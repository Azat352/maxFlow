#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Graph
{
typedef std::vector<std::vector<int>> matrix;
public:
	Graph(const int n)
	: _size(n), _cMatrix(n, std::vector<int>(n)), 
	_fMatrix(n, std::vector<int>(n)) {}
	void addEdge(int v, int u, int capacity);
	Graph makeResGraph();
	void addToFlow(int v, int u, int val);
	void addFlow(int v, int u, int val);
	std::vector<int> findPath();
	int edgeVal(const int i, const int j);
	void print();
	void printFlowM();
	int totalF();
private:
	size_t _size;
	matrix _cMatrix;
	matrix _fMatrix; 
};



#endif
