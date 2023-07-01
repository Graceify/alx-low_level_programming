#include "main.h"
#include <stdio.h>
#include <stdbool.h>

int _atoi(const char *s);

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int nb;

    nb = _atoi("98");
    printf("%d\n", nb);
    nb = _atoi("-402");
    printf("%d\n", nb);
    nb = _atoi("          ------++++++-----+++++--98");
    printf("%d\n", nb);
    nb = _atoi("214748364");
    printf("%d\n", nb);
    nb = _atoi("0");
    printf("%d\n", nb);
    nb = _atoi("Suite 402");
    printf("%d\n", nb);
    nb = _atoi("         +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA             ");
    printf("%d\n", nb);
    nb = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
    printf("%d\n", nb);
    return 0;
}

int _atoi(const char *s)
{
    int result = 0;
    bool negative = false;

    /* Skip leading whitespace */
    while (*s == ' ')
        s++;

    /* Check for a sign */
    if (*s == '-' || *s == '+') {
        negative = (*s == '-');
        s++;
    }

    /* Process digits */
    while (*s >= '0' && *s <= '9') {
        result = result * 10 + (*s - '0');
        s++;
    }

    /* Apply sign */
    if (negative)
        result = -result;

    return result;
}
