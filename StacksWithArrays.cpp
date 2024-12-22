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
		int peak(){
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
		int size(){
			Stack sizestack;
			int x=0;
			do{
				sizestack.push(pop());
				x++;
			}while(!isEmpty());	
			do{
				push(sizestack.pop());
			}while(!sizestack.isEmpty());
			return x;
		}
};

int main(){
	Stack stack;
	stack.push(5);
	stack.push(3);
	stack.push(2);
	stack.push(7);
	cout << "Top element: "<<stack.peak()<<endl;
	cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is the stack full? " << (stack.isFull() ? "Yes" : "No") << endl;
    cout << "Size of stack: "<<stack.size()<<endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Size of stack: "<<stack.size()<<endl;
    return 0;	
};
