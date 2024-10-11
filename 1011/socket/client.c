#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s [serverIP] [portNUM]\n", argv[0]);
        exit(1);
    }

    int client_sock;
    struct sockaddr_in server_addr;
    char message[1024];

    // 1. Create client socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1)
    {
        perror("Socket creation failed");
        exit(1);
    }

    // 2. Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // 3. Connect to server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Connection failed");
        close(client_sock);
        exit(1);
    }

    printf("Connected to server...\n");

    // 4. Communication loop (turn-based)
    while (1)
    {
        // Client receives a message from the server
        memset(message, 0, sizeof(message));
        read(client_sock, message, sizeof(message) - 1);

        // Check if the server wants to exit
        if (strncmp(message, "exit", 4) == 0)
        {
            printf("Server disconnected.\n");
            break;
        }

        printf("Server: %s", message);

        // Client sends a message
        printf("Client: ");
        fgets(message, sizeof(message), stdin);
        write(client_sock, message, strlen(message));

        // Check if the client wants to exit
        if (strncmp(message, "exit", 4) == 0)
        {
            break;
        }
    }

    // 5. Close socket
    close(client_sock);
    return 0;
}
