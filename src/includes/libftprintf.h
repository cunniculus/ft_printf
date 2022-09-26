#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# ifndef FLAG_SIZE
#  define FLAG_SIZE 32
# endif

# ifndef HEXBASELOW 
#  define HEXBASELOW "0123456789abcdef"
# endif

# ifndef HEXBASEUP 
#  define HEXBASEup "0123456789ABCDEF"
# endif

# ifndef OCTALBASE 
#  define OCTALBASE "01234567"
# endif

#include <stdarg.h>
#include "libft.h"

typedef struct s_printf_info
{
	int				prec;
	int				width;
	unsigned char	spec;
	unsigned int	alt;
	unsigned int	space;
	unsigned int	left;
	unsigned int	showsign;
	unsigned char	pad;
}	t_printf_info;

int ft_printf(const char *format, ...);

#endif
