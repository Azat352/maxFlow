#ifndef MAXFLOW_H
#define MAXFLOW_H
#include "graph.h"

void maxFlow(Graph &g)
{
	while(!g.makeResGraph().findPath().empty())
	{
		std::vector<int> path = g.makeResGraph().findPath();
		std::vector<int> cf;
	//	for(auto i : path)
	//		std::cout << i << " ";
	//	std::cout << std::endl;
		for(auto i = 0; i + 1 < path.size(); ++i)
			cf.push_back(g.makeResGraph().edgeVal(path[i], path[i+1]));
		int c = *std::min_element(cf.begin(), cf.end());
		for(auto i = 0; i < path.size() - 1; ++i)
			g.addToFlow(path[i], path[i + 1], c);
	}
}


#endif
