#include "monty.h"

/**
 * check_digit - checks if a string is a digit
 * @arg: string to check
 * Return: 1 if digit, 0 otherwise
 */
int check_digit(char *arg)
{
  int i;

  i = 0;
  if (arg[0] == '-') /* check for negative sign */
    i = 1;
  while (arg[i]) /* loop through each character */
  {
    if (isdigit(arg[i]) == 0) /* check if not a digit */
      return (0);
    i++;
  }
  return (1);
}



/**
 * isnumber - checks if a string is a number
 * @str: provided string
 *
 * Return: 1 if the string is a number, else, 0.
 */
int isnumber(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
		if (i < '0' || i > '9') 
			return (0);

	return (1);
}