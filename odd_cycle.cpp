#include<stdio.h>
struct list{
	int node;
	list *next;
};
int main(){
	int n;
	scanf("%d", &n);
	int ne;
	scanf("%d", &ne);
	list *graph[n];
	for(int i = 0; i < n; i++)
		graph[i] = NULL;
	int x,y;
	for(int i = 0; i < ne; i++){
		scanf("%d%d", &x, &y);
		list *New = new list;
		New->node = y;
		New->next = graph[x];
		graph[x] = New;
		New = new list;
		New->node = x;
		New->next = graph[y];
		graph[y] = New;
	}
	list *Qr, *Qf;
	Qf = new list;
	Qf->node = 0;
	Qf->next = NULL;
	int distance[n];
	for(int i = 0; i < n; i++)
		distance[i] = -1;
	distance[0] = 0;
	int num_reached = 1;
	Qr = Qf;
	int odd_cycle = 0;
	while(Qf != NULL){
		int v = Qf->node;
		list *temp = graph[v];
		while(temp != NULL){
			int neigh = temp->node;
			if(distance[neigh] == -1){

				distance[neigh] = distance[v]+1;
				// printf("hi %d %d\n", neigh, distance[neigh]);
				list *temp2 = new list;
				temp2->node = neigh;
				temp2->next = NULL;
				Qr->next = temp2;
				Qr = temp2;
				num_reached ++; 
			}
			else if(distance[neigh] == distance[v]){
				odd_cycle = 1;
				// printf("bi %d %d\n", neigh, distance[neigh]);
			}
			temp = temp->next;
		}
		Qf = Qf->next;
		if(Qf == NULL && num_reached != n){
			num_reached++;
			for(int i = 0; i < n; i++)
				if(distance[i] == -1){
					distance[i] = 0;
					list *temp2 = new list;
					temp2->node = i;
					temp2->next = NULL;
					Qf = temp2;
					Qr = temp2;
					break;
				}
		}
	}
	printf("%d\n", odd_cycle);
}