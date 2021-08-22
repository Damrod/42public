SRCS	=   philo_death.c philo_death2.c ft_strtol.c utils.c \
			philo_init2.c philo_entry.c my_errno.c input_getters.c \
			input_time.c input_setters.c philo_fork.c philo_init.c
INCS	=   incs/utils.h incs/input_getters.h incs/philo.h \
			incs/input_setters.h incs/input_private.h incs/philo_entry.h \
			incs/my_errno.h incs/philo_init.h incs/philo_fork.h \
			incs/philo_dead.h
OBJFOLDER	= objs
OBJSDBG		= objdbg
SRCSFOLDER	= srcs
INCSFOLDER	= incs
VPATH		= $(OBJFOLDER) $(SRCSFOLDER) ${INCSFOLDER} $(OBJSDBG)
OBJS		= $(SRCS:%.c=$(OBJFOLDER)/%.o)
OBJDBG		= $(SRCS:%.c=$(OBJSDBG)/%.o)
NAME		= philo
NAMEDBG		= philodbg
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g

$(NAME) : $(OBJS)
	$(CC) -I ${INCSFOLDER} $(CFLAGS) $(OBJS) -o $@ -lpthread

all : $(NAME)

dbg : $(NAMEDBG)

$(NAMEDBG) : $(OBJDBG)
	$(CC) -I ${INCSFOLDER} $(CFLAGS) $(OBJDBG) -o $@ -lpthread

$(OBJSDBG)/%.o : %.c
	@if [ ! -d objdbg ] ; then \
		mkdir objdbg ; fi
	$(CC) $(CFLAGS) -D DBG -c $? -I ${INCSFOLDER} -o $@

$(OBJFOLDER)/%.o: %.c
	@if [ ! -d objs ] ; then \
		mkdir objs ; fi
	$(CC) $(CFLAGS) -c $? -I ${INCSFOLDER} -o $@

test : ${TESTFILE} ${NAME}
	@./${NAME}

clean :
	@echo "rm $(OBJS)" ; \
	for file in $(OBJS) ; do \
		if [[ -f $$file ]] ; then \
			rm $(OBJS) ; \
		fi ; \
	done 2> /dev/null ;\
	if [ -f ${TEST_DEST} ] ; then \
		rm ${TEST_DEST} ; \
	fi 2> /dev/null ; \
	rm -rf objs
	rm -rf objdbg

fclean : clean
	@echo "rm $(NAME)"
	@if [ -f $(NAME) ] ; then \
	rm $(NAME); \
	fi 2> /dev/null; \
	if [ -f $(NAMEDBG) ] ; then \
	rm $(NAMEDBG); \
	fi 2> /dev/null

re : fclean all

.PHONY: re clean fclean all test dbg
