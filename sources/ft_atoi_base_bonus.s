;int		is_space(char c)
;{
;	if (c == ' ' || (8 < c && c < 14))
;		return (1);
;	else
;		return (0);
;}
;
;int		is_base(char *base, int len)
;{
;	int	i;
;	int	j;
;
;	i = 0;
;	if (len < 2)
;		return (0);
;	while (i < len - 1)
;	{
;		if (i == 0 && (base[i] == '+' || base[i] == '-' || is_space(base[i])))
;			return (0);
;		j = i + 1;
;		while (j < len)
;		{
;			if (base[j] == base[i] || (i == 0 && (base[j] == '+' ||
;							base[j] == '-' || is_space(base[j]))))
;				return (0);
;			j++;
;		}
;		i++;
;	}
;	return (1);
;}
;
;int		str_len(char *str)
;{
;	unsigned int	len;
;
;	len = 0;
;	while (*str)
;	{
;		len++;
;		str++;
;	}
;	return (len);
;}
;
;int		to_base(char *str, char *base, int base_size)
;{
;	unsigned int	res;
;	int				i;
;	int				sg;
;
;	res = 0;
;	sg = 1;
;	while (*str && (*str == '+' || *str == '-'))
;	{
;		if (*str == '-')
;			sg = (-1) * sg;
;		str++;
;	}
;	while (*str)
;	{
;		i = 0;
;		while (*str != base[i])
;			i++;
;		if (i < base_size)
;			res = base_size * res + i;
;		else
;			return (sg * (int)res);
;		str++;
;	}
;	return (sg * (int)res);
;}
;
;int		ft_atoi_base(char *str, char *base)
;{
;	int base_size;
;
;	base_size = str_len(base);
;	if (!is_base(base, base_size))
;		return (0);
;	else
;	{
;		while (*str && is_space(*str))
;			str++;
;		return (to_base(str, base, base_size));
;	}
;}

global ft_atoi_base

ft_atoi_base:
	ret
