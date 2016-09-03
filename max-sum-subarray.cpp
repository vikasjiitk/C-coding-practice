#include<stdio.h>
typedef long long ll;
ll max(ll s[], ll n){
	ll max = s[0];
	ll pos = 0;
	for( ll i = 1; i < n; i++)
		if(s[i] > max){
			max = s[i];
			pos = i;
		}
	return pos;
}
int main(){
	ll n;
	scanf("%lld", &n);
	ll a[n];
	for(ll i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll s[n], index[n];
	s[0] = a[0];
	index[0] = 0;
	for(ll i = 1; i < n; i++){
		if(s[i-1] > 0){
			s[i] = a[i]+s[i-1];
			index[i] = index[i-1];
		}
		else{
			s[i] = a[i];
			index[i] = i;
		}
	}
	ll pos = max(s, n);
	for(ll i = index[pos]; i <= pos; i++)
		printf("%lld ", a[i]);
	printf("\n");

}
