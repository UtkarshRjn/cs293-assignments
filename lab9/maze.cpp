#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include"maze.h"
using namespace std;

Maze::Maze(int rows, int cols){
	N = rows;
	M = cols;
	cout << "Maze of size " << N << "x" << M << " constructed" << endl;
}

void Maze::construct_Hgrid(){
	cout << "Enter the horizontal grid: " << endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<M-1;j++){
			cin >> horizontal_grid[i][j];
		}
	}
}

void Maze::construct_Vgrid(){
	cout << "Enter the vertical grid: " << endl;
	for(int i=0;i<N-1;i++){
		for(int j=0;j<M;j++){
			cin >> vertical_grid[i][j];
		}
	}
}

void Maze::print_maze(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M-1;j++){
			if(horizontal_grid[i][j] == 1) cout << "__ ";
			else cout << "   ";
		}
		cout << endl;
	}
}

void Maze::construct_graph(){
	for(int i=0;i<N-1;i++){
		for(int j=0;j<M-1;j++){
			if(horizontal_grid[i][j]==0 && i > 0) adj[i*(M-1)+j].push_back((i-1)*(M-1)+j);					
			if(horizontal_grid[i+1][j]==0 && i < N-2) adj[i*(M-1)+j].push_back((i+1)*(M-1)+j);

			if(vertical_grid[i][j]==0 && j>0) adj[i*(M-1)+j].push_back(i*(M-1)+j-1);
			if(vertical_grid[i][j+1]==0 && j < M-2) adj[i*(M-1)+j].push_back(i*(M-1)+j+1);		
		}
	}
	cout << "Graph Constructed Successfully!!!" << endl;
}

void Maze::find_shortest_path(){
	int V = (N-1)*(M-1);
	bool *visited = new bool[V];
	int *level = new int[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	int s = 0;
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	level[s] = 0;

	list<int>::iterator i;

	while(!queue.empty()){
		s = queue.front();
		// cout << s << " -> ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                level[*i] = level[s] + 1;
            }
            // cout << *i << "(" << level[*i] << ")" << " ";
        }
        // cout << endl;
	}

	stack<int> path;
	s = (N-1)*(M-1)-1;
	path.push(s);
	for(i = adj[s].begin(); i != adj[s].end();i++){
		if(level[*i] == level[s]-1){
			path.push(*i);
			s = *i;
			i = adj[s].begin();
			i--;
		}
	}

	while(!path.empty()){
		int x = path.top();
		path.pop();
		if(!path.empty()) cout << '(' << x/(M-1) << ',' << x%(M-1) << ") -> "; 
		else  cout << '(' << x/(M-1) << ',' << x%(M-1) << ")"; 
	}
	cout << endl;
}

int main(){
	
	int rows,cols;
	cout << "Enter Number of Rows(N): ";
	cin >> rows;
	cout << "Enter Number of Columns(M): ";
	cin >> cols;	

	// Part-1
	Maze my_maze(rows,cols);
	my_maze.construct_Hgrid();
	my_maze.construct_Vgrid();
	
	// Part-2
	my_maze.construct_graph();
	// my_maze.print_maze();

	// Part-3
	my_maze.find_shortest_path();
}