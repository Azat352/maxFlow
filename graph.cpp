#include "graph.h"
#include <queue>

void Graph::print()
{
	for(auto i : _cMatrix)
	{			
		for(auto e : i)
			std::cout << e << " ";
		std::cout << std::endl;
	}
}

void Graph::addEdge(int v, int u, int capacity)
{
	_cMatrix[v][u]  =  capacity;
}


Graph Graph::makeResGraph()
{
	Graph res(_size);
	for(auto i = 0; i < _size; ++i)
		for(auto j = 0; j < _size; ++j)
		{
			if(_cMatrix[i][j] != 0)
			{
				res.addEdge(i, j, _cMatrix[i][j] - _fMatrix[i][j]);
				res.addEdge(j, i, _fMatrix[i][j]);
			}
		}
	return res;
}


void Graph::addFlow(int v, int u, int val)
{
	if(val < _cMatrix[v][u])
		_fMatrix[v][u] = val;
}

void Graph::printFlowM()
{
	for(auto i : _fMatrix)
	{
		for(auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}
}


void Graph::addToFlow(int v, int u, int val)
{
	if(_fMatrix[v][u] + val <= _cMatrix[v][u])
		_fMatrix[v][u] += val;
	if(_cMatrix[v][u] == 0)
		_fMatrix[u][v] += val;
}	

std::vector<int> Graph::findPath()
{
	std::vector<int> path;
	
 	matrix &g = _cMatrix;
	std::queue<int> q;
	q.push(0);
	std::vector<bool> isUsed(_size);
	std::vector<int> d(_size), p(_size);
	isUsed[0] = true;
	p[0] = -1;
	while(!q.empty()) 
	{
		int cur = q.front();
		q.pop();
		for(auto i = cur; i < _size; ++i) 
		{
			if(g[cur][i] > 0)
			{
				int neig = i;
				if(!isUsed[neig]) 
				{
					isUsed[neig] = true;
					q.push(neig);
					d[neig] = ++d[cur];
					p[neig] = cur;
				}
			}
		}
	}
	if(!isUsed[_size - 1])
		return path;
	else
	{
		for(auto i = _size-1; i != -1; i = p[i])
			path.push_back(i);
		std::reverse(path.begin(), path.end());
		return path;
	}
}


int Graph::edgeVal(const int i, const int j)
{
	return _cMatrix[i][j];
}

int Graph::totalF()
{
	int sum = 0;
	for(auto i = 0; i < _size; ++i)
		sum += _fMatrix[0][i];
	return sum;
}
