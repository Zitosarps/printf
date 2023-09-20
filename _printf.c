#include "main.h"

/**
 * print_normal_character - prints a normal character
 * @c: character to print
 *
 * Return: the number of characters printed (always 1)
 */
static int print_normal_character(char c)
{
_print_character(c);
return (1);
}

/**
 * print_percent - prints a percent character
 *
 * Return: the number of characters printed (always 1)
 */
static int print_percent(void)
{
_print_character('%');
return (1);
}

/**
 * print_char - prints a character
 * @args: va_list containing the character to print
 *
 * Return: the number of characters printed (always 1)
 */
static int print_char(va_list args)
{
char c = (char) va_arg(args, int);
_print_character(c);
return (1);
}

/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: the number of characters printed (excluding null byte)
 */
static int print_string(va_list args)
{
char *str = va_arg(args, char *);
int count = 0;

if (str == NULL)
str = "(null)";

while (*str)
{
_print_character(*str);
count++;
str++;
}

return (count);
}

/**
 * print_unknown - prints an unknown format specifier
 * @format: the format specifier
 *
 * Return: the number of characters printed (always 2)
 */
static int print_unknown(char format)
{
_print_character('%');
_print_character(format);
return (2);
}

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
return (-1);

va_start(args, format);

while (*format)
{
if (*format != '%')
count += print_normal_character(*format);
else if (*(++format) == '\0')
break;
else if (*format == '%')
count += print_percent();
else if (*format == 'c')
count += print_char(args);
else if (*format == 's')
count += print_string(args);
else
count += print_unknown(*format);

format++;
}

va_end(args);
return (count);
}


