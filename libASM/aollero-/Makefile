#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollero- <aollero@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 18:09:31 by aollero-          #+#    #+#              #
#    Updated: 2020/10/31 14:52:42 by aollero-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libasm.a
SRCS	= srcs/ft_read.s srcs/ft_strcmp.s srcs/ft_strcpy.s srcs/ft_strdup.s	   \
		  srcs/ft_strlen.s srcs/ft_write.s
B_SRC	= bonus/ft_list_push_front.s bonus/ft_list_size.s
FT_SRC	= testsrc/ft_utils.c testsrc/main_ft.c
LC_SRC	= testsrc/ft_utils.c testsrc/main_libc.c
BT_SRC	= testsrc/ft_utils.c testsrc/main_bonus.c
OBJS	= ${SRCS:%.s=%.o}
B_OBJS	= ${B_SRC:%.s=%.o}
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
AS		= nasm
ASFLAGS	= -felf64
AR		= ar
ARFLAGS	= rc
INDEXER	= ranlib
RM		= rm -f
LDLIBS	= -lasm
LDFLAGS	= -L
DCFLAGS = -shared
T_OBJ	= ${FT_SRC:%.c=%.o}
TC_OB	= ${LC_SRC:%.c=%.o}

%.o : %.s
	${AS} ${ASFLAGS} $< -o $@

${NAME} : ${OBJS}
	${AR} ${ARFLAGS} $@ $^
	${INDEXER} ${NAME}

bonus : ${NAME} ${B_OBJS}
	${AR} ${ARFLAGS}s $< ${filter-out $<,$^}

all : ${NAME}

clean :
	${RM} ${OBJS} ${TC_OB} ${T_OBJ} ${B_OBJS} testsrc/main_bonus.o

fclean : clean
	${RM} ${NAME} test testlc libasm.so testbonus

re : fclean all

testlc : ${TC_OB}
	${CC} ${CFLAGS} $^ -o $@
	chmod 755 testlc

test : ${NAME} ${T_OBJ} ${OBJS} testsrc/main.h
	${CC} ${CFLAGS} $^ -o $@ ${LDFLAGS}${<D} ${LDLIBS}
	chmod 755 test

testbonus : bonus ${BT_SRC:%.c=%.o}
	${CC} ${CFLAGS} ${BT_SRC:%.c=%.o} ${NAME} -o $@ ${LDFLAGS}${<D} ${LDLIBS}
	chmod 755 testbonus

libasm.so : ${OBJS}
	${CC} ${DCFLAGS} ${CFLAGS} -o $@ $^

so :
	make libasm.so

help:
	@echo "\e[1mAvailable make\e[0m \e[32mrules\e[0m"
	@echo "\e[32mhelp\e[0m, \e[32mall\e[0m, \e[32mclean\e[0m, \e[32mfclean\e[0m, \e[32mre\e[0m, \e[32mlibasm.a\e[0m, \e[32mlibasm.so\e[0m, \e[32mso\e[0m, \e[32mtest\e[0m, \e[32mrun\e[0m,"
	@echo "\e[32mbonus\e[0m and \e[32mtestbonus\e[0m."

	@echo "\e[32mhelp\e[0m displays this help."
	@echo "\e[32mall\e[0m is the same as \e[32mlibasm.a\e[0m. They build the library that is the object"
	@echo "of the exercise."
	@echo "\e[32mclean\e[0m removes the .o files."
	@echo "\e[32mfclean\e[0m removes the aforementioned library as well as \e[32mclean\e[0m."
	@echo "\e[32mlibasm.so\e[0m is the same as \e[32mso\e[0m and they build the same library only in"
	@echo "shared format."
	@echo "\e[32mtest\e[0m builds two test executables on top of the libasm.a library."
	@echo "The first executable \e[31m./test\e[0m is built on the libasm.a library"
	@echo "and uses the ft_ prefixed functions that are the object of the"
	@echo "exercise."
	@echo "The second executable \e[31m./testlc\e[0m is built on the libc functions"
	@echo "the behaviour of which the libasm functions are expected to reproduce."
	@echo "The test executables \e[31m./test\e[0m and \e[31m./testlc\e[0m should be launched minding the"
	@echo "arguments and their order that will be testing the performance of the"
	@echo "following functions:"
	@echo "    \e[31mft_write\e[0m / \e[31mwrite\e[0m will write \e[36margv[1]\e[0m to the standard output,"
	@echo "    showing	the return value, and errno. To check errno in case of"
	@echo "    error, we should provide some wrong file descriptor into the"
	@echo "    main_ft.c from \e[36m#argv[5]\e[0m. Another choice to see errno would be "
	@echo "    to provide a wrong (for example negative) value as the size to"
	@echo "    write or to read. "
	@echo "    \e[31mft_strcmp\e[0m / \e[31mstrcmp\e[0m will be showed as the alphabetical distance"
	@echo "    between \e[36margv[1]\e[0m and \e[36margv[2]\e[0m."
	@echo "    \e[31mft_strlen\e[0m / \e[31mstrlen\e[0m will be computed on \e[36margv[1]\e[0m."
	@echo "    \e[31mft_strdup\e[0m / \e[31mstrdup\e[0m will show a duplicate of the string in"
	@echo "    \e[36margv[1]\e[0m."
	@echo "    \e[31mft_strcpy\e[0m / \e[31mstrcpy\e[0m will copy \e[36margv[2]\e[0m on top of the last"
	@echo "    duplicated string."
	@echo "    \e[31mft_read\e[0m / \e[31mread \e[0m will attempt to read \e[36m#argv[4]\e[0m chars from the"
	@echo "    file in \e[36margv[3]\e[0m, into the string we just copied with \e[31mft_strcpy\e[0m."
	@echo "    Providing error cases here is easier than for \e[31mft_write\e[0m, since"
	@echo "    a bad file path is easier to produce."
	@echo "An example output for \e[31m./test\e[0m / \e[31m./testlc\e[0m can be launched with the rule"
	@echo "\e[32mrun\e[0m."
	@echo "The rules \e[32mbonus\e[0m and \e[32mtestbonus\e[0m are left to the user to play with."

run : test testlc testbonus
	@echo -e '\e[31m./test "Hello Im argv1" "hello argv2 here" Makefile 200\e[0m'
	@./test "Hello Im argv1" "hello argv2 here" Makefile 200
	@echo -e '\e[31m./testlc "Hello Im argv1" "hello argv2 here" Makefile 200\e[0m'
	@./testlc "Hello Im argv1" "hello argv2 here" Makefile 200
	@echo -e '\e[31m./testbonus "This is the first argument of the list" "This is the second" "This is the third" "all added consecutively to the top, from first to the last"\e[0m'
	@./testbonus "This is the first argument of the list" "This is the second" \
"This is the third" "all added consecutively to the top, from first to the last"
.PHONY: all bonus clean fclean re run so help bonus testbonus
