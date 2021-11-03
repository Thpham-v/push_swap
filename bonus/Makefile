NAME			=	checker
SRCS_DIR		=	./srcs/
SRCS			=	main_bonus.c				\
					get_next_line_bonus.c			\
					get_next_line_utils_bonus.c

PS_SRCS_DIR		=	../srcs/

SRCS_BASENAME	=	$(addprefix $(SRCS_DIR), $(SRCS))			\
					$(addprefix $(PS_SRCS_DIR), parsing.c)		\
					$(addprefix $(PS_SRCS_DIR), utils.c)	\
					$(addprefix $(PS_SRCS_DIR), operations1.c)	\
					$(addprefix $(PS_SRCS_DIR), operations2.c)		\
					$(addprefix $(PS_SRCS_DIR), operations3.c)		\
					$(addprefix $(PS_SRCS_DIR), init_tab.c)

OBJS			=	$(SRCS_BASENAME:.c=.o)

CC					=	clang

FLAGS				=	-Wall -Werror -Wextra -I ./header

.c.o		:
			$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) $(OBJS) $(FLAGS) -o $(NAME)
			@echo [$(NAME)] : Created !

clean		:
			rm -rf $(OBJS)

fclean		:	clean
			rm -f $(NAME)
			@echo [$(NAME)] : Deleted !

re			:	fclean all

.PHONY: 		clean fclean all re