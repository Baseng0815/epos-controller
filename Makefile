CC		= clang
FLAGS		=  -Wall -ggdb -I./deps -L/usr/local/lib -lEposCmd -lftd2xx
SOURCE_FILES	= $(shell find . -type f -name '*.c')

TARGET		= example

.PHONY: clean

all: $(TARGET)

$(TARGET): $(SOURCE_FILES)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJECT_FILES)
