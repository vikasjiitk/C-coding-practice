#include<stdio.h>
typedef long long ll;
int local(ll a[], ll mid, ll n){
	if(mid == 0 || mid == n-1)
		return 1;
	else if(a[mid-1] > a[mid] && a[mid+1] > a[mid])
		return 1;
	else return 0;
}
int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for (ll i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	int find = 0;
	ll low = 0, high = n-1, mid;
	while(!find){
		mid = (low+high)/2;
		if (local(a, mid, n))
			find = 1;
		else{
			if(a[mid-1]<a[mid])
				high = mid-1;
			else
				low = mid+1;
		}
	}
	printf("%lld\n", a[mid]);
}