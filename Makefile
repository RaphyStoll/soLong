NAME = so_long
GCC = gcc
FLAGS = -g -fsanitize=address -Wall -Wextra -Werror
MKDIR = mkdir -p
RM = rm -f
OBJDIR = objects

#! permet de switch entre linux et mac
ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

# Répertoires des bibliothèques
FT_PRINTF_DIR = ft_printf
GNL_DIR = gnl

# Bibliothèques
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
GNL_LIB = $(GNL_DIR)/libgnl.a

SRC =	utils \
		main \
		open_map \
		wall_validation \
		wall_valid_utils \
		remove_new_line \
		map_is_valid \
		map_utils \
		map_utils2 \
		map_setup \
		find_player \
		find_item \
		find_exit \
		load_textures

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


ALL_LIBS = $(FT_PRINTF_LIB) $(GNL_LIB)

all: $(FT_PRINTF_LIB) $(GNL_LIB) $(NAME)

# Règles pour compiler les bibliothèques
$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) $(ALL_LIBS) -o $(NAME) $(MLX_FLAGS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(GCC) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

cleanall: fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re