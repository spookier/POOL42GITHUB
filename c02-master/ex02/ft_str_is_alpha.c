int	ft_str_is_alpha(char *str)
{
	char *charptr;

	charptr = str;
	while (*charptr != 0)
	{
		if (*charptr < 'A')
		{
			return (0);
		}
		if ((*charptr > 'Z' && *charptr < 'a') || (*charptr > 'z'))
		{
			return (0);
		}
		charptr++;
	}
	return (1);
}
