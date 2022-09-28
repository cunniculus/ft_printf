#include "libftprintf.h"

char *get_width(t_printf_info *info, char **str)
{
	int	len;

	len = (int) ft_strlen(*str); 
	while(len < info->width) 
	{
		*str = ft_strjoin_free(" ", str);
		len++;
	}
	return (*str);
}
/*
char *get_width_s(t_printf_info *info, char **str)
{
	int	len;

	len = (int) ft_strlen(*str); 
	while(len < info->width) 
	{
		*str = ft_strjoin_free(" ", str);
		len++;
	}
	return (*str);
}
*/
