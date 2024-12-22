#include <iostream>
using namespace std;
class Stack{
	private:
		int arr[5];
		int top;
	public:
		Stack(){
			top=0;
		}
		int peek(){
			if(top>0){
				return arr[top-1];
			}
		}
		bool isFull(){
			if(top==5){
				return true;
			}
			else {
				return false;
			}
		}
		bool isEmpty(){
			if(top==0){
				return true;
			}
			else{
				return false;
			}
		}
		void push(int i){
			if(isFull()){
				cout<<"Stack is full"<<endl;
			}
			else{
				arr[top]=i ;
				top++;
			}
		}
		int pop(){
			if(isEmpty()){
				cout<<"Sorry no element"<<endl;
			}
			else{
				top--;
				return (arr[top]);
			}
		}
};

int main(){
	Stack stack;
	Stack temp;
	Stack result;
	stack.push(5);
	stack.push(3);
	stack.push(2);
	while(!(stack.isEmpty())){
    	int max=stack.peek();
    	while(!(stack.isEmpty()))
		{
    		if(stack.peek()>max)
			{
    			max=stack.peek();
			}
			temp.push(stack.peek());
			stack.pop();
		}
		while(!(temp.isempty()))
		{
			if(temp.peek()==max)
			{
				result.push(max);
				temp.pop(); 
			}
			else 
			{
				stack.push(temp.peek());
				temp.pop();
			}
		}
	}	
};
