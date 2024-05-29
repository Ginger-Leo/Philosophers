# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:01:51 by lstorey           #+#    #+#              #
#    Updated: 2024/05/29 11:01:58 by lstorey          ###   ########.fr        #
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
				$(CC) $(FLAGS) -g -fsanitize=thread -static-libsan $(SRC) -o san 

clean		:	
				rm -f $(OBJ)

				 

fclean		:	clean
				rm -f $(NAME)


re			:	fclean all

.PHONY 		: all clean fclean re 
