SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(shell find src/ -type f -name '*.cpp')
OBJ_FILES := $(SRC_FILES:.cpp=.o)

SRC_DIRS := $(dir $(SRC_FILES))
OBJ_DIRS := $(dir $(OBJ_FILES))

CFLAGS := -Werror
LIBS := -lm -pthread -lX11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lboost_system
INCLUDES := -I include -I assets

MAIN := game

DOCCMD := doxygen

TEST := false

DOCFILE := Doxyfile

ifeq ($(TEST),true)
TEST_FLAGS := -DTEST_SYSTEM
endif

all: $(MAIN)

remake: clean all

$(MAIN): $(OBJ_FILES)
	g++ $(CLFAGS) -o $@ $(OBJ_FILES) $(LIBS)

.cpp.o:
	@mkdir -p $(OBJ_DIRS)
	g++ $(CLFAGS) $(INCLUDES) $(TEST_FLAGS) -c -o $@ $<

.PHONY: clean docs depend test

test:
	@echo $(SRC_FILES:.cpp=.o)

clean:
	$(RM) $(addprefix $(SOURCE), *~) $(MAIN); find . -type f -name '*.o' -delete

docs:
	$(DOCCMD) $(DOCFILE)

depend: $(SRCS)
	makedepend $(INCLUDES) $^