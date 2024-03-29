#include "main.h"

/**
 * rev_string - Reverses an array.
 * @str: Pointer to the string to be reversed.
 */

void rev_string(char *str)
{
    int length = 0;
    int i = 0;
    char temp;

    while (*(str + length) != '\0')
    {
        length++;
    }
    length--;

    for (i = 0; i < length; i++, length--)
    {
        temp = *(str + i);
        *(str + i) = *(str + length);
        *(str + length) = temp;
    }
}

/**
 * infinite_add - Adds two numbers together.
 * @n1: Text representation of the first number to add.
 * @n2: Text representation of the second number to add.
 * @r: Pointer to the buffer where the result is stored.
 * @size_r: Size of the buffer.
 * Return: Pointer to the calling function.
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int overflow = 0, i = 0, j = 0, digits = 0;
    int val1 = 0, val2 = 0, temp_tot = 0;

    while (*(n1 + i) != '\0')
        i++;
    while (*(n2 + j) != '\0')
        j++;
    i--;
    j--;
    if (j >= size_r || i >= size_r)
        return (0);
    while (j >= 0 || i >= 0 || overflow == 1)
    {
        if (i < 0)
            val1 = 0;
        else
            val1 = *(n1 + i) - '0';
        if (j < 0)
            val2 = 0;
        else
            val2 = *(n2 + j) - '0';
        temp_tot = val1 + val2 + overflow;
        if (temp_tot >= 10)
            overflow = 1;
        else
            overflow = 0;
        if (digits >= (size_r - 1))
            return (0);
        *(r + digits) = (temp_tot % 10) + '0';
        digits++;
        j--;
        i--;
    }
    if (digits == size_r)
        return (0);
    *(r + digits) = '\0';
    rev_string(r);
    return (r);
}
