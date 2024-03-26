# Variáveis
CC = gcc
CFLAGS = -O0 
LFLAGS = -lm

# Diretórios
SRC_DIR = src

DISTFILES = SRC_DIR LEIAME* Makefile
DISTDIR = `basename ${PWD}`

OBJ_DIR = obj

# Arquivos fonte
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Nome do executável
EXECUTABLE = perfSL 
# Regras
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Limpando sujeira ..."
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE) 

purge : clean
	@echo "Limpando tudo ..."
	rm -f $(EXECUTABLE) $(DISTDIR) $(DISTDIR).tar

dist: purge
	@echo "Gerando arquivo de distribuição ($(DISTDIR).tar) ..."
	@ln -s . $(DISTDIR)
	@tar -cvf $(DISTDIR).tar $(addprefix ./$(DISTDIR)/, $(DISTFILES))
	@rm -f $(DISTDIR)

.PHONY: all clean purge dist
