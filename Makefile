NAME				=	push_swap
BONUS_NAME			=	checker
BONUS_DIR			=	./bonus/
SRCS_DIR			=	./srcs/
SRCS			=	main.c	\
					init_tab.c	\
					operations1.c	\
					operations2.c	\
					operations3.c	\
					parsing.c		\
					utils.c			\
					algo_utils.c	\
					algo.c		

					
SRCS_BASENAME		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS				=	$(SRCS_BASENAME:.c=.o)
CC					=	clang
FLAGS				=	-Wall -Werror -Wextra -I ./header

.c.o			:
				$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

all				:	$(NAME)

bonus			:	$(NAME) $(BONUS_NAME)

$(NAME)			:	$(OBJS)
				$(CC) $(OBJS) $(FLAGS) -o $(NAME)
				@echo [$(NAME)] : Created !

$(BONUS_NAME)	:
				make -C $(BONUS_DIR)
				mv $(BONUS_DIR)$(BONUS_NAME) ./

clean			:
				rm -f $(OBJS)
				make clean -C $(BONUS_DIR)

fclean			:	clean
				rm -f $(NAME)
				rm -f $(BONUS_NAME)

re				:	fclean all

.PHONY: 		clean fclean all re