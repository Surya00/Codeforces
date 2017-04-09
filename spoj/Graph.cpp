 #include<bits/stdc++.h>
using namespace std;
class Graph{
public:
	int V;
	vector< int > *g;
    Graph(int a);
    void readGraph(Graph G);
    void addEdge(Graph G,int a, int b);
    int degree(Graph G,int V);
    int maxDegree(Graph G);
    int  numberOfSelfLoop(Graph G);

};

 Graph:: Graph(int a){
 	this->V=a;
    vector< int > A[a+1];
    this->g= A;
 }
void Graph:: readGraph(Graph G){
       int E;
       cout<<"Enter the no of Edges";
       cin>>E;
       int a,b;

       for (int i= 0; i<E; i++)
       {
       	   cin>>a>>b;
       	   G.addEdge(G,a,b);
       }
 }

 void Graph:: addEdge(Graph G, int a,int b){
     g[a].push_back(b);
     cout<<"First added";
     g[b].push_back(a);
     cout<<"edge succesfully added\n";
 }

 int Graph:: degree(Graph G,int v){
 	int degree= 0;
 	for (int i =0; i<G.g[v].size(); i++)
 	{
 		degree++;
 	}
 	return degree;
 }

 int Graph:: maxDegree(Graph G){
 	int max=0;
 	for (int i = 1; i <=G.V; i++)
 	{
 		if(max>degree(G,i)){
 			max= degree(G,i);
 		}
 	}
 }

 int Graph:: numberOfSelfLoop(Graph G){
 	int count=0;
 	for(int v=1; v<G.V; v++){
 		for (int i = 0; i <=G.g[v].size(); ++i)
 		{
 	                if(v==G.g[v][i]){
 	                	count++;
 	                }
 		}
 	}
 	return count ;
 }

 int main()
 {
    int a,b,n,m,i,j,k,l;
    cout<<"no of Vertices";
    cin>>n;
    Graph G(n);
    G.readGraph(G);
    cout<<G.degree(G,3);
 	return 0;
 }


