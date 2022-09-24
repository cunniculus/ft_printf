NAME				:=	libft.a
INCLUDES			:= includes
LIBFT_DIR			:= .
LIBFT_SRC_LIST		:= ft_isalpha.c\
					ft_isdigit.c\
					ft_isalnum.c\
					ft_isascii.c\
					ft_isprint.c\
					ft_strlen.c\
					ft_memset.c\
					ft_bzero.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_toupper.c\
					ft_tolower.c\
					ft_strchr.c\
					ft_strrchr.c\
					ft_strncmp.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_strnstr.c\
					ft_strlcpy.c\
					ft_strlcat.c\
					ft_calloc.c\
					ft_strdup.c\
					ft_atoi.c\
					ft_substr.c\
					ft_strjoin.c\
					ft_strtrim.c\
					ft_split.c\
					ft_itoa.c\
					ft_strmapi.c\
					ft_striteri.c\
					ft_putchar_fd.c\
					ft_putstr_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_lstnew.c\
					ft_lstadd_front.c\
					ft_lstsize.c\
					ft_lstlast.c\
					ft_lstadd_back.c\
					ft_lstdelone.c\
					ft_lstclear.c\
					ft_lstiter.c\
					ft_lstmap.c
LIBFT_SRC			:= $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC_LIST))
LIBFT_OBJ			:= $(patsubst %.c, %.o, $(LIBFT_SRC))
GNL_DIR				:= gnl
GNL_SRC_LIST		:= get_next_line.c\
					get_next_line_utils.c
GNL_SRC				:= $(addprefix $(GNL_DIR)/, $(GNL_SRC_LIST))
GNL_OBJ 			:= $(patsubst %.c, %.o, $(GNL_SRC))
CFLAGS				:= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(GNL_OBJ) 
	@ar rcs $(NAME) $(LIBFT_OBJ) $(GNL_OBJ)

$(LIBFT_OBJ): $(LIBFT_SRC)
	@cc $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES) -c $(LIBFT_SRC) 

$(GNL_OBJ): $(GNL_SRC)
	@cc -DBUFFER_SIZE=1 $(CFLAGS) -I$(INCLUDES) -c -o $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line.c
	@cc -DBUFFER_SIZE=1 $(CFLAGS) -I$(INCLUDES) -c -o $(GNL_DIR)/get_next_line_utils.o $(GNL_DIR)/get_next_line_utils.c

clean: 
	@rm -f $(LIBFT_OBJ)
	@rm -f $(GNL_OBJ)

fclean: clean
	@rm -f $(NAME) 

re: fclean all
