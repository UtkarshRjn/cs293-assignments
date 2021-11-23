#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<deque>
using namespace std;

enum SearchType{BFS, DFS};

class Graph{
	map<int, list<int>> adj;
	map<int, bool> visited;
	deque<int> S;
	int N; // number of nodes in the graph
public:

	Graph();

	void addEdge(int,int);
	bool existEdge(int,int);
	void mySearch(SearchType,int);
	bool isBipartite();
	bool colorGraph(int pos, int* color, int c);
	void printGraph();

};