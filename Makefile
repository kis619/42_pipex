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

SRCs = main.c pipex_utils.c

OBJs := $(SRCs:.c=.o)

LIBPATH = ./libft

LIBRARY = libft.a

PRINTPATH = ./printf

FT_PRINTF = printf.a

all:  $(LIBRARY) $(FT_PRINTF) $(NAME) 

$(FT_PRINTF):
	$(MAKE) -C $(PRINTPATH)

$(LIBRARY):
	$(MAKE) -C $(LIBPATH)  

$(NAME): $(OBJs)
	$(CC) $(Flags) $(SRCs) -o $(NAME) $(LIBPATH)/$(LIBRARY) $(PRINTPATH)/$(FT_PRINTF)

clean:
	$(RM) $(OBJs)


fclean: clean
	$(MAKE) fclean -C $(LIBPATH)
	$(MAKE) fclean -C $(PRINTPATH)
	$(RM) $(NAME)

re: fclean all