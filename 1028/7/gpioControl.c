#include <stdio.h>
#include <stdint.h>
int main()
{

    uint32_t GPIO2_CTRL = 0x000FFFFF;
    uint32_t GPIO2_STATUS = 0xFF7FFFFF;
    uint32_t GPIO20_CTRL = 0xFFFF0FFF;
    uint32_t PADBANK0_GPIO20 = 0x00FFFF00;
    uint32_t PADBANK0_GPIO2 = 0xFF00FF00;

    uint32_t INOVER;
    uint32_t FUNCSEL;
    uint32_t EVENT_LEVEL_HIGH;
    uint32_t OEOVER;
    uint32_t OUTOVER;
    uint32_t DRIVE;
    uint32_t IE;

    INOVER = (GPIO2_CTRL >> 16) & 0b11;
    GPIO2_CTRL = GPIO2_CTRL & ~(0b11 << 16);

    FUNCSEL = GPIO2_CTRL & 0b11111;
    GPIO2_CTRL = GPIO2_CTRL & ~(0b11111);

    GPIO2_CTRL = GPIO2_CTRL | 0x7;

    EVENT_LEVEL_HIGH = (GPIO2_STATUS >> 23) & 0b1;

    OEOVER = (GPIO20_CTRL >> 14) & 0b11;
    GPIO20_CTRL = GPIO20_CTRL & ~(0b11 << 14);
    GPIO20_CTRL = GPIO2_CTRL | (0x3 << 14);

    OUTOVER = (GPIO20_CTRL >> 12) & 0b11;
    GPIO20_CTRL = GPIO20_CTRL & ~(0b11 << 12);
    GPIO20_CTRL = GPIO20_CTRL | (0x2 << 12);

    DRIVE = (PADBANK0_GPIO20 >> 4) & 0b11;
    PADBANK0_GPIO20 = PADBANK0_GPIO20 & ~(0b11 << 4);
    PADBANK0_GPIO20 = PADBANK0_GPIO20 | (0x1 << 4);

    IE = (PADBANK0_GPIO2 >> 6) & 0b1;
    PADBANK0_GPIO2 = PADBANK0_GPIO2 & ~(0b1 << 6);
    PADBANK0_GPIO2 = PADBANK0_GPIO2 | (0x1 << 6);

    return 0;
}
