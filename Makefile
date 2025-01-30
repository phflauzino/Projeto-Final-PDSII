CXX          := g++ 
CXX_FLAGS    := -Wall -Wextra -std=c++11 -ggdb  # Alterado para C++11

BIN          := bin
SRC          := src
INCLUDE      := include
LIB          := lib

LIBRARIES    := 
EXECUTABLE   := main

# Garantir que a pasta bin exista
$(BIN):
	mkdir -p $(BIN)

# Regra para compilar o executável
all: $(BIN)/$(EXECUTABLE)

# Executar o programa
run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

# Regras de compilação dos arquivos .cpp para .o
OBJ_FILES := $(patsubst $(SRC)/games/%.cpp, $(BIN)/%.o, $(shell find $(SRC)/games -name "*.cpp")) \
             $(BIN)/jogador.o  # Adicionando jogador.o

$(BIN)/%.o: $(SRC)/games/%.cpp | $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(SRC)/players -c $< -o $@

# Regra para compilar jogador.cpp
$(BIN)/jogador.o: $(SRC)/players/jogador.cpp | $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(SRC)/players -c $< -o $@

# Regra de linkagem para o executável
$(BIN)/$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $@ $(LIBRARIES)

# Limpar os arquivos gerados
clean:
	-rm -f $(BIN)/$(EXECUTABLE) $(OBJ_FILES)
