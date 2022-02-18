# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 13:07:48 by kmilchev          #+#    #+#              #
#    Updated: 2021/12/06 13:07:48 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = printf.a

CC = gcc

CFLAGS = -Werror -Wextra -Wall

SRCs = ft_printf.c ft_putnbr_fd.c ft_putchar_fd.c \
		ft_test.c ft_print_according_to_type.c ft_putstr_fd.c \
		ft_put_unsigned_nbr_fd.c ft_put_hexa_x_fd.c

OBJs := $(SRCs:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJs)
	ar rcs $(NAME) $(OBJs)

clean: 
	$(RM) $(OBJs)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.out

re: fclean all


