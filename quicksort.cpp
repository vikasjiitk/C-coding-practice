#include<stdio.h>
void swap(int a[], int x, int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
int partition(int a[], int low, int high){
	int pos = high;
	int mark = low;
	while(mark != pos){
		if(a[pos-1] >= a[pos]){
			swap(a, pos-1, pos);
			pos = pos - 1;
		}
		else{
			swap(a, mark, pos-1);
			mark++;
		}
	}
	return pos;
}
void Quicksort(int a[], int low, int high){
	if(low < high){
		int pos = partition(a, low, high); //taking a[high] to be the pivot element
		if(pos-1 >= low)
			Quicksort(a, low, pos-1);
		if(pos+1 <= high)
			Quicksort(a, pos+1, high);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Quicksort(a, 0, n-1);
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}