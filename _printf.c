#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints output depending on the forat passwed
 * @format: data type to be printed
 *
 * Return: the number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char char_arg = (char) va_arg(args, int);
count += _print_character(char_arg);
}
else if (*format == 's')
{
char *str_arg = va_arg(args, char *);
while (*str_arg != '\0')
{
count += _print_character(*str_arg);
str_arg++;
}
}
else if (*format == '%')
{
count += _print_character('%');
}
else
{
count += _print_character(*format);
}
}
else
{
count += _print_character(*format);
}
format++;
}
va_end(args);
return (count);
}
