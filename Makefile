SRC =	push.c r_rotate.c rotate.c sort_utils.c sort.c\
		swap.c utils.c

SRC_MAIN = 	push_swap.c

NAME = push_swap

LIBFT = libft

FT_PRINTF = ft_printf

OBJS_DIR = objs/
SRCS_DIR = src/

OBJS = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECT_MAIN_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJ_MAIN))
SOURCES_PREFIXED = $(addprefix $(SRCS_DIR), $(SRC))
SOURCE_MAIN_PREFIXED = $(addprefix $(SRCS_DIR), $(SRC_MAIN))

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c inc/push_swap.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(C_FLAGS) $(OBJS) -c $< -o $@

$(NAME): $(OBJS) $(OBJ_MAIN)
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@$(CC) -o $(NAME) $(OBJS) $(OBJ_MAIN) libft/libft.a ft_printf/libftprintf.a

clean:
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@rm -f $(OBJS) $(OBJ_MAIN) $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
