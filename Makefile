# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 19:49:18 by retanaka          #+#    #+#              #
#    Updated: 2024/05/12 20:15:11 by retanaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
INCLUDE		=	include
LIBFT		=	libft
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
RM			=	rm -f
AR			=	ar rcs

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES	=	ft_printf_base \
				ft_printf_base_check \
				ft_putptr \
				ft_putoct \
				ft_putdec \
				ft_puthex \
				ft_putnumber_base \
				ft_printf

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:			$(NAME)

$(NAME):		$(OBJ)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)
				@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
				@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
				@mkdir -p $(OBJ_DIR)

clean:
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C $(LIBFT)
				@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)/libft.a
				@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
				@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:				fclean all
				@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
				@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:			all clean fclean re norm
