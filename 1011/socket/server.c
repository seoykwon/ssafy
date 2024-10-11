#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <ctype.h> // For checking numeric inputs

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s [portNUM]\n", argv[0]);
        exit(1);
    }

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    char message[1024];

    // 1. Create server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1)
    {
        perror("Socket creation failed");
        exit(1);
    }

    // 2. Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    // 3. Bind socket to address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Bind failed");
        close(server_sock);
        exit(1);
    }

    // 4. Listen for incoming connections
    if (listen(server_sock, 5) == -1)
    {
        perror("Listen failed");
        close(server_sock);
        exit(1);
    }

    printf("Server is running on port %s...\n", argv[1]);

    // 5. Accept client connection
    client_addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
    if (client_sock == -1)
    {
        perror("Accept failed");
        close(server_sock);
        exit(1);
    }

    // 6. Communication loop (turn-based)
    while (1)
    {
        // Server sends a message
        printf("Server: ");
        fgets(message, sizeof(message), stdin);
        write(client_sock, message, strlen(message));

        // Check if the server wants to exit
        if (strncmp(message, "exit", 4) == 0)
        {
            break;
        }

        // Server receives client's message
        memset(message, 0, sizeof(message));
        read(client_sock, message, sizeof(message) - 1);

        // Check if the client wants to exit
        if (strncmp(message, "exit", 4) == 0)
        {
            printf("Client disconnected.\n");
            break;
        }

        // Process numeric message (multiply by 2 if numeric)
        int is_numeric = 1;
        for (int i = 0; i < strlen(message); i++)
        {
            if (!isdigit(message[i]) && message[i] != '\n')
            {
                is_numeric = 0;
                break;
            }
        }

        if (is_numeric)
        {
            int number = atoi(message);
            printf("Client (numeric): %d -> %d\n", number, number * 2);
        }
        else
        {
            printf("Client: %s", message);
        }
    }

    // 7. Close sockets
    close(client_sock);
    close(server_sock);
    return 0;
}
