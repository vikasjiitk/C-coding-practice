#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
bool myfunction(Interval I1, Interval I2){
	return I1.start <= I2.start;
}
vector<Interval> merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), myfunction);
    long long n = A.size();
    vector<Interval> B;
    for(long long i = 0; i < n;){
    	int left = A[i].start;
    	int right = A[i].end;
    	while(i<n && A[i].start <= right){
    		right = max(A[i].end, right);
    		i++;
    	}
    	Interval I;
    	I.start = left;
    	I.end = right;
    	B.push_back(I);
    }
    return B;
}

int main(){
	int n;
	int num = 1;
	scanf("%d", &n);
	vector<Interval> A(n);
	for(int i = 0; i < n; i++){
		A[i].start = num++;
		A[i].end = num+2;
	}
	for(int i = 0; i < A.size(); i++)
		printf("%d %d\n", A[i].start, A[i].end);
	vector<Interval> B;
	B = merge(A);
	for(int i = 0; i < B.size(); i++)
		printf("%d %d\n", B[i].start, B[i].end);
	return 0;

}