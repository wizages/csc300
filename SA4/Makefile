SOURCE = main.cpp 

OBJS = $(SOURCE:.cpp=.o)

LINK = g++

main: $(OBJS)
	$(LINK) -o $@ $^

clean:
	rm -rf *.o *.d core main