# Directories containing source files
SRC_DIRS = Codes TestCases

# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Find all .c files in specified directories and generate corresponding .o files
SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

# Target to build the final executable
all: solver

# Rule to build the final executable using all .o files
solver: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) solver
	

plot:
	python3 $(CFLAGS) CSV_Files/3D_plot.py

