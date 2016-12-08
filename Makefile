# Italo Tobler Silva		 nUSP - 8551910
CFLAGS = -g -Wall
PROJECT = ProgDinamica
CC = g++
BINDIR = bin
SRCDIR = src
LIBDIR = lib
LIBS := $(wildcard $(LIBDIR)/*hpp)
SRCS := $(wildcard $(SRCDIR)/*cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SRCS))

all : $(BINDIR) build

build : $(OBJS)
	$(CC) -o $(PROJECT) $(OBJS)

$(BINDIR) :
	mkdir -p bin

$(BINDIR)/%.o : $(SRCDIR)/%.cpp $(LIBS)
	$(CC) -c $< -I $(LIBDIR) $(CFLAGS) -o $@

clean :
	rm -f $(BINDIR)/*.o
	rm -f $(PROJECT).zip
	rm -f $(PROJECT)
	rm -f debug.txt
	clear

run : build
	./$(PROJECT)

.zip : clean
	zip $(PROJECT).zip $(SRCS) $(LIBS) Makefile *.pdf Authors.txt

debug : all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(PROJECT) < test.in 2> debug.txt

