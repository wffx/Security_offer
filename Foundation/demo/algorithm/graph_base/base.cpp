#include "base.h"

node::node(int n)
{
	mynum = n;
}

node::node()
{
	mynum = -1;
}

void node::addedge(int endum, int len)
{
	edge side(endum, len);
	vedge.push_back(side);
}

void node::addedge(int my, int end, int len)
{
	mynum = my;
	vedge.push_back(edge(end, len));
}

void node::print()
{
	if (vedge.size() == 0) {
		cout << "There is no edge from " << mynum << endl;
		return;
	}
	  
	cout << "From node " << mynum << ":  " ;
	for (unsigned int i = 0; i < vedge.size(); ++i) {
		cout << '(' << vedge[i].endnum << ':' << vedge[i].len << "),  ";
	}
	cout << endl;
}

edge::edge()
{
	endnum = -1;
	len = -1;
}

edge::edge(int e, int l)
{
	endnum = e;
	len = l;
}
