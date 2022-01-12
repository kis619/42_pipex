# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:07:48 by kmilchev          #+#    #+#              #
#    Updated: 2021/11/23 18:07:48 by kmilchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

# CC = gcc

CFLAGS = -Werror -Wextra -Wall

DEPS = libft.h

SRCS = 	ft_memmove.c ft_strjoin.c ft_isalnum.c ft_isdigit.c ft_substr.c ft_memchr.c \
		ft_itoa.c ft_memcmp.c ft_strchr.c ft_strlcat.c ft_calloc.c \
		ft_strtrim.c ft_tolower.c ft_memcpy.c \
		ft_putendl_fd.c ft_strnstr.c ft_toupper.c ft_memset.c \
		ft_strncmp.c ft_striteri.c ft_isprint.c ft_isalpha.c \
		ft_strdup.c ft_bzero.c ft_atoi.c \
		ft_strrchr.c ft_strmapi.c ft_isascii.c ft_strlcpy.c ft_split.c \
		ft_strlen.c new_split.c


SRCs_bonus = 	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
				ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstmap.c \
				ft_lstlast.c ft_lstiter.c

OBJs := $(SRCS:.c=.o)

OBJs_bonus := $(SRCs_bonus:.c=.o)


all: $(NAME) $(DEPS)

$(NAME): $(OBJs)
	ar rcs $(NAME) $(OBJs)

bonus: $(OBJs_bonus)
	ar rcs $(NAME) $(OBJs_bonus)

clean:
	$(RM) $(OBJs)
	$(RM) $(OBJs_bonus)
	$(RM) *.out
	
fclean: clean
	$(RM) $(NAME)

re: fclean all
