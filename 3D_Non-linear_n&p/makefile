# Directory containing source files
SRC_DIR = Codes

# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Find all .c files in SRC_DIR and create a list of corresponding .o files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Target to build the final executable
all: solver

# Rule to build the final executable using all .o files
solver: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Pattern rule to compile .c files into .o files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

# Clean rule to remove generated files
clean:
	rm -f $(SRC_DIR)/*.o solver

plot:
	python3 $(CFLAGS) CSV_Files/plot.py
