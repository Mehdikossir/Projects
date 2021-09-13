CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++11 -pthread
INCLUDES=../includes
TARGET = ../bin/main

OBJS = main.o EquationDeLaChaleur.o Vector.o Materiau.o EquationDeLaChaleur1D.o EquationDeLaChaleur2D.o
all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

 %.o: %.cpp $(INCLUDES)%.h
	$(CC) $(CPPFLAGS) $< -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
