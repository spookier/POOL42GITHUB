int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int 	param_invalid(char *input, int size)
{
	int i = 0;
	if(ft_strlen(input) != ((size * 2 * 4) - 1))
	{
		return 1;
	}
	while(input[i] != '\0')
	{
		if( (input[i] < '1' || input[i] > (size + '0'))
		    && input[i] != ' ')
			return 1;
		i++;
	}
	return 0;
}
