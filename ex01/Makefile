# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 14:33:47 by deryacar          #+#    #+#              #
#    Updated: 2025/02/15 15:45:28 by deryacar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = span

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32mDone\033[m"

clean:
	@$(RM) $(OBJ) $(NAME)
	@echo "\033[0;34mclean\033[m"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;36mfclean\033[m"

re: fclean $(NAME)

.PHONY: all clean fclean re
