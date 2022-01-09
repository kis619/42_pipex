# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 15:53:25 by kmilchev          #+#    #+#              #
#    Updated: 2022/01/04 15:53:25 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

Flags = -Wall -Werror -Wextra

SRCs = main.c

OBJs := $(SRCs:.c=.o)

LIBPATH = ./libft

LIBRARY = libft.a

all:  $(LIBRARY) $(NAME)

$(LIBRARY):
	$(MAKE) -C $(LIBPATH)  

$(NAME): $(OBJs)
	$(CC) $(Flags) $(SRCs) -o pipex ./libft/libft.a

clean:
	$(RM) $(OBJs)


fclean: clean
	$(MAKE) fclean -C $(LIBPATH)
	$(RM) $(NAME)

re: fclean all