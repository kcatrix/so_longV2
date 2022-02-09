CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra

MY_CPPFLAGS = -I$(LIBPATH) -I$(LIBFTDIR)

CPPFLAGS = $(MY_CPPFLAGS)

NAME = so_long

SRCDIR = ./srcs

SRC = $(wildcard $(SRCDIR)/*.c)

LIBFTDIR = ./libft
APLIBFT = $(LIBFTDIR)/libft.a

OBJ = $(SRC:.c=.o)

LDLIBS = $(APGNL) $(APLIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit

all:
	@$(MAKE) -j $(NAME)	

$(NAME): $(SRC)
	@$(MAKE) -j -s --no-print-directory -C $(LIBFTDIR)
	$(CC) $(LDLIBS) $(CFLAGS) $(SRC) $(APLIBFT) -o $(NAME)

%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $(SRC) $< -o $@ 

clean:
	@$(MAKE) -s --no-print-directory -C $(LIBFTDIR) clean
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -s --no-print-directory -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
