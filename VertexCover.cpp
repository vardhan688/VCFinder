#include<bits/stdc++.h>
using namespace std;

class VertexCover{
	public:
	Graph* inputGraph;
	vector<int> vertexSet;
	vector<Edge> edgeSet;
	int K;
	bool flag;

	VertexCover(Graph* g,int k=0){
		inputGraph = g;
		for(int i=0;i<g->V;i++){
			vertexSet.push_back(i);
		}
		edgeSet = g->edgeList;
		K = k;
		flag = false;
	}

	void setK(int k){
		K = k;
	}


	bool isVertexCover(vector<int> vc){
		bool isCovered[edgeSet.size()];
		for(int i=0;i<vc.size();i++){
			for(int j=0;j<edgeSet.size();j++){
				if(vc[i]==edgeSet[j].u || vc[i]==edgeSet[j].v){
					isCovered[j] = true;
				}
			}
		}
		
		for(int j=0;j<edgeSet.size();j++){
			if(!isCovered[j]) return false;
		}
		return true;
		
	}

	void vertexCoverSolve(vector<int> vc,int k){
		if(k>K){
			return;
		}
		if(isVertexCover(vc) && k<=K){
			flag =  true;
			return;
		}
		k = k+1;
		vector<int> vc1 = vc;
		vc1.push_back(vertexSet[k]);
		vertexCoverSolve(vc1,k);

		vector<int> vc2 = vc;
		int k2 = vc2.size();
		for(int i=0;i<inputGraph->V;i++){
			if(inputGraph->graph[k][i]==1){
				vc2.push_back(i);
				k2++;
			}
		}
		vertexCoverSolve(vc2,k2);
	}

	void vertexCoverExistence(){
		if(K==0){
			cout<<"No vertex cover of this size..\n";
		}
		vector<int> vc;
		vertexCoverSolve(vc,0);	
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";	
	}

	void displayEdges(){
		for(int i=0;i<edgeSet.size();i++){
			cout<<edgeSet[i].u<<"---"<<edgeSet[i].v<<"\n";
		}
	}
};
