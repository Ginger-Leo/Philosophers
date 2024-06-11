# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 10:11:18 by fdessoy-          #+#    #+#              #
#    Updated: 2024/06/11 15:11:28 by fdessoy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo
CC		= 	cc
FLAGS		= 	-Wall -Werror -Wextra -pedantic -g
LIBS 		= 	philo.h
SRC 		=	philo.c\
				printer.c\
				parsing.c\
				utils.c\
				struct_utils.c\
				main.c\
				locks.c\
				routine.c
		
OBJ  		= 	$(SRC:.c=.o) 

$(NAME)		:	$(OBJ)
				cc $(FLAGS) $(OBJ) -o $(NAME)
				
%.o			:	%.c
				$(CC) $(FLAGS) -c $< -o $@
				
				
all			:	$(NAME)

#san			: DOESNT WORK IN LLINUX
#				$(CC) $(FLAGS) -g -fsanitize=address -static-libasan $(SRC) -o san 

clean		:	
				rm -f $(OBJ)

				 

fclean		:	clean
				rm -f $(NAME)


re			:	fclean all

.PHONY 		: all clean fclean re 