#include <stdio.h>
#include <stdint.h>

// Define a structure with bitfields
typedef struct
{
    uint8_t a : 2; // 2 bits for 'a' (1:0)
    uint8_t b : 2; // 2 bits for 'b' (3:2)
    uint8_t c : 2; // 2 bits for 'c' (5:4)
    uint8_t d : 2; // 2 bits for 'd' (7:6)
} Bitfield;

int main()
{
    // Create a variable of the bitfield structure
    Bitfield bitfield;

    // Assign values as per the slide's instructions
    bitfield.a = 0x1; // a [1:0] = 0x1
    bitfield.b = 0x0; // b [3:2] = 0x0
    bitfield.c = 0x2; // c [5:4] = 0x2
    bitfield.d = 0x3; // d [7:6] = 0x3

    // Print the values to verify
    printf("a: %u\n", bitfield.a);
    printf("b: %u\n", bitfield.b);
    printf("c: %u\n", bitfield.c);
    printf("d: %u\n", bitfield.d);

    // Output the entire byte (raw data)
    uint8_t *raw_data = (uint8_t *)&bitfield;
    printf("Raw byte: 0x%02X\n", *raw_data);

    return 0;
}
