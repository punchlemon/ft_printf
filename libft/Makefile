# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retanaka <retanaka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 19:23:41 by retanaka          #+#    #+#              #
#    Updated: 2024/05/12 20:22:18 by retanaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
INCLUDES		=	../include
SRCS_DIR		=	src/
OBJS_DIR		=	obj/
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I
RM				=	rm -f
AR				=	ar rcs

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

SRC_FILES		=	ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_strlen \
					ft_memset \
					ft_bzero \
					ft_memcpy \
					ft_memmove \
					ft_strlcpy \
					ft_strlcat \
					ft_toupper \
					ft_tolower \
					ft_strchr \
					ft_strrchr \
					ft_strncmp \
					ft_memchr \
					ft_memcmp \
					ft_strnstr \
					ft_atoi \
					ft_calloc \
					ft_strdup \
					ft_substr \
					ft_strjoin \
					ft_strtrim \
					ft_split \
					ft_itoa \
					ft_strmapi \
					ft_striteri \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \
					ft_lstnew \
					ft_lstadd_front \
					ft_lstsize \
					ft_lstlast \
					ft_lstadd_back \
					ft_lstdelone \
					ft_lstclear \
					ft_lstiter \
					ft_lstmap \

SRCS			=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS			=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJSF			=	.cache_exists

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(AR) $(NAME) $(OBJS)
				@ranlib $(NAME)
				@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
				@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
				@mkdir -p $(OBJS_DIR)

clean:
				@$(RM) -r $(OBJS_DIR)
				@$(RM) $(OBJSF)
				@echo "$(BLUE)libft objects files cleaned!$(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:				fclean all
				@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

norm:
				@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
