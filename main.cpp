/* Vertex Cover */
/* Implementation of a graph and a solution to the existential vertex cover problem */

/* Given a Graph G(V,E), is there a vertex cover of size <= k where k is > 0 
	- Vertex Cover - a subset of V such that at least one endpoint of each edge of G is present in VC.
	- NP- Complete
*/
#include<iostream>
#include "Graph.cpp"
#include "VertexCover.cpp"
using namespace std;



int main(){
	Graph* g = new Graph(12);
	g->insertEdge(0,1);
	g->insertEdge(0,8);
	g->insertEdge(0,9);
	
	g->insertEdge(1,2);
	g->insertEdge(1,11);
	g->insertEdge(3,4);
	g->insertEdge(0,11);
	g->insertEdge(4,5);
	g->insertEdge(4,11);
	g->insertEdge(4,10);
	g->insertEdge(5,6);
	g->insertEdge(6,10);
	g->insertEdge(6,7);
	g->insertEdge(8,10);
	g->insertEdge(9,10);
	g->insertEdge(10,11);
	//g->insertEdge(0,4);
	//g->insertEdge(1,2);
	//g->insertEdge(2,3);
	g->displayAdjacencyMatrix();
	g->displayEdges();
	VertexCover* v = new VertexCover(g,8);
	v->displayEdges();
	v->vertexCoverExistence();
	
}
