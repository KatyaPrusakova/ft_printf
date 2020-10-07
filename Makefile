# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 11:04:15 by eprusako          #+#    #+#              #
#    Updated: 2020/10/07 16:26:43 by eprusako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TEST = test #DELETE

LIBFT = ./libft
LIBFTFLAGS= -L$(LIBFT) -lft
DIR_SRC = printf_src
DIR_OBJ = obj_dir
HEADER = includes

MAIN =	main.c
SRC =	check_flags.c ft_printf.c print_csp.c print_buff.c ft_ftoa.c\

YELLOW = "\033[1;33m"
NOCOLOR = "\033[0m"

SRCS = $(addprefix $(DIR_SRC)/, $(SRC))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJS)
	@echo $(YELLOW)Compiling libftprintf.a...$(NOCOLOR)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

test: $(NAME)
	gcc -g $(NAME) $(MAIN)

$(DIR_OBJ):
	@echo $(YELLOW)Compiling to .o files...$(NOCOLOR)
	@mkdir $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADER)/ft_printf.h
	@gcc -g -Wall -Wextra -Werror -I$(HEADER) -c -o $@ $<

clean:
	@echo $(YELLOW)Cleaning...$(NOCOLOR)
	@/bin/rm -rf $(DIR_OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@echo $(YELLOW)F-cleaning...$(NOCOLOR)
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: $(NAME), all, clean, fclean, re
