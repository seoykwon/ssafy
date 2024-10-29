#include <stdio.h>
#include <stdint.h>

int main()
{

    uint32_t *IOBANK0 = 0x400d0000;
    uint32_t *PADBANK0 = 0x400f0000;

    uint32_t *GPIO2_CTRL;
    uint32_t *GPIO2_STATUS;
    uint32_t *GPIO20_CTRL;
    uint32_t *PADBANK0_GPIO2;
    uint32_t *PADBANK0_GPIO20;

    /*
    Base Address + OFFSET을 하는 과정에서
    OFFSET이 0x10인 경우 0x10이 더해진 Address가 아닌
    0x40이 더해진 Address가 나오는 것을 확인할 수 있다.

    이는 C언어에서 Pointer에 "+"연산을 하는 방식에서 기인된 문제라고 볼 수 있다.

    uint32_t type의 Pointer에서 "+"연산을 진행하기 때문에 데이터의 크기인 32Bits = 4Bytes가 기준이 된다.
    그래서 0x01(1)을 더하는 경우 주소기준으로 0x04(4)가 더해진다.

    그래서 0x14(20)을 더하는 경우, 주소기준으로 0x50(80)이 더해지게 되는 것이다.
    그래서 실제 OFFSET을 적용하고 싶은 경우에는 지정한 Type을 고려해야 한다.

    그래서 4로 나눠서 OFFSET 설정을 진행한다.
     */

    GPIO2_CTRL = IOBANK0 + 0x014 / 4;
    GPIO2_STATUS = IOBANK0 + 0x010 / 4;
    GPIO20_CTRL = IOBANK0 + 0x0a4 / 4;

    PADBANK0_GPIO2 = PADBANK0 + 0x0c / 4;
    PADBANK0_GPIO20 = PADBANK0 + 0x54 / 4;
    return 0;
}
