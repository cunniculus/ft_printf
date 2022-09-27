#include "libft.h"

int main()
{
	ft_putnbr_fd(ft_putnbr_fd(42, 1),1);
	write(1, "\n", 1);
	ft_putnbr_fd(INT_MAX, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(ft_putnbr_fd(-2, 1),1);
	write(1, "\n", 1);
}
