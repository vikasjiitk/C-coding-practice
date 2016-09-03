#include<stdio.h>
int count_Inv(int a[], int low, int high){
	if(low == high)
		return 0;
	int mid = (low+high)/2;
	int count1 = count_Inv(a, low, mid);
	int count2 = count_Inv(a, mid+1, high);
	int c[high-low+1];
	int mark1 = low;
	int mark2 = mid+1;
	int conquer = 0;
	int i;
	for(i = 0; i <= high-low; i++){
		if(mark1 <= mid && mark2 <= high && a[mark1] <= a[mark2]){
			c[i] = a[mark1];
			mark1++;
		}
		else if(mark1 <= mid && mark2 <= high && a[mark1] > a[mark2]){
			c[i] = a[mark2];
			mark2++;
			conquer += mid - mark1 + 1;
		}
		else
			break;
	}
	for(;i <= high-low; i++){
		if(mark1 > mid){
			c[i] = a[mark2];
			mark2++;
		}
		else{
			c[i] = a[mark1];
			mark1++;
		}
	}
	for(i = low; i <= high; i++)
		a[i] = c[i-low];
	return conquer+count1+count2;
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int countInversion = count_Inv(a, 0, n-1);
	printf("%d\n", countInversion);
}