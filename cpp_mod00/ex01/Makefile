# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pviegas <pviegas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:39:39 by pviegas           #+#    #+#              #
#    Updated: 2024/03/05 10:50:51 by pviegas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color variables
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m
RESET 	= \033[0m

# Executable name
NAME = phonebook

# Compiler options
CXX = c++
CXXFLAGS = -Werror -Wall -Wextra -std=c++98  -g #-fsanitize=address

# Paths
SRC_DIR 	= srcs/
SRC_FILES =	PhoneBook.cpp \
			Contacts.cpp \
			main.cpp
OBJ_DIR	= obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

#
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

${NAME}: $(OBJS)
	@clear
	@echo "\n$(BLUE) [Compiling] $(NAME)$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) [Success] $(NAME) created.$(RESET)\n\n"

clean:
	@clear
	@rm -rf $(OBJS)
	@echo "\n$(RED) [Deleting] .o files ... (deleted)$(RESET)\n\n"

fclean: clean
	@rm -rf $(NAME) $(OBJS)
	@echo "$(GREEN) [Success] $(NAME) files ... (deleted)$(RESET)\n\n"

re: fclean all

.PHONY: clean all fclean all re
