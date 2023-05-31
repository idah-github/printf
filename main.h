#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#define S_LONG 2
#define S_SHORT 1

#define F_MINUS 1
#define F_ZERO 4
#define F_PLUS 2
#define F_SPACE 16
#define F_HASH 8
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
*typedef struct fm fm_t - op struct def
*@fm: the format
*@fm_t: associated function
*
*
*typedef struct fm fm_t;
*/

int _printf(const char *format, ...);
int print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

int flags(const char *format, int *i);
int width(const char *format, int *i, va_list list);
int precision(const char *format, int *i, va_list list);
int size(const char *format, int *i);

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

#endif
