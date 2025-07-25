#include "control_flags.h"

int flag_toggle(int flag) {
    return !flag;
}

int is_active(int status) {
    return status & 0x01;
}