#include<stdio.h>
#include<vector>
using namespace std;
void DFS(vector<vector<int> >& G, int visited[], int x){
	visited[x] = 1;
	for(vector<int>::iterator it = G[x].begin(); it != G[x].end(); it++)
		if(visited[*it] == 0)
			DFS(G, visited, *it);
}
int main(){
	int n;
	scanf("%d", &n);
	vector<vector<int> > G(n);
	int e;
	scanf("%d", &e);
	int x, y;
	for(int i = 0; i < e; i++){
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	//////////////////
	// Printing Graph
	//////////////////
	// for(int i = 0; i < n; i++){
	// 	for(vector<int>::iterator it = G[i].begin(); it != G[i].end(); it++)
	// 		printf("%d ", *it);
	// 	printf("\n");
	// }
	scanf("%d%d", &x, &y);
	int visited[n];
	for(int i = 0; i < n; i++)
		visited[i] = 0;
	DFS(G, visited, x);
	for(int i = 0; i < n; i++)
		printf("%d ", visited[i]);
	printf("\n");
	return 0;
}