//
// Created by 10578 on 9/27/2019.
//

#include "helpler.h"

using namespace std;

char *strupr(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}