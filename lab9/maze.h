#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Maze{
	int N;
	int M;
	int horizontal_grid[1000][1000];
	int vertical_grid[1000][1000];
	list<int> adj[1000];
	// vector<vector<int>> horizontal_grid( N , vector<int>(M-1));
	// vector<vector<int>> vertical_grid(N-1,vector<int>(M));

	public:

		Maze(int,int);

		void construct_Hgrid();
		void construct_Vgrid();
		void print_maze();
		void construct_graph();
		void find_shortest_path();
};
