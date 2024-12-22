#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int val){
			data = val;
			next = NULL;
		}
};

class Stacks{
	public:
		Node *top;
		int size;
		int count;
		
		Stacks(int n){
			size = n;
			count = 0; //count isliae krrahe coz top is always head and not the last node
			top = NULL;
		}
		
		void push(int val){
			if(isFull()){
				cout << "Stack is already full" << endl;
			}
			else{
				Node *n = new Node(val);
				n->next = top; 
				top = n;
				count++;
				cout << val << " added to the top of the stack" << endl;
			}
		}
		
		void peek(){
			if(top == NULL){
				cout << "Stack is empty" << endl;
			}
			else{
				cout << top->data << endl; // top is head node and this outputs head ka data/val
			}
		}
		
		bool isFull(){
			if(count == size){
				cout << "Stack is full" << endl;
				return true;
			}
			else{
				cout << "Stack is not full" << endl;
				return false;
			}
		}
		void pop(){
			if(isEmpty()){
				cout<<"Stack is already empty"<<endl;
			}
			else{
				top=top->next; // top/head becomes andar wala node(the one below the initial top/head) and jispae phailae(initial) tha pops
			}
		}
		bool isEmpty(){
			if(top==NULL){
				cout<<"Stack is empty"<<endl;
				return true;
			}
			else{
				cout<<"Stack is not empty"<<endl;
				return false;
			}
		}
};

int main(){
	Stacks s1(5); 
	s1.pop();
	s1.peek();
	s1.push(3);
	s1.pop();
	s1.push(8);
	s1.peek();
	s1.push(12);
	s1.push(17);
	s1.push(4);
	s1.peek();
}

