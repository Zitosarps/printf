#include <unistd.h>
#include "main.h"

/**
 * put_character - prints out character(s) to stdout
 * @c: character to print
 *
 * Return: 1 on success else -1
 */
int put_character(char c)
{
return (write(1, &c, 1));
}
