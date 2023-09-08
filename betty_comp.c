#include <stdio.h>

/**
 * add - adds two numbers
 * @a: first num
 * @b: second num
 *
 * Return: sum of nums
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 * main - Entry
 *
 * Return: 0 (Success)
 */

int main(void)
{
	int a, b, c;

	a = 10;
	b = 5;

	c = add(10, 5);
	printf("Sum of %d and %d is : %d\n", a, b, c);

	return (0);
}
