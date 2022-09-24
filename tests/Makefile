NAME			= ft_printf_test
SRC_TEST		= ft_printf_test.c

CFLAGS 			= -Wall -Wextra -Werror

PRINTF_INCLUDES = ../src/includes
LIBFT_INCLUDES  := ../src/libft/includes
PRINTF_LIB		:= libftprintf.a

SRCDIR 			= ../src
SRC 			= ft_printf.c
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

mtest: $(SRCS) minunit.c $(TEST_FILES)
	$(CC) $(CFLAGS) -I$(PRINTF_INCLUDES) -I$(LIBFT_DIR) minunit.c -o mtest $(SRCS)

vgnl: $(NAME) 
	valgrind ./$(NAME)

vm: mtest
	valgrind --error-exitcode=42 --leak-check=full ./mtest
clean:
	@rm -f *.o
	
fclean: clean
	@rm -f $(NAME)
	@rm -f mtest

re: fclean all

rem: fclean m
