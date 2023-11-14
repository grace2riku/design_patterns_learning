targets = singleton_simple.app
OBJS := Singleton.o main.o

$(targets): $(OBJS)
	g++ $(OBJS) -o $(targets)

.cpp.o:
	g++ -std=c++11 -c $<

Singleton.o: Singleton.cpp Singleton.h
main.o: main.cpp

.PHONY: clean
clean:
	rm -f $(targets) $(OBJS)