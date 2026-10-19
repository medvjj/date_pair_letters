CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
TARGET = date_pair_letters
SOURCE = date_pair_letters.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean
