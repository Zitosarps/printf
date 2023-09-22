#include "main.h"

/**
 * print_character - prints a character
 * @list: list of arguments
 *
 * Return: Always 1
 */
int print_character(va_list list)
{
char c = va_arg(list, int);
return (put_character(c));
}


/**
 * print_string - prints a string
 * @list: list of arguments
 *
 * Return: The number of characters printed.
 */
int print_string(va_list list)
{
char *str = va_arg(list, char *);
int count = 0;
int i;
if (str == NULL)
str = "(null)";


for (i = 0; str[i] != '\0'; i++)
{
count += put_character(str[i]);
}
return (count);
}

/**
 * print_percentage - prints a percent symbol
 * @list: list of arguments
 *
 * Return: 1 (the number of characters printed)
 */

int print_percentage(__attribute__((unused)) va_list list)
{
return (put_character('%'));
}

/**
* _printf - prints output depending on the format passed
* @format: format string
*
* Return: the number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
int chars = 0;
int i;
va_list args;
va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%') {
i++;
switch (format[i])
{
case 'c':
chars += print_character(args);
break;
case 's':
chars += print_string(args);
break;
case '%':
chars += print_percentage(args);
break;
default:
chars += put_character('%');
chars += put_character(format[i]);
break;
}
}
else
{
chars += put_character(format[i]);
}
}
va_end(args);
return (chars);
}
