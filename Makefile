#-fsanitize=address
# Nom de l'exécutable principal et bonus (placés dans output/)
NAME        = output/so_long
NAME_BONUS  = output/so_long_bonus

# Compilateur et flags
CC          = gcc
CFLAGS      = -g -Wall -Wextra -Werror

# Commandes pratiques
MKDIR       = mkdir -p
RM          = rm -f

# Couleurs et styles (facultatif, pour un bel affichage)
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
RED         = \033[0;31m
BOLD        = \033[1m
RESET       = \033[0m

# Répertoires
SRC_DIR     = source
MAIN_DIR    = $(SRC_DIR)/main
BONUS_DIR   = $(SRC_DIR)/bonus

OBJ_DIR     = objects
MAIN_OBJ    = $(OBJ_DIR)/main
BONUS_OBJ   = $(OBJ_DIR)/bonus

OUTPUT_DIR  = output

# Détection Linux/Mac pour les includes et flags MLX
ifeq ($(shell uname), Linux)
    MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
    INCLUDES  = -I/usr/include -Imlx -Iinclude
else
    MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
    INCLUDES  = -I/opt/X11/include -Imlx -Iinclude
endif

# Répertoires des bibliothèques tierces
FT_PRINTF_DIR = ft_printf
GNL_DIR       = gnl

# Bibliothèques statiques
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
GNL_LIB       = $(GNL_DIR)/libgnl.a

# Regroupe toutes les libs
ALL_LIBS      = $(FT_PRINTF_LIB) $(GNL_LIB)

# ------------------------------------------------------------------------------
# Sources Principales (NOMS SANS EXTENSION)
# ------------------------------------------------------------------------------
MAIN_SRC = \
    bfs_algo \
    bts_setup \
    find_exit \
    find_item \
    find_player \
    free_utils \
    hooks_setup \
    keymap_setup \
    main \
    map_is_valid \
    map_setup \
    map_utils \
    move_player \
    move_utils \
    move_utils2 \
    next_game \
    open_exit \
    open_map \
    remove_new_line \
    textures_setup \
    utils \
    wall_valid_utils \
    wall_validation \
    Were_you_move \
    window_close \
    window_setup \
	one_more_line1

# 1) On construit la liste de .c
#    ex. main => main.c
MAIN_SRCS = $(addsuffix .c, $(MAIN_SRC))
# 2) On préfixe de $(MAIN_DIR) => source/main/main.c
MAIN_SRCS := $(addprefix $(MAIN_DIR)/, $(MAIN_SRCS))

# 3) On construit la liste de .o
#    ex. main => main.o
MAIN_OBJS = $(addsuffix .o, $(MAIN_SRC))
# 4) On préfixe de $(MAIN_OBJ) => objects/main/main.o
MAIN_OBJS := $(addprefix $(MAIN_OBJ)/, $(MAIN_OBJS))

# ------------------------------------------------------------------------------
# Sources Bonus (NOMS SANS EXTENSION)
# ------------------------------------------------------------------------------
BONUS_SRC = \
    bfs_algo_bonus \
    bts_setup_bonus \
    find_exit_bonus \
    find_item_bonus \
    find_player_bonus \
    free_utils_bonus \
    hooks_setup_bonus \
    keymap_setup_bonus \
    main_bonus \
    map_is_valid_bonus \
    map_setup_bonus \
    map_utils_bonus \
    move_player_bonus \
    move_utils_bonus \
    move_utils2_bonus \
    next_game_bonus \
    open_exit_bonus \
    open_map_bonus \
    remove_new_line_bonus \
    textures_setup_bonus \
    utils_bonus \
    wall_valid_utils_bonus \
    wall_validation_bonus \
    Were_you_move_bonus \
    window_close_bonus \
    window_setup_bonus \
	monster_setup_bonus \
	find_monster_bonus \
	put_textures_bonus \
	rand_bonus \
	move_utils3_bonus \
	move_monster_bonus \
	monster_move_utils_bonus \
	ft_itoa_bonus \
	move_count_bonus \
	free_utils2_bonus \
	textures_setup2_bonus \
	one_more_line1_bonus \
	one_more_line2_bonus

# 1) monster => monster.c, 2) => source/bonus/monster.c
BONUS_SRCS = $(addsuffix .c, $(BONUS_SRC))
BONUS_SRCS := $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))

# 3) monster => monster.o, 4) => objects/bonus/monster.o
BONUS_OBJS = $(addsuffix .o, $(BONUS_SRC))
BONUS_OBJS := $(addprefix $(BONUS_OBJ)/, $(BONUS_OBJS))

# ------------------------------------------------------------------------------
# Cibles principales
# ------------------------------------------------------------------------------
all: $(FT_PRINTF_LIB) $(GNL_LIB) $(NAME)

bonus: $(FT_PRINTF_LIB) $(GNL_LIB) $(NAME_BONUS)

# ------------------------------------------------------------------------------
# Compilation du binaire principal
# ------------------------------------------------------------------------------
$(NAME): $(MAIN_OBJS) | $(OUTPUT_DIR)
	@echo "$(GREEN)→ Linking objects for the main build...$(RESET)"
	$(CC) $(CFLAGS) $(MAIN_OBJS) $(ALL_LIBS) -o $(NAME) $(MLX_FLAGS)
	@echo "$(BOLD)$(BLUE)✔ Finished building $(NAME)$(RESET)"

# ------------------------------------------------------------------------------
# Compilation du binaire bonus
# ------------------------------------------------------------------------------
$(NAME_BONUS): $(BONUS_OBJS) | $(OUTPUT_DIR)
	@echo "$(GREEN)→ Linking objects for the bonus build...$(RESET)"
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(ALL_LIBS) -o $(NAME_BONUS) $(MLX_FLAGS)
	@echo "$(BOLD)$(BLUE)✔ Finished building $(NAME_BONUS)$(RESET)"

# ------------------------------------------------------------------------------
# Création des répertoires
# ------------------------------------------------------------------------------
$(OUTPUT_DIR):
	@echo "$(YELLOW)Creating output directory '$(OUTPUT_DIR)'$(RESET)"
	@$(MKDIR) $(OUTPUT_DIR)

$(MAIN_OBJ):
	@echo "$(YELLOW)Creating object directory '$(MAIN_OBJ)'$(RESET)"
	@$(MKDIR) $(MAIN_OBJ)

$(BONUS_OBJ):
	@echo "$(YELLOW)Creating object directory '$(BONUS_OBJ)'$(RESET)"
	@$(MKDIR) $(BONUS_OBJ)

# ------------------------------------------------------------------------------
# Règles de compilation pour les sources principales
# ------------------------------------------------------------------------------
$(MAIN_OBJ)/%.o: $(MAIN_DIR)/%.c | $(MAIN_OBJ)
	@echo "$(GREEN)Compiling $< → $@$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# ------------------------------------------------------------------------------
# Règles de compilation pour les sources bonus
# ------------------------------------------------------------------------------
$(BONUS_OBJ)/%.o: $(BONUS_DIR)/%.c | $(BONUS_OBJ)
	@echo "$(GREEN)Compiling $< (bonus) → $@$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# ------------------------------------------------------------------------------
# Règles pour compiler les bibliothèques tierces
# ------------------------------------------------------------------------------
$(FT_PRINTF_LIB):
	@echo "$(YELLOW)→ Building ft_printf library...$(RESET)"
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL_LIB):
	@echo "$(YELLOW)→ Building gnl library...$(RESET)"
	@$(MAKE) -C $(GNL_DIR)

# ------------------------------------------------------------------------------
# Nettoyage
# ------------------------------------------------------------------------------
clean:
	@echo "$(RED)→ Removing object files...$(RESET)"
	$(RM) $(MAIN_OBJS) $(BONUS_OBJS)
	@echo "$(RED)→ Removing '$(OBJ_DIR)' directory...$(RESET)"
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(RED)→ Removing executables...$(RESET)"
	$(RM) $(NAME) $(NAME_BONUS)

cleanall: fclean
	@echo "$(RED)→ Cleaning ft_printf and gnl libraries...$(RESET)"
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

# Cibles phony
.PHONY: all clean fclean re bonus cleanall