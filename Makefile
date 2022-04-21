NAME = test

SRCDIR = ./tests

SRC = $(SRCDIR)/main.cpp

INCDIR = ./includes

INC = $(INCDIR)/vector.hpp

OBJDIR = ./objects

DEPDIR = $(OBJDIR)/.dependencies

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS)

all: $(NAME)

$(NAME): $(OBJDIR)/%.o
	$(COMPILE.cc) -o $@ $+

$(OBJDIR)/%.o : %.c $(DEPDIR)/%.d | $(DEPDIR)
	$(COMPILE.cc) $(OUTPUT_OPTION) $<

$(DEPDIR): ; @mkdir -p $@

DEPFILES := $(SRC:%.c=$(DEPDIR)/%.d)
$(DEPFILES):
include $(wildcard $(DEPFILES))

clean:
	/bin/rm -rf $(OBJ) *.d

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
