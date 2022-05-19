# NAME = test

# CXX = c++

# DEPFLAGS = -MMD -MP

# CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# SRC = test.cpp

# INC = vector.hpp

# OBJ = $(SRC:.cpp=.o)

# all: $(NAME)

# $(NAME): $(OBJ) $(INC)
# 	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -o $@ $<

# -include $(OBJ:.o=.d)

# clean:
# 	/bin/rm -rf $(OBJ) *.d

# fclean: clean
# 	/bin/rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

NAME = test

CXX = c++

CXXFLAGS = -MMD -MP -Wall -Wextra -Werror -std=c++98# -g -fsanitize=address

SRC = test.cpp

INC = ./includes/vector.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $+

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)

clean:
	/bin/rm -rf $(OBJ) *.d

fclean: clean
	/bin/rm -f $(NAME)

-include $(OBJ:.o=.d)

re: fclean all

.PHONY: all clean fclean re
