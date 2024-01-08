#include "../ft_printf.h"

// Prints a single character to the console

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// Prints a string to the console
// and returns len

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

// Converts an integer to a string, prints the
// string to the console and returns len

int	ft_putnumb(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
