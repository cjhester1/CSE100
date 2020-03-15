#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

/*
 I received help on this lab from my tutor Tatiana Sluus from varsitytutors.com tsluus55@gmail.com.. I also used
 
 this website https://www.geeksforgeeks.org/strongly-connected-components/ for help on this assignment. Tatiana
 
 walked me through the importance/significance of this lab, she explained how a strongly connected component of
 
 a graph is a max set of vertices for which every pair of vertices has a two way directed path (from a to
 
 b..from b to a) first we call DFS to get end times for vertices then we transpose our directed graph. After we
 
 call our transposed directed graph in decreasing order. Then we simply output he vertices of each tree.
 
 */

vector<int> idS;
vector<int> counter;
int arr[100];

void makeID(vector<int> V);
void print (vector<int> idS);
	
class Graph {
	private:
		int vertices;
		list < int >  *graph; 
		vector<int> V;
		int count;
		int word;
    
	public:


		Graph(int node) 
		{
			this->vertices = node;
			graph = new list < int > [vertices];
			count = word = 0;
		}

    void addEdge(int u, int v)
    {
		graph[u].push_back(v);
    }

    Graph transpose()
    {
		Graph g(vertices);

        for (int i = 0; i < vertices; i++)
        {
			list < int > ::iterator j;
			
            for (j = graph[i].begin(); j != graph[i].end(); ++j)
            {
				g.graph[ *j].push_back(i);
            }	
        }

        return g;
    }

    void fill(int v, bool visited[], stack < int >  &ST)
    {
        visited[v] = true;
        list < int > ::iterator i;

        for (i = graph[v].begin(); i != graph[v].end(); ++i)
        {
			if (!visited[ *i])
            {
                fill(*i, visited, ST);
            }
        }
        ST.push(v);
    }

	void DFS(int v, bool visited[])
	{	
		count++;
        visited[v] = true;
      	V.push_back(v);
        list < int > ::iterator i;

        for (i = graph[v].begin(); i != graph[v].end(); ++i)
        {

			if (!visited[ *i])
            {	
				DFS(*i, visited);
            }
        }
        
		if(count != 0 && word==0) 
		{
			counter.push_back(count);
			word=1;
		}
		
		makeID(V); 		
		V.clear();	
		count = 0;
		word = 0;
	
    }

    int SCCS()
    {
		stack < int > ST;
   
        bool *visited = new bool[vertices];
        
		for (int i = 0; i < vertices; i++)
		{	
			visited[i] = false;	
		}
          
        for (int i = 0; i < vertices; i++)
		{	
			if (visited[i] == false)
			{
				fill(i, visited, ST);
        	}       	
        }
     
        Graph g2 = transpose();
       
        for (int i = 0; i < vertices; i++)
		{	
			visited[i] = false;
        }
         
        int count = 0;
        int v;
        
        while (ST.empty() == false)
        {    
			v = ST.top();
            ST.pop();
             
            if (visited[v] == false)
            {	
				g2.DFS(v, visited);
               
				count++;
                
            }
            
        }
        return count;
    }
	
    void SSID()
	{
    	print(idS);	
    }

~Graph()
{
	delete [] graph;
}

};

int main()
{
	int node; 
	int edge;

	cin >> node;

	Graph g(node);

	cin >> edge;
	int u, v;
	for (int i = 0; i < edge; i++)
	{

		cin >> u;
		cin >> v;

		g.addEdge(u, v);

	}

	g.SCCS();
	g.SSID();

  return 0;
}

void makeID(vector<int> V)
{

	int temp = 0;
	int j = 0;

	for (int i = 1; i < V.size(); i++)
	{

		temp = V[i]; 
		j = i - 1;
    while (j >= 0 && V[j] > temp)
    {
		V[j + 1] = V[j]; 

		j--;
    }
   		V[j + 1] = temp;
  }
  
  
  	for(int i=0; i<V.size(); i++)
	{
		idS.push_back(V[i]);	
	}

}

void print (vector<int> idS)
{
	for(int i= 0; i< idS.size();i++)
	{
		arr[i]=-100;
	}
  
  	bool x = true;
 	int k = 0;
 	int k2 = 0;
 	int temp2;
 	int z = 0;
 	int place = idS[idS.size()]; 
 	
	while (x)
	{  	
		temp2 = idS[k2];
		z = counter[k];
  
		while (z>0)
		{
			arr[idS[k2]] = temp2;			
  			k2++;
  			z--;
  		}
  	
  		if (k2== idS.size())
		{
			x= false;
  		}
  	
  		k++;
  	
	}
 
	for(int i=0; i<idS.size(); i++)
	{
		cout<< arr[i]<<endl;  	  	
	}	
	
}
