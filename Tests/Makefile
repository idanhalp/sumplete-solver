COMPILER = g++

CPP_STANDARD = -std=c++23

WARNING_FLAGS = -Wall -Wextra -pedantic -Werror

SANITIZER_FLAGS = -fsanitize=address,undefined,signed-integer-overflow,bounds

OPTIMIZATION_LEVEL = -O0

LINK_TIME_OPTIMIZATION = #-flto

PATH_TO_ROOT = ../../
INCLUDE_PATH = -I$(PATH_TO_ROOT)

COMPILER_FLAGS = $(CPP_STANDARD) $(WARNING_FLAGS) $(SANITIZER_FLAGS) $(OPTIMIZATION_LEVEL) $(INCLUDE_PATH)

SOURCE_FILES = \
	Backend/Source/Algorithm/Version1/Algorithm.cpp \
	Backend/Source/Algorithm/Version2/Algorithm.cpp \
	Backend/Source/Algorithm/Version2/Utils/Trie/Trie.cpp \
	Backend/Source/Algorithm/Version2/Utils/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp \
	Backend/Source/ValidityChecks/ValidityChecks.cpp

TEST_FILES = \
	Backend/Tests/Algorithm/Algorithm.cpp \
	Backend/Tests/Algorithm/Version2/Trie/Trie.cpp \
	Backend/Tests/Algorithm/Version2/ValidSubsetsGeneration/ValidSubsetsGeneration.cpp \
	Backend/Tests/Main.cpp \
	Backend/Tests/ValidityChecks/ValidityChecks.cpp


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
