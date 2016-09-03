#include<stdio.h>
#include<map>
#include<stack>
#include<math.h>
using namespace std;

stack<int> operands;
stack<char> operators;
void evaluate(){
	int op1, op2, val;
	char op;
	op1 = operands.top();
	operands.pop();
	op2 = operands.top();
	operands.pop();
	op = operators.top();
	operators.pop();
	switch(op){
		case '+': val = op2+op1;
		break;
		case '-': val = op2-op1;
		break;
		case '*': val = op2*op1;
		break;
		case '/': val = op2/op1;
		break;
		case '%': val = op2%op1;
		break;
		case '^': val = pow(op2, op1);
		break;
	}
	operands.push(val);
}
int isdigit(char a){
	if(a >= 48 && a <= 57)
		return 1;
	else
		return 0;
}
int main(){
	char a[100];
	char ch;
	int len = 0;
	while((ch = getchar()) != '\n'){
		a[len++] = ch;
	}
	map<char, int> inprior;
	map<char, int> outprior;
	inprior['+'] = 1;
	inprior['-'] = 1;
	inprior['*'] = 2;
	inprior['/'] = 2;
	inprior['%'] = 2;
	inprior['('] = 0;
	inprior['^'] = 3;
	outprior['+'] = 1;
	outprior['-'] = 1;
	outprior['*'] = 2;
	outprior['/'] = 2;
	outprior['%'] = 2;
	outprior['^'] = 4;
	outprior['('] = 5;
	int op1, op2, val;
	char op;
	for(int i = 0; i < len; i++){
		if(isdigit(a[i])){
			operands.push(a[i]-'0');
		}
		else if(a[i] == ')'){
			while(operators.top() != '(')
				evaluate();
			operators.pop();
		}
		else{
			while(operators.empty() == 0 && inprior[operators.top()] >= outprior[a[i]])
				evaluate();
			operators.push(a[i]);
		}
	}
	while(operators.empty() == 0)
		evaluate();

	printf("%d\n", operands.top());
	return 0;
}