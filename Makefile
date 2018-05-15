NAME = RT

INC = -I./includes

GCC = clang++ 
# WWW = -Wall -Werror -Wextra

SRC = RT.cpp Vect.cpp Ray.cpp Camera.cpp Color.cpp Light.cpp

OBJ	= $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

OBJDIR =	./objects/
SRCDIR	=	./sources/

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
			$(GCC) -o $@ $(OBJ)

$(OBJDIR):
			mkdir -p $@

$(OBJDIR)%.o:$(SRCDIR)%.cpp
			$(GCC) $(WWW) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
