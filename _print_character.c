#include <unistd.h>
#include "main.h"

/**
 * _print_character - prints out character(s) to stdout
 * @c: character to print
 *
 * Return: 1 on success else -1
*/

int _print_character(char c)
{
return write(1, &c, 1);
}
