/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:24:26 by pgiovann          #+#    #+#             */
/*   Updated: 2024/01/09 01:36:40 by pgiovann         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ft_printf.h"

// Returns the number of digits required to represent an unsigned integer

static int	ft_length_num(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

// Converts an unsigned integer to a string

static char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_length_num(n);
	num = malloc(len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (len > 0)
	{
		num[--len] = n % 10 + '0';
		n /= 10;
	}
	return (num);
}

// Prints an unsigned integer to the console
// and returns the number of characters printed

int	ft_putuns(unsigned int n)
{
	char	*num;
	int		len;

	num = ft_utoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}
