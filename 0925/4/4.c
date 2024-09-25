#include <stdio.h>
#include <stdint.h>

// Define a structure for the data protocol
typedef struct
{
    uint8_t header[5]; // 5 bytes for the header
    uint8_t body[4];   // 4 bytes for the body
    uint8_t tail[2];   // 2 bytes for the tail
} DataProtocol;

// Optionally using union to represent the entire data in one go (optional)
typedef union
{
    uint8_t raw_data[11]; // Full data as raw bytes
    DataProtocol parsed;  // Parsed data as header, body, and tail
} DataUnion;

int main()
{
    // Initialize the data array
    DataUnion data = {.raw_data = {0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef, 0x98, 0x76, 0x54}};

    // Print Header (5 bytes)
    printf("Header: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%02X ", data.parsed.header[i]);
    }
    printf("\n");

    // Print Body (4 bytes)
    printf("Body: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%02X ", data.parsed.body[i]);
    }
    printf("\n");

    // Print Tail (2 bytes)
    printf("Tail: ");
    for (int i = 0; i < 2; i++)
    {
        printf("%02X ", data.parsed.tail[i]);
    }
    printf("\n");

    return 0;
}
