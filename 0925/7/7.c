#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    // Open the binary file for reading
    FILE *file = fopen("binary", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Buffer to hold the binary data (14 bytes as per the structure)
    uint8_t buffer[14];

    // Read 14 bytes from the binary file
    size_t bytesRead = fread(buffer, sizeof(uint8_t), 14, file);
    if (bytesRead != 14) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    // Close the file after reading
    fclose(file);

    // Parse and display weight (at base address 0x00)
    uint16_t weight = buffer[0] | (buffer[1] << 8); // Combine Little Endian bytes
    printf("Weight: %u KG\n", weight);

    // Parse and display Account Password (at offset 0x00 of Unique ID)
    uint16_t account_password = buffer[2] | (buffer[3] << 8); // Little Endian
    printf("Account Password: %u\n", account_password);

    // Parse and display Expected Salary (at offset 0x02 of Unique ID)
    uint16_t expected_salary = buffer[4] | (buffer[5] << 8); // Little Endian
    printf("Expected Salary: %u\n", expected_salary);

    // Parse and display Favorite Food (ASCII string starting at offset 0x04)
    printf("Favorite Food: %c%c%c%c\n", buffer[6], buffer[7], buffer[8], buffer[9]);

    // Parse and display Favorite Drink (ASCII string starting at offset 0x08)
    printf("Favorite Drink: %c%c%c%c\n", buffer[10], buffer[11], buffer[12], buffer[13]);

    return 0;
}

