#include "libftprintf.h"

char *get_precision_diu(t_printf_info *info, char **str)
{
	int		len;
	char	*tmp;
	int		neg;


	len = (int) ft_strlen(*str); 
	neg = FALSE;
	tmp = *str;
	if (**str == '-')
	{
		tmp = ft_strtrim(*str, "-");
		free(*str);
		neg = TRUE;
	}
	while(len < info->prec) 
	{
		tmp = ft_strjoin_free("0", &tmp);
		len++;
	}
	if (info->showsign && !neg && info->spec != 'u')
	{
		tmp = ft_strjoin_free("+", &tmp);
	}
	if (info->space && !neg && info->spec != 'u') 
	{
		tmp = ft_strjoin_free(" ", &tmp);
	}
	if (neg)
		tmp = ft_strjoin_free("-", &tmp);
	return (tmp);
}

char *get_precision_s(t_printf_info *info, char **str)
{
	char	*nstr;

	if (!info->prec)
		return (0);
	nstr = *str;
	if (info->spec == 's')
		nstr = ft_substr(*str, 0, info->prec);
	free(*str);
	return (nstr);
}
