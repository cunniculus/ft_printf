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
char *	ft_litoa_base(unsigned long nbr, char *base);
int 	convert_printf(t_printf_info *info, va_list args, size_t *counter);
size_t	convert_nbr_int(t_printf_info *info, va_list args);
int 	convert_pchar(t_printf_info *info, va_list args);
int 	convert_base(t_printf_info *info, va_list args);
char	*ft_strjoin_free(char *s1, char  **s2);

#endif
