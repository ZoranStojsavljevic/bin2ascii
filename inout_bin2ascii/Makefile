######################
# bin2ascii Makefile #
######################

TARGET = bin2ascii
CC = gcc
CPPFLAGS += -Wall
CPPFLAGS += -O3
PROGSIZE = size

$(TARGET): $(TARGET).o
	@echo "$(TARGET).o -> $(TARGET)"
	@$(CC) $(TARGET).o -lm -o $(TARGET)
	@$(PROGSIZE) $(TARGET)

$(TARGET).o: $(TARGET).c
	@echo "$(TARGET).c -> $(TARGET).o"
	@$(CC) $(CFLAGS) -c $(TARGET).c
	@$(PROGSIZE) $(TARGET).o

clean:
	@rm -f $(TARGET) $(TARGET).o

