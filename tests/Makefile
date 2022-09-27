NAME			= ft_printf_test
SRC_TEST		= ft_printf_test.c

CFLAGS 			= -Wall -Wextra -Werror -Wno-format

PRINTF_INCLUDES = ../src/includes
LIBFT_INCLUDES  := ../src/libft/includes
PRINTF_LIB		:= libftprintf.a

SRCDIR 			= ../src
SRC 			= ft_printf.c\
				  ft_printf_utils.c\
				  ft_printf_convert.c\
				  ft_convert_integer.c\
				  ft_convert_char_and_str.c\
				  ft_convert_pointer.c
SRCS 			= $(addprefix $(SRCDIR)/, $(SRC))

OBJS            = ft_printf_test.o\
				  ft_printf.o

LIBFT_DIR 		= ../src/libft

CC 				= cc

all: $(NAME)
	@echo running test:
	@echo
	@./$(NAME)

$(NAME): $(SRCS) $(SRC_TEST)
	@make -C $(SRCDIR) re
	@$(CC) $(CFLAGS) -I$(PRINTF_INCLUDES) -I$(LIBFT_INCLUDES) -L$(LIBFT_DIR) $(SRCS) $(SRC_TEST) -lft -L../src -lftprintf -o $(NAME)

m: mtest 
	@./mtest

mtest: $(SRCS) mintest.c $(TEST_FILES)
	$(CC) $(CFLAGS) -I$(PRINTF_INCLUDES) -I$(LIBFT_INCLUDES) -L$(LIBFT_DIR) $(SRCS) mintest.c -lft -o mtest 

vgnl: $(NAME) 
	valgrind ./$(NAME)

vm: mtest
	valgrind --error-exitcode=42 --leak-check=full ./mtest

printf:
	@make -C $(SRCDIR) re
	$(CC) $(CFLAGS) -I$(PRINTF_INCLUDES) -I$(LIBFT_INCLUDES) -L$(LIBFT_DIR) $(SRCS) printf_test.c -lft -L../src -lftprintf -o $(NAME)
	./$(NAME)

dif:
	@make -C $(SRCDIR) re
	$(CC) $(CFLAGS) -I$(PRINTF_INCLUDES) -I$(LIBFT_INCLUDES) -L$(LIBFT_DIR) $(SRCS) $(SRC_TEST) -lft -L../src -lftprintf -o $(NAME)
	./$(NAME) > ft_printf_output.txt
	$(CC) $(CFLAGS) -I$(PRINTF_INCLUDES) -I$(LIBFT_INCLUDES) -L$(LIBFT_DIR) $(SRCS) printf_test.c -lft -L../src -lftprintf -o $(NAME)
	./$(NAME) > printf_output.txt
	diff ft_printf_output.txt printf_output.txt > output_diff

clean:
	@rm -f *.o
	
fclean: clean
	@rm -f $(NAME)
	@rm -f mtest

re: fclean all

rem: fclean m
