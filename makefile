# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 10:11:18 by fdessoy-          #+#    #+#              #
#    Updated: 2024/06/07 14:19:27 by fdessoy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo
CC			= 	cc
FLAGS		= 	-Wall -Werror -Wextra -pedantic
LIBS 		= 	philo.h
SRC 		=	philo.c\
				printer.c\
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
