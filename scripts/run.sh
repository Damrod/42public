#!/bin/sh
VLG_MAIN="no"
VALGRIND="yes"
MAKE="yes"
TEST="yes"
RMTESTFILE="yes"
BONUS="yes"
until [ -z "$1" ]
do
	if [ $1 = "--valgrind-main" ]
	then
		VLG_MAIN="yes"
	fi
	if [ $1 = "--no-valgrind" ]
	then
		VALGRIND="no"
	fi
	if [ $1 = "--no-make" ]
	then
		MAKE="no"
	fi
	if [ $1 = "--no-test" ]
	then
		TEST="no"
	fi
	if [ $1 = "--no-rmtest" ]
	then
		RMTESTFILE="no"
	fi
	if [ $1 = "--no-bonus" ]
	then
		BONUS="no"
	fi
	shift
done
if [ ${MAKE} = "yes" ]
then
	printf "\n**** make all ****\n\n"
	make all
	printf "\n**** make re ****\n\n"
	make re
	printf "\n**** make fclean ****\n\n"
	make fclean
	printf "\n**** make libft.a ****\n\n"
	make libft.a
	printf "\n**** make clean ****\n\n"
	make clean
	printf "\n**** ls ****\n\n"
	ls
	printf "\n**** make fclean ****\n\n"
	make fclean
	printf "\n**** make ****\n\n"
	make
	printf "\n**** test no relink ****\n\n"
	make
	printf "\n**** ls ****\n\n"
	ls
	if [ ${BONUS} = "yes"]
	then
		printf "\n**** BONUS ****\n\n"
		make test_bonus
	fi
fi
if [ ${TEST} = "yes" ]
then
	printf "\n**** compiling main for testing purposes (make test)****\n\n"
	make test
	printf "\n**** testing ft_memset ****\n\n"
	printf "argv: \"ft_memset\" \"Hello world\" \"-\" \"6\"\n"
	./test "ft_memset" "Hello world" "-" "6"
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_memset" "Hello world" "-" "6"
	fi
	printf "\n*** testing ft_bzero \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_bzero\" \"Hello world\" \"6\"\n"
	./test "ft_bzero" "Hello world" "6" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_bzero" "Hello world" "6"
	fi
	printf "\n*** testing ft_memcpy \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_memcpy\" \"Hello world\" \"G-bye staar\" \"6\"\n"
	./test "ft_memcpy" "Hello world" "G-bye staar" "6" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_memcpy" "Hello world" "G-bye staar" "6"
	fi
	printf "\n*** testing ft_memccpy \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_memccpy\" \"Hello world\" \"G-bye staar\" \"k\" \"6\"\n"
	./test "ft_memccpy" "Hello world" "G-bye staar" "k" "6" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_memccpy" "Hello world" "G-bye staar" "k" "6"
	fi
	printf "\n*** testing ft_memmove \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_memmove\" \"Hello world\" \"G-bye staar\" \"6\"\n"
	./test "ft_memmove" "Hello world" "G-bye staar" "6" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_memmove" "Hello world" "G-bye staar" "6"
	fi
	printf "\n*** testing ft_memchr \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_memchr\" \"Hello world\" \"l\" \"6\"\n"
	./test "ft_memchr" "Hello world" "l" "6" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_memchr" "Hello world" "l" "6"
	fi
	printf "\n*** testing ft_memcmp \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_memcmp\" \"Hello world\" \"Helle staar\" \"6\"\n"
	./test "ft_memcmp" "Hello world" "Helle staar" "6" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_memcmp" "Hello world" "Helle staar" "6"
	fi
	printf "\n*** testing ft_strlen \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strlen\" \"Hello world\"\n"
	./test "ft_strlen" "Hello world" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strlen" "Hello world"
	fi
	printf "\n*** testing ft_strlcpy \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strlcpy\" \"Hello world\" \"G-bye staar\" \"7\"\n"
	./test "ft_strlcpy" "Hello world" "G-bye staar" "7"| cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strlcpy" "Hello world" "G-bye staar"
	fi
	printf "\n*** testing ft_strlcat \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strlcat\" \"Hello world\" \"G-bye staar\" \"7\"\n"
	./test "ft_strlcat" "Hello world" "G-bye staar" "7"| cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strlcat" "Hello world" "G-bye staar"
	fi
	printf "\n*** testing ft_strchr \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strchr\" \"Hello world\" \"l\"\n"
	./test "ft_strchr" "Hello world" "l" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strchr" "Hello world" "l"
	fi
	printf "\n*** testing ft_strrchr \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strrchr\" \"Hello world\" \"l\"\n"
	./test "ft_strrchr" "Hello world" "l" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strrchr" "Hello world" "l"
	fi
	printf "\n*** testing ft_strnstr \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strnstr\" \"Hello world this is a test\" \"is\" \"16\"\n"
	./test "ft_strnstr" "Hello world this is a test" "is" "16" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test  "Hello world this is a test" "is" "16"
	fi
	printf "\n*** testing ft_strncmp \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strncmp\" \"Hello world\" \"Helle staar\" \"6\"\n"
	./test "ft_strncmp" "Hello world" "Helle staar" "6" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strncmp" "Hello world" "Helle staar" "6"
	fi
	printf "\n*** testing ft_atoi \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_atoi\" \"14035\"\n"
	./test "ft_atoi" "14035" | cat -e
	printf "\n*** testing ft_atoi \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_atoi\" \"-2147483648\"\n"
	./test "ft_atoi" "-2147483648" | cat -e
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_atoi" "14035"
	fi
######################## testing isalpha digit, etc. ###########################
	######################## testing isalpha ###################################
	printf "\n*** testing ft_isalpha \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isalpha\" \"H\"\n"
	./test "ft_isalpha" "H" | cat -e
	printf "\n*** testing ft_isalpha \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isalpha\" \"3\"\n"
	./test "ft_isalpha" "3" | cat -e
	######################## testing isdigit ###################################
	printf "\n*** testing ft_isdigit \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isdigit\" \"H\"\n"
	./test "ft_isdigit" "H" | cat -e
	printf "\n*** testing ft_isdigit \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isdigit\" \"3\"\n"
	./test "ft_isdigit" "3" | cat -e
	######################## testing isalnum ###################################
	printf "\n*** testing ft_isalnum \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isalnum\" \"H\"\n"
	./test "ft_isalnum" "H" | cat -e
	printf "\n*** testing ft_isalnum \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isalnum\" \"3\"\n"
	./test "ft_isalnum" "3" | cat -e
	printf "\n*** testing ft_isalnum \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isalnum\" \"-\"\n"
	./test "ft_isalnum" "-" | cat -e
	######################## testing isprint ###################################
	printf "\n*** testing ft_isprint \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isprint\" \"H\"\n"
	./test "ft_isprint" "H" | cat -e
	printf "\n*** testing ft_isprint \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_isprint\" \"\"\n"
	./test "ft_isprint" "" | cat -e
	######################## testing toupper ###################################
	printf "\n*** testing ft_toupper \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_toupper\" \"H\"\n"
	./test "ft_toupper" "H" | cat -e
	printf "\n*** testing ft_toupper \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_toupper\" \"j\"\n"
	./test "ft_toupper" "j" | cat -e
	######################## testing tolower ###################################
	printf "\n*** testing ft_tolower \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_tolower\" \"H\"\n"
	./test "ft_tolower" "H" | cat -e
	printf "\n*** testing ft_tolower \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_tolower\" \"j\"\n"
	./test "ft_tolower" "j"
	######################## testing calloc ####################################
	printf "\n*** testing ft_calloc \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_calloc\" \"10\" \"3\"\n"
	./test "ft_calloc" "10" "3" | cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_calloc" "10" "3"
	fi
	######################## testing strdup ####################################
	printf "\n*** testing ft_strdup \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strdup\" \"Hello world!\"\n"
	./test "ft_strdup" "Hello world" | cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strdup" "Hello world"
	fi
	######################## testing substr ####################################
	printf "\n*** testing ft_substr \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_substr\" \"Hello world!\" \"3\" \"5\"\n"
	./test "ft_substr" "Hello world" "3" "5"| cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_substr" "Hello world" "3" "5"
	fi
	######################## testing strjoin ###################################
	printf "\n*** testing ft_strjoin \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strjoin\" \"Hello world!\" \", this is Sparta\"\n"
	./test "ft_strjoin" "Hello world" ", this is Sparta" | cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strjoin" "Hello world" ", this is Sparta"
	fi
	######################## testing strtrim ###################################
	printf "\n*** testing ft_strtrim \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_strtrim\" \". . .Hello world! . \" \". \"\n"
	./test "ft_strtrim" ". . .Hello world! . " ". " | cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strtrim" ". . .Hello world! . " ". "
	fi
	######################## testing split ###################################
	printf "\n*** testing ft_split \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_split\" \"..This.is.a...test.\" \".\"\n"
	./test "ft_split" "..This.is.a...test." "." | cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_split" "..This.is.a...test." "."
	fi
	######################## testing itoa ###################################
	printf "\n*** testing ft_itoa \"| cat -e\" to see no-print char ***\n\n"
	printf "argv: \"ft_itoa\" \"4354\"\n"
	./test "ft_itoa" "4354" | cat -e
	printf "\n***************** test ft_itoa negative ******************\n\n"
	printf "argv: \"ft_itoa\" \"-354\"\n"
	./test "ft_itoa" "-354" | cat -e
	printf "\n*************** testing ft_itoa underflow ****************\n\n"
	printf "argv: \"ft_itoa\" \"-2147483648\"\n"
	./test "ft_itoa" "-2147483648" | cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_itoa" "4354"
	fi
	######################## testing strmapi ###################################
	printf "\n******************** testing ft_strmapi ********************\n\n"
	printf "argv: \"ft_strmapi\" \"Hello this is a test\"\n"
	./test "ft_strmapi" "Hello this is a test" | cat -e
	if [ ${VALGRIND} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_strmapi" "Hello this is a test"
	fi
	######################## testing filedes ###################################
	touch testfile
	echo "" > newline
	printf "\n****************** testing ft_putchar_fd ******************\n\n"
	printf "argv: \"ft_putchar_fd\" \"testfile\" \"K\"\n"
	./test "ft_putchar_fd" "testfile" "K"
	if [ ${VLG_MAIN} = "yes" ]
	then
		printf "\n**** testing for memory leaks ****\n\n"
		valgrind --leak-check=full ./test "ft_putchar_fd" "testfile" "K"
	fi
	#printf "echo \"\" > newline\n"
	printf "cat testfile\n"
	cat testfile newline
	if [ ${RMTESTFILE} = "yes" ]
	then
		printf "rm testfile\n"
		rm testfile
		touch testfile
	fi
	printf "\n****************** testing ft_putstr_fd ******************\n\n"
	printf "argv: \"ft_putstr_fd\" \"testfile\" \"This is a sentence\"\n"
	./test "ft_putstr_fd" "testfile" "This is a sentence"
	printf "cat testfile\n"
	cat testfile newline
	if [ ${RMTESTFILE} = "yes" ]
	then
		printf "rm testfile\n"
		rm testfile
		touch testfile
	fi
	printf "\n****** testing ft_putendl_fd | cat -e to see newline *******\n\n"
	printf "argv: \"ft_putendl_fd\" \"testfile\" \"This is a sentence\"\n"
	./test "ft_putendl_fd" "testfile" "This is a sentence"
	printf "cat -e testfile\n"
	cat -e testfile
	if [ ${RMTESTFILE} = "yes" ]
	then
		printf "rm testfile\n"
		rm testfile
		touch testfile
	fi
	printf "\n*********** testing ft_putnbr_fd positives *****************\n\n"
	printf "argv: \"ft_putnbr_fd\" \"testfile\" \"124\"\n"
	./test "ft_putnbr_fd" "testfile" "124"
	printf "cat testfile\n"
	cat testfile newline
	if [ ${RMTESTFILE} = "yes" ]
	then
		printf "rm testfile\n"
		rm testfile
		touch testfile
	fi
	printf "\n*********** testing ft_putnbr_fd negatives *****************\n\n"
	printf "argv: \"ft_putnbr_fd\" \"testfile\" \"-124\"\n"
	./test "ft_putnbr_fd" "testfile" "-124"
	printf "cat testfile\n"
	cat testfile newline
	if [ ${RMTESTFILE} = "yes" ]
	then
		printf "rm testfile\n"
		rm testfile
		touch testfile
	fi
	printf "\n*********** testing ft_putnbr_fd underflow *****************\n\n"
	printf "argv: \"ft_putnbr_fd\" \"testfile\" \"-2147483648\"\n"
	./test "ft_putnbr_fd" "testfile" "-2147483648"
	printf "cat testfile\n"
	cat testfile newline
	if [ ${RMTESTFILE} = "yes" ]
	then
		printf "rm testfile\n"
		rm testfile
	fi
	rm newline
	######################## testing bonus #####################################
	if [ ${BONUS} = "yes" ]
		printf "\n******************* COMPILING BONUS *********************\n\n"
		make test_bonus
	then
		printf "\n**************** testing BONUS LIST FUNCTIONS ***********\n\n"
		printf "\n****************** testing ft_lstnew ******************\n\n"
		printf "argv: \"ft_lstnew\" \"This is a new element\"\n"
		./test_bonus "ft_lstnew" "This is a new element"
		if [ ${VLG_MAIN} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstnew" "This is a new element"
		fi
		printf "\n*************** testing ft_lstadd_front *****************\n\n"
		printf "argv: \"ft_lstadd_front\" \"This is an existing element\" \"This is the new head.\"\n"
		./test_bonus "ft_lstadd_front" "This is an existing element" "This is the new head."
		if [ ${VLG_MAIN} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstadd_front" "This is an existing element" "This is the new head."
		fi
		printf "\n*************** testing ft_lstsize *****************\n\n"
		printf "argv: \"ft_lstsize\" \"This is an existing element\" \"This is the new head.\"\n"
		./test_bonus "ft_lstsize" "This is an existing element" "This is the new head."
		if [ ${VLG_MAIN} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstsize" "This is an existing element" "This is the new head."
		fi
		printf "\n*************** testing ft_lstlast *****************\n\n"
		printf "argv: \"ft_lstlast\" \"This is an existing element\" \"This is the new head.\"\n"
		./test_bonus "ft_lstlast" "This is an existing element" "This is the new head."
		if [ ${VLG_MAIN} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstlast" "This is an existing element" "This is the new head."
		fi
		printf "\n*************** testing ft_lstadd_back *****************\n\n"
		printf "argv: \"ft_lstadd_back\" \"This is an existing element\" \"This is the new head.\" \"This is added to the back\"\n"
		./test_bonus "ft_lstadd_back" "This is an existing element" "This is the new head." "This is added to the back"
		if [ ${VLG_MAIN} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstadd_back" "This is an existing element" "This is the new head." "This is added to the back"
		fi
		printf "\n*************** testing ft_lstdelone *****************\n\n"
		printf "argv: \"ft_lstdelone\" \"This is an existing element\" \"This is the new head.\" \"This is added to the back\"\n"
		./test_bonus "ft_lstdelone" "This is an existing element" "This is the new head." "This is added to the back"
		if [ ${VLG_MAIN} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstdelone" "This is an existing element" "This is the new head." "This is added to the back"
		fi
		printf "\n*************** testing ft_lstclear *****************\n\n"
		printf "argv: \"ft_lstclear\" \"This is an existing element\" \"This is the new head.\" \"This is added to the back\"\n"
		./test_bonus "ft_lstclear" "This is an existing element" "This is the new head." "This is added to the back"
		if [ ${VALGRIND} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstclear" "This is an existing element" "This is the new head." "This is added to the back"
		fi
		printf "\n*************** testing ft_lstiter *****************\n\n"
		printf "argv: \"ft_lstiter\" \"This is an existing element\" \"This is the new head.\" \"This is added to the back\"\n"
		./test_bonus "ft_lstiter" "This is an existing element" "This is the new head." "This is added to the back"
		if [ ${VALGRIND} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstiter" "This is an existing element" "This is the new head." "This is added to the back"
		fi
		printf "\n*************** testing ft_lstmap *****************\n\n"
		printf "argv: \"ft_lstmap\" \"This is an existing element\" \"This is the new head.\" \"This is added to the back\"\n"
		./test_bonus "ft_lstmap" "This is an existing element" "This is the new head." "This is added to the back"
		if [ ${VALGRIND} = "yes" ]
		then
			printf "\n**** testing for memory leaks ****\n\n"
			valgrind --leak-check=full ./test_bonus "ft_lstmap" "This is an existing element" "This is the new head." "This is added to the back"
		fi
	fi
fi
