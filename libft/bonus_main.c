#include "libft.h"
#define STDOUT 1

void displayone(t_list *list)
{
	ft_putchar_fd('"', STDOUT);
	ft_putstr_fd(list->content, STDOUT);
	ft_putstr_fd("\"\n", STDOUT);
}

void displaylist(t_list *list)
{
	int		i;
	char c;
	t_list *indirect;

	if (!(list))
		return ;
	indirect = list;
	i = 0;
	while (indirect)
	{
		c = '0' + i;
		ft_putchar_fd(c, STDOUT);
		ft_putstr_fd(" - member of the list starting from head. Content: ", STDOUT);
		displayone((t_list *)indirect);
		indirect = indirect->next;
		i++;
	}
	return ;
}

void del(void *content)
{
	int i;
	unsigned char *buff;

	i = 0;
	buff = content;
	while (buff[i] && i < 1000)
	{
		buff[i] = '\0';
		i++;
	}
	free (content);
	return ;
}

void f(void *content)
{
	int i;
	unsigned char *buff;

	buff = content;
	i = 0;
	while (buff[i])
	{
		buff[i] = ft_toupper(buff[i]);
		i++;
	}
	return ;
}

void *f2(void *content)
{
	int i;
	unsigned char *buff;

	buff = content;
	i = 0;
	while (buff[i])
	{
		buff[i] = ft_toupper(buff[i]);
		i++;
	}
	return ((void *)buff);
}

int		main_lstnew(int argc, char **argv)
{
	t_list *list;

	if (argc < 3)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	displaylist(list);
	return (0);
}

int		main_lstadd_front(int argc, char **argv)
{
	t_list *list;
	t_list *head;

	if (argc < 3)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	return (0);
}

int		main_lstsize(int argc, char **argv)
{
	int		size;
	t_list *list;
	t_list *head;

	if (argc < 3)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	size = ft_lstsize(head);
	ft_putstr_fd("The size of this list is : ", STDOUT);
	ft_putnbr_fd(size, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	return (0);
}

int		main_lstlast(int argc, char **argv)
{
	t_list *list;
	t_list *head;
	t_list *last;
	int		size;

	if (argc < 4)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	size = ft_lstsize(head);
	ft_putstr_fd("The size of this list is : ", STDOUT);
	ft_putnbr_fd(size, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	last = ft_lstlast(head);
	ft_putstr_fd("The last element of this list is : ", STDOUT);
	displayone(last);
	ft_putstr_fd("\n", STDOUT);
	return (0);
}

int		main_lstadd_back(int argc, char **argv)
{
	t_list *list;
	t_list *head;
	t_list *last;
	t_list *addback;
	int		size;

	if (argc < 5)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	size = ft_lstsize(head);
	ft_putstr_fd("The size of this list is : ", STDOUT);
	ft_putnbr_fd(size, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	last = ft_lstlast(head);
	ft_putstr_fd("The last element of this list is : ", STDOUT);
	displayone(last);
	ft_putstr_fd("\n", STDOUT);
	addback = ft_lstnew(ft_strdup(argv[4]));
	ft_lstadd_back(&head, addback);
	displaylist(head);
	return (0);
}

int		main_lstdelone(int argc, char **argv)
{
	t_list *list;
	t_list *head;
	t_list *last;
	t_list *addback;
	int		size;
	t_list *indirect;

	if (argc < 3)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	size = ft_lstsize(head);
	ft_putstr_fd("The size of this list is : ", STDOUT);
	ft_putnbr_fd(size, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	last = ft_lstlast(head);
	ft_putstr_fd("The last element of this list is : ", STDOUT);
	displayone(last);
	ft_putstr_fd("\n", STDOUT);
	addback = ft_lstnew(ft_strdup(argv[4]));
	ft_lstadd_back(&head, addback);
	displaylist(head);
	ft_putstr_fd("Deleting the head, and resetting head to \"", STDOUT);
	ft_putstr_fd(argv[2], STDOUT);
	ft_putendl_fd("\"", STDOUT);
	indirect = head->next;
	ft_lstdelone(head, &del);
	head = indirect;
	displaylist(head);
	return (0);
}

int		main_lstclear(int argc, char **argv)
{
	t_list *list;
	t_list *head;
	t_list *last;
	t_list *addback;
	int		size;

	if (argc < 5)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	size = ft_lstsize(head);
	ft_putstr_fd("The size of this list is : ", STDOUT);
	ft_putnbr_fd(size, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	last = ft_lstlast(head);
	ft_putstr_fd("The last element of this list is : ", STDOUT);
	displayone(last);
	ft_putstr_fd("\n", STDOUT);
	addback = ft_lstnew(ft_strdup(argv[4]));
	ft_lstadd_back(&head, addback);
	displaylist(head);
	ft_lstclear(&head, &del);
	displaylist(head);
	ft_putendl_fd("All freed as seen in Valgrind down here :", STDOUT);
	return (0);
}

int		main_lstiter(int argc, char **argv)
{
	t_list *list;
	t_list *head;
	t_list *last;
	t_list *addback;
	int		size;

	if (argc < 5)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	size = ft_lstsize(head);
	ft_putstr_fd("The size of this list is : ", STDOUT);
	ft_putnbr_fd(size, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	last = ft_lstlast(head);
	ft_putstr_fd("The last element of this list is : ", STDOUT);
	displayone(last);
	ft_putstr_fd("\n", STDOUT);
	addback = ft_lstnew(ft_strdup(argv[4]));
	ft_lstadd_back(&head, addback);
	displaylist(head);
	ft_putchar_fd('\n', STDOUT);
	ft_putendl_fd("Now function f is going to capitalize each char from the list above:\n", STDOUT);
	ft_lstiter(head, &f);
	displaylist(head);
	ft_lstclear(&head, &del);
	displaylist(head);
	ft_putendl_fd("All freed as seen in Valgrind down here :", STDOUT);
	return (0);
}

int		main_lstmap(int argc, char **argv)
{
	t_list *list;
	t_list *head;
	t_list *last;
	t_list *addback;
	int		size;
	t_list *newlist;

	if (argc < 5)
		return (1);
	list = ft_lstnew(ft_strdup(argv[2]));
	head = ft_lstnew(ft_strdup(argv[3]));
	ft_lstadd_front(&list, head);
	displaylist(head);
	size = ft_lstsize(head);
	ft_putstr_fd("The size of this list is : ", STDOUT);
	ft_putnbr_fd(size, STDOUT);
	ft_putchar_fd('\n', STDOUT);
	last = ft_lstlast(head);
	ft_putstr_fd("The last element of this list is : ", STDOUT);
	displayone(last);
	ft_putstr_fd("\n", STDOUT);
	addback = ft_lstnew(ft_strdup(argv[4]));
	ft_lstadd_back(&head, addback);
	displaylist(head);
	ft_putstr_fd("\n", STDOUT);
	ft_putstr_fd("This is the result of lstmap : ", STDOUT);
	ft_putstr_fd("\n", STDOUT);
	newlist = ft_lstmap(head, &f2, &del);
	displaylist(newlist);
	//ft_lstclear(&newlist, &del);
	//ft_putendl_fd("This should prove that newlist and head are diff", STDOUT);
	//displaylist(head);
	ft_lstclear(&head, &del);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 3)
		return (1);
	if (ft_strncmp(argv[1], "ft_lstnew", 18) == 0)
		return (main_lstnew(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstadd_front", 18) == 0)
		return (main_lstadd_front(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstsize", 18) == 0)
		return (main_lstsize(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstlast", 18) == 0)
		return (main_lstlast(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstadd_back", 18) == 0)
		return (main_lstadd_back(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstdelone", 18) == 0)
		return (main_lstdelone(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstclear", 18) == 0)
		return (main_lstclear(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstiter", 18) == 0)
		return (main_lstiter(argc, argv));
	else if (ft_strncmp(argv[1], "ft_lstmap", 18) == 0)
		return (main_lstmap(argc, argv));
	else
		return (1);
}
