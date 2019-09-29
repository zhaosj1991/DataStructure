SRC = test.cpp
OBJ = $(SRC:%.cpp=./%.o)

CFLAG = -std=c++11

%.o : %.cpp
	g++ -c -o $@ $^ $(CFLAG)

test: $(OBJ)
	g++ -o $@ $^ $(CFLAG) 

clean:
	@rm -rf test *.o