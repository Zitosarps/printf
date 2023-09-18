#include "main.h"
/**
 * _printf.c:99: ERROR: parentheses are required on a return statement
total: 1 errors, 0 warnings, 100 lines checked
print_normal_character
print_percent
_printf.c:32: warning: No description found for parameter or member 'args'
_printf.c:33: warning: Excess function parameter 'c' description in 'print_char'
print_char
print_string
_printf
*/

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
 * @args: character to print
 *
 * Return: the number of characters printed (always 1)
 */
static int print_char(va_list args)
{
char c = (char)va_arg(args, int);
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
count += print_normal_character(*format);
else if (*(++format) == '\0')
break;
else if (*format == '%')
count += print_percent();
else if (*format == 'c')
count += print_char(args);
else if (*format == 's')
count += print_string(args);

format++;
}

va_end(args);
return (count);
}
