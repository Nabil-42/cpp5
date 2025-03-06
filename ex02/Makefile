# Variables
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
OBJ = $(SRC:%.cpp=obj/%.o)
OBJDIR = obj
EXEC = bureaucrat

# Compilation flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Règles
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Créer le dossier obj s'il n'existe pas
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilation des fichiers objets dans obj
obj/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJDIR) $(EXEC)

fclean: clean

re: fclean $(EXEC)
