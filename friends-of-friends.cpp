#include<stdio.h>
#include<set>
using namespace std;
int main(){
	set<int> a;
	int n,n2;
	scanf("%d", &n);
	n2 = n;
	int fr[n], m, ffr;
	while(n--){
		scanf("%d", &fr[n]);
		scanf("%d", &m);
		while(m--){
			scanf("%d", &ffr);
			a.insert(ffr);
		}
	}
	for(int i = 0; i < n2; i++)
		a.erase(fr[i]);
	int size = a.size();
	printf("%d\n", size);
}