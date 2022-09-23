NAME = ft_printg_test
SRC_TEST = ft_printf_test.c
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ../src
CC = cc
SRCDIR = ../src
SRC = ft_printf.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC))

all: $(NAME) 
	@./$(NAME)

$(NAME): $(SRCS) $(SRC_TEST) $(TEST_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDES) $(SRC_TEST) -o $(NAME) $(SRCS)

m: mtest 
	@./mtest

mtest: $(SRCS) minunit.c $(TEST_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDES) minunit.c -o mtest $(SRCS)

vgnl: $(NAME) 
	valgrind ./$(NAME)

vm: mtest
	valgrind --error-exitcode=42 --leak-check=full ./mtest
	
fclean:
	@rm -f $(NAME)
	@rm -f mtest

re: fclean all

rem: fclean m
