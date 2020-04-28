#include<iostream>
#include<vector>
using namespace std;

class Edge{
	public:
	int u;
	int v;
	double weight;

	Edge(int u1,int v1){
		u = u1;
		v = v1;
		weight = 0;
	}
};

/*Undirected graph class
	- contains adjacency Matrix
	- Degree of each vertex
	- No. of vertices
	- No. of edges
	- List of edges*/
class Graph{
	public:
	int **graph; //Adjacency Matrix
	int V;
	int E;
	int* degree;
	vector<Edge> edgeList;


	Graph(int vertices){
		/*Initialising vertices and graph size*/
		V = vertices;
		E = 0;
		degree = new int[V];
		graph = new int*[V];
		for(int i=0;i<V;i++){
			graph[i] = new int[V];
		}
	
		/*Initialising graph with no edge i.e. Empty Graph*/
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				graph[i][j]=0;
			}
			degree[i] = 0;
		}
	}


	/*Insert new Edge and update degree*/
	int insertEdge(int u,int v){
		if(graph[u][v] != 1 && graph[v][u] != 1){
			graph[u][v] = 1;
			graph[v][u] = 1;
			E++;
			degree[u]++;
			degree[v]++;
			Edge e(u,v);
			edgeList.push_back(e);
		}
	}

	/*Adjacency matrix displayed in rows and columns
		- Only one cell is updated i.e. if edge is (u,v) then only [u][v] is declared as 1, not [v][u]*/
	void displayAdjacencyMatrix(){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				cout<<graph[i][j]<<" ";
			}
			cout<<"\n";
		}
	}

	void displayEdges(){
		for(int i=0;i<edgeList.size();i++){
			cout<<edgeList[i].u<<"---"<<edgeList[i].v<<"\n";
		}
	}
};
