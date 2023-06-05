CC		= gcc
FLAGS		= -I./deps -lEposCmd -lftd2xx -Wall -ggdb
SOURCE_FILES	= $(shell find . -type f -name '*.c')
OBJECT_FILES	= $(SOURCE_FILES:.c=.o)

TARGET		= example

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECT_FILES)
