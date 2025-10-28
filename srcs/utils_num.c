/* 4.1- Her karkater sadece 0-9 arasında rakam olabilir. ***is_digit ile kontrol edebiliriz. */
int num_format_ok(char *s)
{
    int i = 0;
    
    i = 0; 
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    if (!s[i])
    {
        return (0);
    }
    while (s[i])
    {
        if (!is_digit(s[i]))
        {
            return (0);
        }
        i++;    
    }
    return (1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
/* 4.2- Tek bir tane +/- olabilir. 
5- INT_MIN/ INT_MAX kontrolü, eğer sayı int değeri aşıyorsa error dönmeli. ***Atoi ile kontrol edebiliriz. */
long ft_atol (const char *str)
{
    int sign; 
    long result;
    int i; 
    i = 0;
    sign = 1;
    result = 0;

    while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
    {
        i++;
    }

    if (str[i] == '+' ||str[i] == '-')
    {
        if (str[i] == '-')
        {
            sign = -1;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return (result * sign);
    
    
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}