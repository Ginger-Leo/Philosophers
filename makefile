# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:32:21 by lstorey           #+#    #+#              #
#    Updated: 2024/05/29 10:07:04 by lstorey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo
CC			= 	cc
FLAGS		= 	-Wall -Werror -Wextra -g
LIBS 		= 	philo.h
SRC 		=	philo.c\
				error_printer.c\
				parsing.c\
				utils.c\
				struct_utils.c\
				main.c\
		
OBJ  		= 	$(SRC:.c=.o) 

$(NAME)		:	$(OBJ) 

				cc $(FLAGS) $(OBJ) -o $(NAME)
				
%.o			:	%.c
				@CC $(FLAGS) -c $< -o $@
				
				
all			:	$(NAME)

san			:
				$(CC) $(FLAGS) -g -fsanitize=address -static-libsan $(SRC) -o san 

clean		:	
				rm -f $(OBJ)

				 

fclean		:	clean
				rm -f $(NAME)


re			:	fclean all

.PHONY 		: all clean fclean re 
