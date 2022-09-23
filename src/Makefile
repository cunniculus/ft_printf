NAME		:= libftprintf.a
SOURCES		:= ft_printf.c
OBJECTS		:= $(patsubst %.c, %.o, $(SOURCES))
INCLUDES	:= libftprintf.h
LIBFT_DIR	:= libft
LIBFT		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES) 
	@make -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) -c $(SOURCES)

clean:
	@rm -f $(OBJECTS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
