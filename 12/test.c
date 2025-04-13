#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "IfxCan_regdef.h"
#include "IfxCan_reg.h"

Ifx_CAN dummy;

#undef MODULE_CAN
#define MODULE_CAN (*(Ifx_CAN*)&dummy)

int main(void) {

    return 0;
}