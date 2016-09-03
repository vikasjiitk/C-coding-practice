#include<stdio.h>
typedef long long ll;
int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for(ll i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll ele, count = 0;
	for(ll i = 0; i < n; i++){
		if(count == 0){
			ele = a[i];
			count = 1;
		}
		else{
			if(a[i] == ele)count++;
			else count--;
		}
	}
	count = 0;
	for(ll i = 0; i < n; i++)
		if(a[i] == ele)
			count++;
	if(count > n/2)printf("%lld\n", ele);
	else printf("No\n");
}