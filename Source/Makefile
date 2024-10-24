COMPILER = g++

CPP_STANDARD = -std=c++23
WARNING_FLAGS = -Wall -Wextra -pedantic -Werror
SANITIZER_FLAGS = # -fsanitize=address,undefined,signed-integer-overflow,bounds
OPTIMIZATION_LEVEL = -O3
LINK_TIME_OPTIMIZATION = -flto

COMPILER_FLAGS = $(CPP_STANDARD) $(WARNING_FLAGS) $(SANITIZER_FLAGS) $(OPTIMIZATION_LEVEL)

SOURCE_FILES = \
	Algorithm/Version1/Algorithm.cpp \
	Algorithm/Version2/Algorithm.cpp \
	Main.cpp \
	ValidityChecks/ValidityChecks.cpp

OBJECT_FILES = $(SOURCE_FILES:.cpp=.o)

# Output executable
TARGET = output.exe

# Build rule
all: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(COMPILER) $(COMPILER_FLAGS) $(LINK_TIME_OPTIMIZATION) -o $@ $^

# Compilation rule for object files
%.o: %.cpp
	$(COMPILER) $(COMPILER_FLAGS) -c -o $@ $<

VALGRIND = valgrind

VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

valgrind: $(TARGET)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(TARGET)

clean:
	rm -f $(OBJECT_FILES) $(TARGET)

.PHONY: all clean valgrind
