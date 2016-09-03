#include<stdio.h>
#include<algorithm>
using namespace std;
struct Node
{
	Node *left;
	Node *right;
	int value;
};
Node *build(int a[], int low, int high){
	Node *node = new Node;
	int mid = (low+high)/2;
	node->value = a[mid];
	node->left = NULL;
	node->right = NULL;
	if(low != mid)
		node->left = build(a, low, mid-1);
	if(mid != high)
		node->right = build(a, mid+1, high);
	return node;
}
void Traversal(Node *node){
	if(node->left != NULL)
		Traversal(node->left);
	printf("%d ", node->value);
	if(node->right != NULL)
		Traversal(node->right);
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	Node *root = build(a, 0, n-1);
	Traversal(root);
	printf("\n");
	return 0;
}