/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:24:19 by pgiovann          #+#    #+#             */
/*   Updated: 2024/01/08 15:01:52 by pgiovann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Converts unsigned integer to hexadecimal string,

static void	ft_num_to_hex(unsigned int num, const char type, char *hex)
{
	int				i;
	unsigned int	digit;

	i = 0;
	if (num == 0)
		hex[i++] = '0';
	while (num != 0)
	{
		digit = num % 16;
		if (digit < 10)
			hex[i++] = digit + '0';
		else
		{
			if (type == 'x')
				hex[i++] = 'a' + digit - 10;
			else if (type == 'X')
				hex[i++] = 'A' + digit - 10;
		}
		num /= 16;
	}
	hex[i] = '\0';
}

// Prints the hex string

int	ft_puthex(unsigned int num, const char type)
{
	char	hex[9];
	int		len;

	ft_num_to_hex(num, type, hex);
	len = ft_strlen(hex);
	while (len > 0)
		ft_putchar(hex[--len]);
	return (ft_strlen(hex));
}

// Prints hexadecimal digits iteratively

static int	ft_put_hex_iter(unsigned long long prt)
{
	int					i;
	int					len;
	unsigned long long	digit;
	char				hex[16];

	i = 0;
	if (prt == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (prt != 0)
	{
		digit = prt % 16;
		if (digit < 10)
			hex[i++] = digit + '0';
		else
			hex[i++] = digit - 10 + 'a';
		prt /= 16;
	}
	len = i;
	while (i > 0)
		ft_putchar(hex[--i]);
	return (len);
}

// Prints the hex representation of a pointer to stdout

int	ft_putptr(void *ptr)
{
	unsigned long long	prt;
	int					len;

	prt = (unsigned long long)ptr;
	if (!ptr)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	len = write(1, "0x", 2);
	len += ft_put_hex_iter(prt);
	return (len);
}
