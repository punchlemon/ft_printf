# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 19:49:18 by retanaka          #+#    #+#              #
#    Updated: 2024/05/30 11:30:41 by retanaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
INCLUDE		=	include
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	-I $(INCLUDE)
RM			=	rm -f
AR			=	ar rcs

# Colors
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

SRC_FILES	=	ft_printf_base \
				ft_printf_base_check \
				ft_putptr \
				ft_putoct \
				ft_putdec \
				ft_puthex \
				ft_putnumber_base \
				ft_printf \

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_DIR_FLAG=	.obj_dir_exists

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(AR) $(NAME) $(OBJ)
				@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR_FLAG)
				@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR_FLAG):
				@mkdir -p $(OBJ_DIR)

clean:
				@$(RM) -rf $(OBJ_DIR)
				@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

eclean:
				@$(RM) $(NAME)
				@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"

fclean:			clean eclean

re:				fclean all
				@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

norm:
				@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:			all clean eclean fclean re norm
