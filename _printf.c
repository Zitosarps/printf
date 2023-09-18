#include "main.h"

/**
 * _printf - prints output depending on the format passed
 * @format: format string
 *
 * Return: the number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;

if (format == NULL)
{
return (-1);
}

va_start(args, format);

while (*format)
{
if (*format != '%')
{
_print_character(*format);
count++;
}
else
{
format++;
if (*format == '\0')
break;

if (*format == '%')
{
_print_character('%');
count++;
}
else if (*format == 'c')
{
char c = (char) va_arg(args, int);
_print_character(c);
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";

while (*str)
{
_print_character(*str);
count++;
str++;
}
}
}
format++;
}

va_end(args);
return (count);
}
