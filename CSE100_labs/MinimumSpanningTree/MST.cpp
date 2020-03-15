#include <iostream>
#include <limits.h>

using namespace std;

/*
Pseudocode
Initialize a min-priority queue Q.
 for all u∈V do
u.key = ∞.
u.π = NIL.
Insert (Q, u).
end for
Decrease-key(Q,r,0).
 while Q̸=∅ do
u = Extract-Min(Q).
 for all v ∈ Adj[u] do
if v ∈ Q and w(u, v) < v.key then
 v.π = u.
Decrease-Key(Q, v, w(u, v)).
 end if
end for
 end while
 */
 /*
  
  
  my tutor Tatiana Sluus from varsitytutors.com tsluus55@gmail.com helped me with this lab, as I mentioned for other labs i love when labs have pseudocode for us to follow because it makes the implementation that much easier.
  
  
  */

void min_span_tree(int key[], bool sub_span_tree[], int vertice){ // setting the minimum spanning tree.
	for(int i = 0; i < vertice; i++){//for int = 0 while i is less than vertices increment i
		key[i] = INT_MAX;
		sub_span_tree[i] = false;
	}
	
	key[0] = 0;
}


void print_span_tree(int vertice, int minWeight[]){// printing the minimum spanning tree.
	for(int i = 1; i < vertice; i++){//for int = 1 while i is less than vertices increment i
		cout << minWeight[i] << endl;//cout the min weight of each index
	}
}

int min_key(int vertice, int key[], bool sub_span_tree[]){// function to find the vertice w/ the min_key value.
	int min_index = INT_MAX;
	int ind;
	
	for(int i = 0; i < vertice; i++){
		if(sub_span_tree[i] == false && key[i] < min_index){
			min_index = key[i];
			ind = i;
		}
	}
	
	return ind;
}


void Prim(int vertice, int edges){// Prim's Minimum Spanning tree.
	
	int x, y, weight;
	int graph[vertice][vertice];
    
	
    for(int i = 0; i < vertice; i++){//initialize tree graph.
		for(int j = 0; j < vertice; j++){
			graph[i][j] = 0;
		}
	}

  for(int i = 0; i < edges; i++){//  getting edges and weights from cin
	  cin >> x;
	  cin >> y;
	  cin >> weight;
	  
	  graph[x][y] = weight;
	  graph[y][x] = weight;
  }
	
	int minWeight[vertice];
	int key[vertice];
	bool sub_span_tree[vertice];
	
	min_span_tree(key,sub_span_tree,vertice);
	

	for(int i = 0; i < vertice - 1; i++){
		int u = min_key(vertice, key, sub_span_tree);
		sub_span_tree[u] = true;
		
		for(int j = 0; j < vertice; j++){
			if(graph[u][j] && sub_span_tree[j] == false && graph[u][j] < key[j]){
				minWeight[j] = u;
				key[j] = graph[u][j];
			}
		}
	}
	
	print_span_tree(vertice, minWeight);
	
}

int main(int argc,char **argv) {
 
  int vertices = 1;
  int edges = 1;	

  cin >> vertices;
  
  cin >> edges;
  
  Prim(vertices, edges);
 
}
