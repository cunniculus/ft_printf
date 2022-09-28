NAME			:= libftprintf.a
SOURCES			:= ft_printf.c\
				   ft_printf_utils.c\
				   ft_printf_convert.c\
				   ft_convert_integer.c\
				   ft_convert_char_and_str.c\
				   ft_convert_pointer.c\
				   precision.c\
				   width.c
OBJECTS			:= $(patsubst %.c, %.o, $(SOURCES))
LIBFT_DIR		:= libft
INCLUDES		:= $(LIBFT_DIR)/includes 
PRINT_INCLUDES  := includes
GNL_HEADER		:= $(INCLUDES)/get_next_line.h
LIBFT_HEADER	:= $(INCLUDES)/libft.h
FTPRINTF_HEADER	:= libftprintf.h
LIBFT			:= libft.a
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo building ft_printf library
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(INCLUDES)
	@echo compiling
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(PRINT_INCLUDES) -c $(SOURCES)

clean:
	@rm -f $(OBJECTS)
	@echo clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo fclean
	@make -C $(LIBFT_DIR) fclean

re: fclean all
