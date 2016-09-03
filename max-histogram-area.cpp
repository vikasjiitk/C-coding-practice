#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	long long int a[100005];
	while(1){
		int n = 0;
		char ch;
		do{
		scanf("%lld", &a[n++]);
		ch = getchar();
		}while(ch!='\n');
		if(n == 1 && a[0] == 0)
			break;
		stack<int> s;
		long long int maxarea = 0, area;
		// s.push(a[0]);
		for(int i = 0; i < n;){
			if( s.empty() || a[i] > a[s.top()])
				s.push(i++);
			else{
				int bar = s.top();
				s.pop();
				area = a[bar]*(s.empty()?i:i-s.top()-1);
				if(area > maxarea)
					maxarea = area;
			}
		}
		int size = s.top()+1;
		while(s.empty() != 1){
			int bar = s.top();
			s.pop();
			area = a[bar]*(s.empty()?size:size-s.top()-1);
			if(area > maxarea)
				maxarea = area;
		}
		printf("%lld\n", maxarea);
	}
	return 0;
}