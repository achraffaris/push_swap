NAME = push_swap.a
NAME_BONUS = checker.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rc

SRCS = 	push_swap.c \
		utils/common.c \
		utils/ft_atoi.c \
		utils/ft_errors.c \
		utils/stack_a.c \
		utils/stack_b.c \
		utils/checker.c \
		utils/mini_sort.c \
		utils/comp.c \
		utils/stack_ab.c

BSRCS = bonus/checker.c \
		bonus/stack_a_bonus.c \
		bonus/stack_b_bonus.c \
		utils/common.c \
		utils/ft_atoi.c \
		utils/ft_errors.c \
		utils/checker.c \
		utils/mini_sort.c \
		utils/comp.c \
		utils/get_next_line/get_next_line_utils.c \
		utils/get_next_line/get_next_line.c \
		utils/stack_ab.c
		
BOBJS = $(BSRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@rm -rf $(NAME_BONUS)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(NAME) -o push_swap

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BOBJS)
	@rm -rf $(NAME)
	@$(AR) $(NAME_BONUS) $(BOBJS)
	@$(CC) $(CFLAGS) $(NAME_BONUS) -o checker 

clean:
	@rm -rf $(OBJS) $(BOBJS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf push_swap

re : fclean all

.PHONY: re fclean all clean bonus