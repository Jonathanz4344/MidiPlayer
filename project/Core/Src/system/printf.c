#include "printf.h"
#include "UART.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

static char buffer[128];

static void print_string (const char* string, int len) {
    USART_Write (USART2, (unsigned char*) string, len);
}

int puts (const char* string){
    int len = strlen (string);
    print_string (string, len);
    print_string ("\n", 1);
    return len;
}

int putchar (int chr){
    print_string ((char*)&chr, 1);
    return chr;
}

int printf (const char* format, ...) {
    va_list aptr;
    int ret;

    va_start(aptr, format);
    ret = vsprintf(buffer, format, aptr);
    va_end(aptr);
    print_string (buffer, ret);

    return(ret);
}


