int	*myerrno(void)
{
	static int	myerrno = 0;

	return (&myerrno);
}

void	set_myerrno(int value)
{
	*myerrno() = value;
}

void	reset_myerrno(void)
{
	*myerrno() = 0;
}

int	get_myerrno(void)
{
	return (*myerrno());
}
