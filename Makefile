#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiovann <pgiovann@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:25:11 by pgiovann          #+#    #+#              #
#    Updated: 2024/01/09 01:46:16 by pgiovann         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libftprintf.a
LIBFT		= ./libft/libft.a
LIBFTDIR	= ./libft
SRC			= ./source
PRINTF_SRCS	= ft_printf.c ft_printf_hexptr.c ft_printf_uns.c ft_printf_utils.c
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