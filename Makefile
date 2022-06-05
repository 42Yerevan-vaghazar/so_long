NAME = so_long

BONUS = so_long_bonus

CC	=	cc

CFLAGS = -g

SRCS = $(wildcard ./src/*.c)

SRCS_BONUS = $(filter-out ./src/get_map.c ./src/paint_window.c, $(SRCS))

SRCS_BONUS += $(wildcard ./bonus/*.c)

LIBS = $(shell find . -name '*.a')

OBJS = $(patsubst %.c, %.o, $(SRCS))

BONUS_OBJS = $(patsubst %.c, %.o, $(SRCS_BONUS))

RM = rm -f

AR = ar rcs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
LIBFTFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a
GNL_DIR = get_next_line
GNL = $(LIBFT_DIR)/get_next_line.a

# %.o: %.c
# 	$(CC) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTFTPRINTF)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFTFTPRINTF):
	@make --no-print-directory -C $(FT_PRINTF_DIR)

bonus:  $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT) $(LIBFTFTPRINTF)
	$(CC) $(CFLAGS) $(LIBS) $(BONUS_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

# $(BONUS_OBJS):

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@make --no-print-directory clean -C $(FT_PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@make --no-print-directory fclean -C $(FT_PRINTF_DIR)

re:	fclean all


.PHONY: all clean fclean re bonus
