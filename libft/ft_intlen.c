
int	ft_intlen(long n)
{
	int	count;

	count = 0;
	if (n == 2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
