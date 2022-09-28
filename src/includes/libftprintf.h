/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guolivei <guolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:05:33 by guolivei          #+#    #+#             */
/*   Updated: 2022/09/28 18:05:35 by guolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# ifndef FLAG_SIZE
#  define FLAG_SIZE 32
# endif

# ifndef HEXBASELOW 
#  define HEXBASELOW "0123456789abcdef"
# endif

# ifndef HEXBASEUP 
#  define HEXBASEUP "0123456789ABCDEF"
# endif

# ifndef DECIMALBASE
#  define DECIMALBASE "0123456789"
# endif

# ifndef OCTALBASE 
#  define OCTALBASE "01234567"
# endif

#include <stdarg.h>
#include "libft.h"

typedef struct s_printf_info
{
	unsigned int	alt;
	unsigned int	space;
	unsigned int	left;
	unsigned int	showsign;
	unsigned char	pad;
	int				width;
	int				prec;
	unsigned char	spec;
}	t_printf_info;

int 	ft_printf(const char *format, ...);
int		char_is_flag(int c);
int		char_is_specifier(char c);
int		ft_putnbr_base(unsigned long nbr, char *base);
char	*ft_litoa_base(unsigned long nbr, char *base);
int 	convert_printf(t_printf_info *info, va_list args, size_t *counter);
size_t	convert_nbr_int(t_printf_info *info, va_list args);
int 	convert_pchar(t_printf_info *info, va_list args);
int 	convert_base(t_printf_info *info, va_list args);
char	*ft_strjoin_free(char *s1, char  **s2);
size_t	convert_u(t_printf_info *info, va_list args);
size_t	convert_di(t_printf_info *info, va_list args);
size_t	width_and_precision_handler(t_printf_info *info, char *str);
size_t	convert_c_and_percent(t_printf_info *info, va_list args);
size_t	convert_s(t_printf_info *info, va_list args);
size_t	convert_p(t_printf_info *info, va_list args);
char	*get_precision_diu(t_printf_info *info, char **str);
char	*get_precision_s(t_printf_info *info, char **str);
char	*get_width(t_printf_info *info, char **str);
char	*get_right_justify(t_printf_info *info, char **str);
char	*get_left_justify(t_printf_info *info, char **str);

#endif
