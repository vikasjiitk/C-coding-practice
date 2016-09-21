#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int temp;
    long long n = A.size();
    sort(A.begin(), A.end());
    for(long long i = 1; i < n; i += 2){
    	temp = A[i];
    	A[i] = A[i-1];
    	A[i-1] = temp;
    }
    return A;
}
int main(){
	int n;
	int num = 1;
	scanf("%d", &n);
	vector<int> A(n);
	for(int i = 0; i < n; i++)
		A[i] = num++;
	A = wave(A);
	for(int i = 0; i < n; i++)
		printf("%d ", A[i]);
	return 0;
}