#include "libftprintf.h"

char *get_precision_diu(t_printf_info *info, char **str)
{
	int		len;

	if (info->spec == 'd' || info->spec == 'i' || info->spec == 'u')
	len = (int) ft_strlen(*str); 
	while(len < info->prec) 
	{
		*str = ft_strjoin_free("0", str);
		len++;
	}
	return (*str);
}

char *get_precision_s(t_printf_info *info, char **str)
{
	char	*nstr;

	if (!info->prec)
		return (0);
	if (info->spec == 's')
		nstr = ft_substr(*str, 0, info->prec);
	free(*str);
	return (nstr);
}
