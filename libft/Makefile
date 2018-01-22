# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 20:42:11 by cmiran            #+#    #+#              #
#    Updated: 2018/01/22 18:01:22 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_atoi.c\
      ft_bzero.c\
      ft_freentab.c\
      ft_freetab.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isblank.c\
      ft_iscntrl.c\
      ft_isdigit.c\
      ft_isgraph.c\
      ft_islower.c\
      ft_islowhexa.c\
      ft_isprint.c\
      ft_isspace.c\
      ft_isupper.c\
      ft_isupphexa.c\
      ft_isxdigit.c\
      ft_itoa.c\
      ft_lstadd.c\
      ft_lstdel.c\
      ft_lstdelone.c\
      ft_lstiter.c\
      ft_lstmap.c\
      ft_lstnew.c\
      ft_memalloc.c\
      ft_memccpy.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memdel.c\
      ft_memmove.c\
      ft_memset.c\
      ft_print_memory.c\
      ft_putchar.c\
      ft_putchar_fd.c\
      ft_putendl.c\
      ft_putendl_fd.c\
      ft_putnbr.c\
      ft_putnbr_fd.c\
      ft_putstr.c\
      ft_putstr_fd.c\
      ft_puttab.c\
      ft_puttab_fd.c\
      ft_str_is_alpha.c\
      ft_str_is_lowercase.c\
      ft_str_is_numeric.c\
      ft_str_is_printable.c\
      ft_str_is_uppercase.c\
      ft_strcapitalize.c\
      ft_strcasecmp.c\
      ft_strcasestr.c\
      ft_strcat.c\
      ft_strchr.c\
      ft_strcjoin.c\
      ft_strclen.c\
      ft_strclr.c\
      ft_strcmp.c\
      ft_strcnew.c\
      ft_strcpy.c\
      ft_strdel.c\
      ft_strdup.c\
      ft_strequ.c\
      ft_striter.c\
      ft_striteri.c\
      ft_strjoin.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strlowcase.c\
      ft_strmap.c\
      ft_strmapi.c\
      ft_strncasecmp.c\
      ft_strncat.c\
      ft_strncmp.c\
      ft_strncpy.c\
      ft_strndup.c\
      ft_strnequ.c\
      ft_strnew.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_strsplit.c\
      ft_strstr.c\
      ft_strsub.c\
      ft_strtrim.c\
      ft_strupcase.c\
      ft_tolower.c\
      ft_toupper.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@gcc -c $(CFLAGS) $(SRC)
	@ar rc $@ $^
	@ranlib $@

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
