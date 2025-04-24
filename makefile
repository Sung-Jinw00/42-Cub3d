NAME = cub3d

INCLUDE = includes
SRC_DIR = src
OBJ_DIR = objs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx_Linux.a

CC = cc
FLAGS = -Wall -Werror -g
MLX_FLAGS = -lX11 -lXext -lm

FILES = main.c\
		free.c\
		printing.c\
		treat_map.c\
		treat_file.c\
		player_check.c

OBJS = $(FILES:%.c=$(OBJ_DIR)/%.o)

RM = rm -f

CYAN = "\033[36m"
RED    = "\033[31m"
GREEN = "\033[32m"
RESET = "\033[0m"

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo $(CYAN)"Compilation de Cub3D..."$(RESET)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -I $(INCLUDE) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(LIBFT_DIR)/includes -o $(NAME) $(MLX_FLAGS)
	@echo $(GREEN)"Exécutable $(NAME) créé !"$(RESET)

$(LIBFT):
	@echo -n "Compiling libft..."
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "\nLibft compilation done!"

$(MLX):
	@echo -n "Compiling libmlx..."
	@make -C $(MLX_DIR) > /dev/null
	@echo "\nLibmlx compilation done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I $(INCLUDE) -I $(LIBFT_DIR) -I $(LIBFT_DIR)/includes -I $(MLX_DIR) -c $< -o $@

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