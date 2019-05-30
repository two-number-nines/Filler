# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vmulder <vmulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:18:40 by vmulder        #+#    #+#                 #
#    Updated: 2019/05/30 14:58:51 by vmulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

## EXECUTABLE ##
NAME = libft.a

## INCLUDES ##
SRC_PATH = srcs
HEADER = ./incl/

## SOURCES ##
SOURCES = ft_printf.c checkflags.c checkwidth.c checkpresicion.c checklengmodif.c \
			checkspecifier.c converter_csp.c utils_csp.c converter_di.c \
			utils_di.c utils_main.c converter_uox.c utils_uox.c utils_f.c \
			converter_f.c whileloops.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
			ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
			ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c ft_getdigits.c \
			ft_skipwhite.c ft_strrev.c ft_islower.c ft_isupper.c \
			ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
			ft_lstmap.c ft_atoi_base.c ft_itoa_base_u.c ft_itoa_base.c \
			ft_getdigits_u.c get_next_line.c ft_strnsplit.c

## OBJECTS ##
SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(SOURCES:.c=.o)

## COMPILATION ##
CC = gcc
FLAGS = -Wall -Werror -Wextra -c -g

## RULES ##
all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJS)
	@echo "libft compiled"

clean:
	@echo "Cleaning libft..."
	@rm -rf *.o

fclean:
	@echo "Fcleaning libft..."
	@rm -rf *.o
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean
