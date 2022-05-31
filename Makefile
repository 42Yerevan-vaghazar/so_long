NAME = so_long

CC	=	cc

CFLAGS = -g

SRCS = $(wildcard ./src/*.c)

LIBS = $(shell find . -name '*.a')

OBJS = $(patsubst %.c, %.o, $(SRCS))

RM = rm -f

AR = ar rcs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = get_next_line
GNL = $(LIBFT_DIR)/get_next_line.a

%.o: %.c
	$(CC) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@make --no-print-directory clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make --no-print-directory fclean -C $(LIBFT_DIR)

re:	fclean all

bonus:	all

.PHONY: all clean fclean re bonus
