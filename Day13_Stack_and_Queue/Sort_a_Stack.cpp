#include <bits/stdc++.h> 
void putMax(stack<int> &stack){
	if(stack.size() == 1){
		return;
	}
	int u = stack.top();
	stack.pop();
	putMax(stack);
	if(stack.top() > u){
		swap(u, stack.top());
	}
	stack.push(u);
}
void sortStack(stack<int> &stack)
{
	if(stack.size() == 1){
		return;
	}
	putMax(stack);
	int u = stack.top();
	stack.pop();
	sortStack(stack);
	stack.push(u);
	return;
}
