#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollero- <aollero@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/18 15:35:39 by aollero-          #+#    #+#              #
#    Updated: 2020/08/05 19:15:32 by aollero-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
SRCS = src/ft_printf.c src/misc.c src/misc2.c src/ft_unsigned.c \
		src/lst_rm.c src/lst_alloc.c src/parse_plholder.c \
		src/parse_fstr.c src/out_format0.c src/out_format1.c \
		src/out_format2.c src/out_cat.c
LIBOBJS = libft/ft_atoi.o libft/ft_bzero.o libft/ft_calloc.o \
		libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o \
		libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o \
		libft/ft_memccpy.o libft/ft_memchr.o libft/ft_memcmp.o \
		libft/ft_memcpy.o libft/ft_memmove.o libft/ft_memset.o libft/ft_split.o\
		libft/ft_strchr.o libft/ft_strdup.o libft/ft_strjoin.o \
		libft/ft_strlcat.o libft/ft_strlcpy.o libft/ft_strlen.o \
		libft/ft_strmapi.o libft/ft_strncmp.o libft/ft_strnstr.o \
		libft/ft_strrchr.o libft/ft_strtrim.o libft/ft_substr.o \
		libft/ft_tolower.o libft/ft_toupper.o libft/ft_putchar_fd.o \
		libft/ft_putstr_fd.o libft/ft_putendl_fd.o libft/ft_putnbr_fd.o \
		libft/ft_lstadd_back.o libft/ft_lstadd_front.o libft/ft_lstclear.o \
		libft/ft_lstdelone.o libft/ft_lstiter.o libft/ft_lstlast.o \
		libft/ft_lstmap.o libft/ft_lstnew.o libft/ft_lstsize.o
IDIR = incs/
OBJS = $(SRCS:%.c=%.o)
CFLAGS = -O3 -Wall -Werror -Wextra
RM = rm -f
LDIR = libft/
LIB = libft.a
TEST = test
$(CC) = gcc

$(NAME) : $(OBJS) $(LIBOBJS)
	ar rcs $@ $^

$(LIBOBJS) :
	make -C $(LDIR) bonus

%.o : %.c
	${CC} -c ${CFLAGS} $< -o $@

$(TEST) : $(OBJS) $(LIB) $(INCS)
	gcc -I$(IDIR) $^ -lft -L. -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS) $(LIBOBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(TEST)
	$(RM) $(LDIR)$(LIB)

re : fclean all

.PHONY : fclean clean re all
