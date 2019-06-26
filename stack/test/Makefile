HOME := ..

TARGET := test

CC := g++
LD := g++

INC := -I. -I..
CPPFLAG :=
LDFLAG :=

SRC := $(shell find $(HOME) -name "*.cpp")
OBJ := $(SRC:%.cpp=%.o)

%.o : %.cpp
	$(CC) $(INC) $(CPPFLAG) -c -o $@ $<

$(TARGET): $(OBJ)
	$(LD) $(LDFLAG) -o $@ $^

.PHONY: clean

clean: 
	rm -f $(OBJ) $(TARGET)