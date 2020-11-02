#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollero- <aollero@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 18:09:31 by aollero-          #+#    #+#              #
#    Updated: 2020/10/13 14:29:30 by aollero-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libft.a
SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
		  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		  ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
		  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_B	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
		  get_next_line.c ft_advalloc.c ft_myalloc.c ft_lstdelmany.c \
		  ft_lsttoarr.c ft_arrtolst.c ft_findptrinarray.c ft_mperror.c \
		  ft_lstcullpattern.c ft_strjoin_ult.c misc.c ft_isspace.c \
		  ft_arrkey2.c ft_arrkey.c ft_arrbyte.c mlx_protect.c ft_array.c \
		  ft_isspace_adv.c ft_algebra.c
TEST	= test
TEST_B	= test_bonus
INCS	= libft.h advice.h ft_lstdelmany.h ft_arrkey.h
SRC_T	= main.c
SRC_TB	= bonus_main.c
OBJ_T	= ${SRC_T:%.c=%.o}
OBJ_TB	= ${SRC_TB:%.c=%.o}
OBJS	= ${SRCS:%.c=%.o}
OBJS_B	= ${SRC_B:%.c=%.o}
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
AR		= ar
ARFLAGS	= rc
INDEXER	= ranlib
RM		= rm -f
LDLIBS	= -lft
LDFLAGS	= -L
DCFLAGS = shared

%.o : %.c
	${CC} -c ${CFLAGS} $< -o $@

${NAME} : ${OBJS} ${INCS}
	${AR} ${ARFLAGS} $@ $^
	${INDEXER} ${NAME}

all : ${NAME}

clean :
	${RM} ${OBJS} ${OBJS_B} ${OBJ_T} ${OBJ_TB}

fclean : clean
	${RM} ${NAME} ${TEST} ${TEST_B}

re : fclean all

bonus : ${NAME} ${OBJS_B}
	${AR} ${ARFLAGS}s $< ${filter-out $<,$^}

${TEST} : ${NAME} ${OBJ_T}
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}${<D} ${LDLIBS}

${TEST_B} : ${NAME} ${OBJ_TB} ${OBJS_B}
	make bonus
	${CC} ${CFLAGS} ${filter-out ${OBJS_B}, $^} -o $@ ${LDFLAGS}${<D} ${LDLIBS}

libft.so : ${OBJS}
	${CC} ${DCFLAGS} ${CFLAGS} -o libft.so $^

so :
	make libft.so

run :
	./run.sh --no-make --no-valgrind #--no-bonus

.PHONY: all bonus clean fclean re run so
