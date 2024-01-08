#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnumb(int n);

int	ft_putuns(unsigned int n);

int	ft_putptr(void *ptr);
int	ft_puthex(unsigned int num, const char type);

#endif