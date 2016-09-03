#include<stdio.h>
typedef long long ll;
#define MOD 1000000007
void pow(ll A[2][2], ll n){
	if(n == 0){
		A[0][0] = 1;
		A[0][1] = 0;
		A[1][0] = 0;
		A[1][1] = 1;
		return;
	}
	pow(A, n/2);
	ll temp[2][2];
	temp[0][0] = A[0][0];
	temp[0][1] = A[0][1];
	temp[1][0] = A[1][0];
	temp[1][1] = A[1][1];

	for(int i = 0; i < 2; i++)
		for (int j = 0; j < 2; ++j)
		{
			A[i][j] = 0;
			for(int k = 0; k < 2; k++){
				// A[i][j] = A[i][j] + temp[i][k]*temp[k][j];
				// printf("%lld\n", A[i][j]);
				// printf("%lld %lld %lld ", A[i][j]%MOD, temp[i][k]%MOD, temp[k][j]%MOD);
				A[i][j] = (A[i][j]%MOD + ((temp[i][k]%MOD)*(temp[k][j]%MOD))%MOD)%MOD;
				// printf("%lld\n", A[i][j]);
			}
		}

	if(n&1){
		ll temp2[2][2];
		temp[0][0] = 1;
		temp[0][1] = 1;
		temp[1][0] = 1;
		temp[1][1] = 0;
		temp2[0][0] = A[0][0];
		temp2[0][1] = A[0][1];
		temp2[1][0] = A[1][0];
		temp2[1][1] = A[1][1];
		for(int i = 0; i < 2; i++)
			for (int j = 0; j < 2; ++j)
			{
				A[i][j] = 0;
				for(int k = 0; k < 2; k++){
					// A[i][j] = A[i][j] + temp[i][k]*temp2[k][j];
					// printf("%lld\n", A[i][j]);
					// printf("%lld %lld %lld ", A[i][j]%MOD, temp[i][k]%MOD, temp2[k][j]%MOD);
					A[i][j] = (A[i][j]%MOD + ((temp[i][k]%MOD)*(temp2[k][j]%MOD))%MOD)%MOD;
					// printf("%lld\n", A[i][j]);
				}
			}
	}
}
int main(){
	ll n;
	scanf("%lld", &n);
	ll A[2][2] = {{1, 1},{1, 0}};
	// printf("%lld\n", A[1][1]);
	pow(A, n-1);
	printf("%lld\n", A[0][0]);
}