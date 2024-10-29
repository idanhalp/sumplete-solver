COMPILER = g++

CPP_STANDARD = -std=c++23
WARNING_FLAGS = -Wall -Wextra -pedantic -Werror
SANITIZER_FLAGS = # -fsanitize=address,undefined,signed-integer-overflow,bounds
OPTIMIZATION_LEVEL = -O0
LINK_TIME_OPTIMIZATION = # -flto

COMPILER_FLAGS = $(CPP_STANDARD) $(WARNING_FLAGS) $(SANITIZER_FLAGS) $(OPTIMIZATION_LEVEL)

SOURCE_FILES = \
	Source/Algorithm/Version1/Algorithm.cpp \
	Source/Algorithm/Version2/Algorithm.cpp \
	Source/Algorithm/Version2/Utils/Trie/Trie.cpp \
	Source/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp \
	Source/ValidityChecks/ValidityChecks.cpp

TEST_FILES = \
	Tests/Algorithm/Algorithm.cpp \
	Tests/Algorithm/Version2/Trie/Trie.cpp \
	Tests/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp \
	Tests/Main.cpp \
	Tests/ValidityChecks/ValidityChecks.cpp

PATH_TO_ROOT = ../

ALL_FILES = \
	$(addprefix $(PATH_TO_ROOT), $(SOURCE_FILES)) \
	$(addprefix $(PATH_TO_ROOT), $(TEST_FILES))

OBJECT_FILES = $(ALL_FILES:.cpp=.o)

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
