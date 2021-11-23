#include<iostream>
#include<vector>
#include<list>
#include"graph.h"

using namespace std;

void Graph::addEdge(int u, int v){
	adj[v].push_back(u);
	adj[u].push_back(v);
}

bool Graph::existEdge(int u, int v){
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end();++i){
		if(*i == u){
			return true;
		}
	}
	return false;
}

Graph::Graph(){
	srand(time(0));
	N = rand()%5 + 6;
	cout << "Graph with " << N << " nodes constructed." << endl;
	for(int i=1;i<N;i++){
		visited[i] = false;
	}
	cout << endl;
	cout << "Edges: " << endl;
	for(int i=0;i<2*N;i++){
		int u = rand()%N + 1;
		int v = u;
		// cout << "hey" << endl;
		while(v == u){
			// cout << v << endl;
			v = rand()%N + 1;
		}
		if(!existEdge(u,v)){ 
			addEdge(u,v); 
			cout << u << "---" << v << endl;
		}else{
			i--;
		}
	}

}

void Graph::mySearch(SearchType t, int s){
	
	if(t == BFS){
		cout << "BSF at node " << s << " : ";
	}
	else if(t == DFS){
		cout << "DSF at node " << s << " : ";
	}

	S.push_back(s);
	while(!S.empty()){
		int y;
		if(t == BFS){
			y = S.front();
			S.pop_front();
			cout << y << " ";
		}else if(t == DFS){
			y = S.back();
			S.pop_back();
			cout << y << " ";
		}

		list<int>::iterator i;
		for(i = adj[y].begin(); i != adj[y].end();++i){
			if(visited[*i] == false){
				visited[*i] = true;
				S.push_back(*i);
			}
		}
	}
}

bool Graph::colorGraph(int pos, int* color, int c){

	if(color[pos] != -1 && color[pos] != c)
		return false;
	
	cout << pos << " " << c << endl;
	color[pos] = c;
    bool no_odd_cycle = true;
    list<int>::iterator i;
    for(i = adj[pos].begin(); i != adj[pos].end();++i){
        if(color[*i] == -1)
            no_odd_cycle &= colorGraph(*i,color,1-c);
             
        if(color[*i] !=-1 && color[*i] != 1-c){
            cout << pos << " ";
            return false;
        }

        if (!no_odd_cycle){
        	cout << pos << " ";
            return false;
        }
    }
     
    return true;
}


bool Graph::isBipartite(){
	int color[N+1];
	for(int i=1;i<N+1;i++)
		color[i] = -1;

	int s = 1;

	return colorGraph(s,color,1);

}

void Graph::printGraph(){
	cout << endl;	
	cout << "Adjacency List: " << endl;
	for(int i=1;i<N+1;i++){
		list<int>::iterator itr;
		cout << i << "->" ;
		for(itr = adj[i].begin();itr != adj[i].end();++itr){
			cout << *itr << " ";
		}
		cout << endl;
	}
}

int main(){
	Graph my_graph;
	my_graph.printGraph();
	my_graph.isBipartite() ? cout << "Graph is bipartite!!!" << endl : cout << "Graph is not Bipartite!!!" << endl;
}