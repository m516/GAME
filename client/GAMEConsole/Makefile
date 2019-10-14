#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

SOURCE = src/

# define the C++ compiler to use
CXX = g++

# define any compile-time flags
# -Wall warnings, errors
# -Werror errors only
CFLAGS = -Werror

# define any directories containing header files other than /usr/include
#
INCLUDES = -I $(SOURCE)include/

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
# LFLAGS = -L

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lm

# define the C++ source files
SRCS = $(addprefix $(SOURCE), main.cpp \
		application.cpp \
		GUI/theme.cpp \
		GUI/guiElement.cpp \
		GUI/button.cpp \
		GUI/panel.cpp \
		GUI/Menu/menuItem.cpp \
		GUI/Menu/menuPane.cpp \
		UI/menuNavigator.cpp )

# define the C++ object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .cpp of all words in the macro SRCS
# with the .o suffix
#

OBJS = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = game

DOCCMD = doxygen
DOCFILE = Doxyfile

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean docs

all: $(MAIN)
	@echo  Simple compiler named game has been compiled

# $(LFLAGS)
$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS) 

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $<  -o $@ 

clean:
	$(RM) $(addprefix $(SOURCE), *.o GUI/*.o UI/*.o GUI/Menu/*.o *~) $(MAIN)

# Creats Doxygen documentation in docs/html
docs:
	$(DOCCMD) $(DOCFILE)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
