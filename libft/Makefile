# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 23:23:47 by qle-bevi          #+#    #+#              #
#    Updated: 2017/05/03 23:17:15 by bdesbos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = .

OBJ_PATH = obj

HEAD = includes/libft.h

SRC_NAME = ft_atoi.c ft_bzero.c ft_countwords.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isescaped.c ft_isprint.c ft_itoa.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_pow.c ft_pushchar.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strrejoin.c \
ft_strlcat.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_getdecade.c ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstpush.c ft_lstmap.c \
ft_lstsort.c ft_lstsize.c ft_lstrev.c ft_lstselect.c ft_lstgot.c ft_errexit.c \
ft_lstpop.c ft_freetab.c ft_strsplitif.c ft_putstr_color.c ft_free_tab.c \
ft_strlen.c ft_tablen.c  ft_putwchar.c ft_putwstr.c ft_jointab.c ft_strredup.c \
ft_puttab.c ft_str_replace.c ft_rfreetab.c\

INCL = -I ./includes/

CC = clang

FLAGS = -Wall -Werror -Wextra -O2 -g

OBJ_NAME = $(SRC_NAME:%.c=%.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: title $(NAME)

title:
	@echo "Checking libft..."

$(NAME): $(OBJ)
	@ar rc $@ $^
	@echo "Indexing..."
	@ranlib $(NAME)
	@echo "\n✅  LIBFT BUILT !\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEAD)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INCL) -o $@ -c $<
	@echo "libft => \033[33;32m$@\033[33;0m"

clean :
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "libft cleaned"

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re title
