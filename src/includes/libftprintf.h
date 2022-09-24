#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# ifndef FLAG_SIZE
#  define FLAG_SIZE 32
# endif

#include <stdarg.h>
#include "libft.h"

int ft_printf(const char *format, ...);

#endif
