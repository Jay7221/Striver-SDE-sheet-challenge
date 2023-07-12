#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		
		// Constructor
		stack<int> st, st_min;
		int n;
		minStack() 
		{ 
			n = 0;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			int mn = num;
			if(n > 0){
				mn = min(mn, st_min.top());
			}
			st.push(num);
			st_min.push(mn);
			++n;
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			int res = -1;
			if(n > 0){
				--n;
				res = st.top();
				st.pop();
				st_min.pop();
			}
			return res;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			int res = -1;
			if(n > 0){
				res = st.top();
			}
			return res;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			int res = -1;
			if(n > 0){
				res = st_min.top();
			}
			return res;
		}
};
