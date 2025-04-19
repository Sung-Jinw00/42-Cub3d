NAME = cub3d

INCLUDE = include
SRC_DIR = src
OBJ_DIR = objs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

FILES = main.c

OBJS = $(FILES:%.c=$(OBJ_DIR)/%.o)

RM = rm -f

CYAN = "\033[36m"
RED	= "\033[31m"
GREEN = "\033[32m"
RESET = "\033[0m"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo $(CYAN)"Compilation de Cub3D..."$(RESET)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -I $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"Exécutable $(NAME) créé !"$(RESET)

$(LIBFT):
	@echo -n "Compiling libft..."
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "\nLibft compilation done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Suppression de l'exécutable..."
	@$(RM) $(NAME)
	@echo "Suppression de libft..."
	@make -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re
