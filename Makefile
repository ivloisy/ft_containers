NAME = test

CXX = c++

CXXFLAGS = -MMD -MP -Wall -Wextra -Werror -std=c++98# -g -fsanitize=address

SRC = test.cpp

INC = -I./includes

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $+

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC) $(INC)

clean:
	/bin/rm -rf $(OBJ) *.d

fclean: clean
	/bin/rm -f $(NAME)

-include $(OBJ:.o=.d)

re: fclean all

.PHONY: all clean fclean re
