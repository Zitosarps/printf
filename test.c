#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    _printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
     _printf("Percent:[%%]\n");
    _printf("Unknown:[%r]\n");
    _printf("Null:[%s]\n", NULL);
    _printf("I am a nullbyte %c", '\0');
    return (0);
}
