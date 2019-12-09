CC = g++
CFLAGS = -c 
EXE = game

LIBS := -lm -pthread -lX11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lboost_system
INCLUDES := -I include -I assets

TEST := false

ifeq ($(TEST), true)
TEST_FLAGS := -DTEST_SYSTEM
endif

SRC = src
BIN = bin
OBJ = $(BIN)/obj
DOCFILE = Doxyfile
DOCCMD = doxygen

SRC_FILES = $(shell find $(SRC)/ -type f -name '*.cpp')

EXE_FILE = $(EXE)
OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ)/%.o)

all: $(EXE_FILE)

$(EXE_FILE): $(OBJ_FILES)
	@$(CC) -o $@ $^ $(LIBS)
	@echo "Compiled $(words $(SRC_FILES)) files."
	@echo "Build successful! Run ./game"

$(OBJ_FILES): $(OBJ)/%.o: %.cpp
	@echo "Compiling" $<
	@mkdir -p $(@D)
	@$(CC) $(INCLUDES) $(CFLAGS) -o $@ $<

.PHONY: clean remake docs depend

remake: clean all

clean:
	rm -r -f $(BIN)

docs:
	$(DOCCMD) $(DOCFILE)

depend: $(SRCS)
	makedepend $(INCLUDES) $^