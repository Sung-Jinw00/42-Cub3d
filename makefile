MAKEFLAGS += -s

CC				= cc
FLAGS			= -Wall -Wextra -Werror -g -w
HDRS			= includes
MLX_HDRS		= mlx
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
SRCS_DIR		= ./
OBJ_DIR			= obj

SRCS			= $(shell find $(SRCS_DIR) -type f -name '*.c' ! -path '$(SRCS_DIR)/mlx/*' ! -path '$(SRCS_DIR)/libft/*')
SRC_O			= $(SRCS:$(SRCS_DIR)%.c=$(OBJ_DIR)/%.o)

MLX_FLAGS		= -L mlx -lmlx -lXpm -lXext -lX11 -lm
LIB_PATH		= mlx
LIB_MLX			= $(LIB_PATH)/libmlx.a

NAME			= cub3d
RM				= rm -f
CYAN			= "\033[36m"
RED				= "\033[31m"
GREEN			= "\033[32m"
RESET			= "\033[0m"

all: $(NAME)

$(NAME): $(LIBFT) $(SRC_O) $(LIB_MLX)
	@echo $(CYAN)"Compilation de Cub3D..."$(RESET)
	@$(CC) $(FLAGS) $(SRC_O) $(LIB_MLX) $(MLX_FLAGS) -L libs -lft -I includes -I libft -I libft/includes -I $(MLX_HDRS) -o $(NAME)
	@echo $(GREEN)"Exécutable $(NAME) créé !"$(RESET)

$(LIBFT):
	@mkdir -p libs
	@mkdir -p $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	@mv $(LIBFT) libs

$(OBJ_DIR)/%.o: $(SRCS_DIR)%.c includes/*.h libft/*.h libft/includes/*.h
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -I includes -I libft -I libft/includes -I $(MLX_HDRS) -c $< -o $@

# Règle pour la compilation de MiniLibX
$(LIB_MLX):
	@echo $(CYAN)"Compilation de MiniLibX..."$(RESET)
	@make -s -C $(LIB_PATH)
	@echo $(GREEN)"MiniLibX compilée !"$(RESET)

clean:
	@echo $(CYAN)"Suppression des fichiers objets..."$(RESET)
	@rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo $(CYAN)"Suppression de l'exécutable..."$(RESET)
	@$(RM) $(NAME)
	@echo $(CYAN)"Suppression des libs..."$(RESET)
	@$(RM) libs/*.a

re: fclean all

.PHONY: all clean fclean re
