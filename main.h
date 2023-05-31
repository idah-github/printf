#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/**
*struct fm - op struct
*@fmt: the format
*@fun: associated function
*
*/

struct fm
{
	char fmt;
	int (*fun)(va_list, char[], int, int, int, int);
} fm_t

/**
*struct fm fm_t - op struct def
*@fm: the format
*@fm_t: associated function
*
*typedef struct fm fm_t;
*/
int _printf(const char *format, ...);
/*
*int print(const char *fmt, int *i,
*va_list list, char buffer[], int flags, int width, int precision, int size);
*/

#endif
