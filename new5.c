#include "main.h"

/**
 * mem_init - fills memory with byte
 * @st: the pointer
 * @ba: the byte
 * @n: the amount of bytes
 * Return: st
 */
char *mem_init(char *st, char ba, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = ba;
	return (st);
}

/**
 * custom_start - checks if n starts with h
 * @h: string
 * @n: the other string
 * Return: address
 */
char *custom_start(const char *h, const char *n)
{
	while (*n)
		if (*n++ != *h++)
			return (NULL);
	return ((char *)h);
}

/**
 * conv_num - function, similar to itoa.
 * @number: The number to be converted.
 * @base: The base for the conversion.
 * @formatFlags: Formatting flags.
 *
 * Return: A string representing the converted number.
 */
char *conv_num(long int number, int base, int formatFlags)
{
    static char *conversionArray;
    static char conversionBuffer[50];
    char sign = 0;
    char *resultPointer;
    unsigned long n = number;

    if (!(formatFlags & CUSTOM_UNSIGNED) && number < 0)
    {
        n = -number;
        sign = '-';
    }

    conversionArray = formatFlags & CUSTOM_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
    resultPointer = &conversionBuffer[49];
    *resultPointer = '\0';

    do {
        *--resultPointer = conversionArray[n % base];
        n /= base;
    } while (n != 0);

    if (sign)
        *--resultPointer = sign;
    return (resultPointer);
}
