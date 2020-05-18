TARGET = net
PREFIX = /usr/local/bin

.PHONY: all clean install uninstall

all: $(TARGET)

clean:
		rm -rf $(TARGET) *.o
graph.o: graph.cpp graph.h
		g++ -c -g graph.cpp -o graph.o
main.o: main.cpp graph.cpp graph.h maxFlow.h
		g++ -c -g main.cpp -o main.o 
$(TARGET): main.o graph.o
		g++ -g main.o graph.o -o $(TARGET)
install:
		install	./$(TARGET) $(PREFIX)
uninstall:
		rm -rf $(PREFIX)/$(TARGET)
