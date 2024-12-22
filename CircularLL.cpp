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
	cout<<"Inserted"<<endl;
}

//Insert at Start Function
void insertStart(int val)
{
	Node *n = new Node(val);
	if (head == NULL){
		head = n;
		tail = n;
		tail->next = head;
		return;
	}
	n->next = head;
	head = n;
	tail->next = head;
}

//Insert After Function
void insertAfter(int pos, int val)
{
	Node *n = new Node(val);
	Node *curr;
	curr = head;
	for(int i=1;i<pos;i++)
	{
		curr = curr->next;
	}
	n->next = curr->next;
	curr->next = n;
	if (curr == tail){
		tail = n;
	}
	
	cout<<"Inserted after Position"<<endl;
}

//Searching Function
bool Search(int key)
{
	Node *temp = head;
	if (head == NULL)
	{
		return false;
	}
	do{
		if(temp->data == key)
		{
			cout<<"Found"<<endl;
			return true;
		}
		temp = temp->next;
	}	
		while(temp != head);
	cout<<"Not Found"<<endl;
	return false;
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
	Node *curr=head;
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

int main()
{
	Circular cll;
	cll.insertTail(14);
	cll.insertStart(12);
	cll.insertAfter(1, 13);
	cll.Display();
	cll.Search(12);
	cll.deletePosition(1);
	cll.Display();

	return 0;
	
}
