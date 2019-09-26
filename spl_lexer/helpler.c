//
// Created by 10578 on 9/27/2019.
//

#include "helpler.h"


char *strupr(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}

int strequal(char *s1, char *s2) {
    return strcmp(s1, s2) == 0;
}