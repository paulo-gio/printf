NAME		= libftprintf.a
LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft
SRC			= ./c_files
PRINTF_SRCS	= ft_printf.c ft_printf_hexptr.c ft_printf_unsigned.c ft_printf_utils.c
OBJS		= $(PRINTF_SRCS:%.c=%.o)

CC			= cc
AR			= ar rcs
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFT) $@
	$(AR) $@ $^

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re