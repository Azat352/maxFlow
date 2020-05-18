#include <iostream>
#include "graph.h"
#include "maxFlow.h"

int main()
{
	Graph g(6);
	g.addEdge(0, 1, 16);
	g.addEdge(0, 2, 13);
	g.addEdge(2, 1, 4);
	g.addEdge(1, 3, 12);
	g.addEdge(2, 4, 14);
	g.addEdge(4, 3, 7);
	g.addEdge(3, 2, 9);
	g.addEdge(3, 5, 20);
	g.addEdge(4, 5, 4);
	
	maxFlow(g);
	std::cout << "Value:" << g.totalF() << std::endl;
	std::cout << "Matrix:" << std::endl;
	g.printFlowM();
	return 0;
}
