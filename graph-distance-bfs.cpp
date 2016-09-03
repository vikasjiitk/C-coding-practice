#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
# define MAX 10000000
void BFS(vector<vector<int> >& G, int x, int distance[]){
	queue<int> Q;
	Q.push(x);
	int v;
	while(!Q.empty()){
		v = Q.front();
		for(vector<int>::iterator it = G[v].begin(); it != G[v].end(); it++)
			if(distance[*it] == MAX){
				distance[*it] = distance[v]+1;
				Q.push(*it);
			}
		Q.pop();
	}
	return;
}
using namespace std;
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
	scanf("%d", &x); //node from distance to be measured
	int distance[n];
	for(int i = 0; i < n; i++)
		distance[i] = MAX;
	distance[x] = 0;
	BFS(G, x, distance);
	for(int i = 0; i < n; i++)
		printf("%d ", distance[i]);
	printf("\n");
	return 0;
}