#include <iostream>
#include <cstddef>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	Node (int val)
	{
		data = val;
		next = NULL;
	}
};

//Circular Linked List
class Circular{
	public:
	Node *head;
	Node *tail;
	
	Circular()
	{
		head = NULL;
		tail = NULL;
	}

//Insert at Tail Function
void insertTail(int val)
{
	Node *n = new Node(val);
	if(head == NULL)
	{
		head = n;
		tail = n;
		tail->next = head;
		return;
	}
	tail->next = n;
	tail = n;
	tail->next = head;
}

//Traversal Fucntion
void Display()
{
	Node *temp = head;
	do{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	while(temp != head);
	cout<<endl;		
}

//Deleteion from End
void deleteEnd()
{
	Node *temp = head;
	Node *pre;
	
	while(temp->next != head)
	{
		pre = temp;
		temp = temp->next;
	}
	tail = pre;
	tail->next = head;
	
	delete temp;
}

//Delete
void deleteStart()
{
    Node *temp = head;
	Node *curr=head->next;
	tail->next=curr;
	head = curr;
	delete temp;
}

void deletePosition(int pos)
{
	Node *pre;
	Node *curr;
	curr = head;
	for(int i=1;i<pos;i++)
	{
		pre=curr;
		curr=curr->next;
	}
        if (curr == head) 
		{
            deleteStart();
        } 
		else if (curr == tail) 
		{
            deleteEnd();
        } 
		else 
		{
            pre->next = curr->next;
            delete curr;
        }
}

};
void josephus(Circular c,int N,int K){
    int k=K-1;
    int pos=0;
    while(N!=1){
        pos+=k;
        c.deletePosition(pos);
        N--;
    }
    cout<<"The winner is ";
    c.Display();
}

int main()
{
	Circular cll;
    int arr[7]={1,2,3,4,5,6,7};
    int K=3;
    for(int i=0;i<7;i++){
        cll.insertTail(arr[i]);
    }
    josephus(cll,7,3);
	return 0;
	
}