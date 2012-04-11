#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <list>


class directedGraph;
class DGNode;

class directedGraph{
	typedef std::list<DGNode> Nodes;
	Nodes nodes;
public:
	directedGraph(){}
	void pushNode(const DGNode& src) { nodes.push_back(src); }

};


int main(int,char**){

	return 0;
}
