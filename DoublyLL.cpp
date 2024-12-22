#include <iostream>
#include <cstddef>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
		
		Node(int val)
		{
			data = val;
			next = NULL;
			prev = NULL;
		}
};

class Doubly{
	public:
		Node *head;
		Node *tail;
		
		Doubly()
		{
			head = NULL;
			tail = NULL;
		}

//Insert at Tail
void insertTail(int val)
{
	Node *n = new Node(val);
	if (head == NULL)
	{
		head = n;
		tail = n;
		return;
	}
	tail->next = n;
	n->prev = tail;
	tail = n;
	cout<<"Inserted "<<endl;
}

//Insert at Start
void insertStart(int val)
{
	Node *n = new Node(val);
	if (head == NULL)
	{
		head = n;
		tail = n;
		return;
	}
	n->next = head;
	head->prev = n;
	head = n;
}

//Insert After Position
void insertAfter(int pos, int val)
{
	Node *n = new Node(val);
	Node *curr = head;
	for (int i=1;i<pos;i++)
	{
		curr = curr->next;
	}
	n->next = curr->next;
	//n->prev = curr;
	if (curr->next != NULL)
	{
		curr->next->prev = n;
	}
	else
	{
		tail = n;
	}
	curr->next = n;
	n->prev = curr;
	cout<<"Inserted After"<<endl;
}

//Search Function
bool Search(int key)
{
	Node *temp = head;
    while (temp != NULL) 
	{
		if (temp->data == key) 
		{
			cout << "Found" << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Not Found" << endl;
    return false;
}

//Traversal Function
void Display() 
{
    Node *temp = head;
    while (temp != NULL) 
	{
		cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Reverse Function
void Reverse()
{
	Node *temp = NULL;
	Node *curr = head;
	
	while(curr != NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	
	if (temp != NULL)
	{
		tail = head;
		head = temp->prev;
	}
}

//Delete Tail Function
void deleteEnd()
{
	Node *temp = tail;
	tail = tail->prev;
	if (tail != NULL)
	{
		tail->next = NULL;
	}
	else 
	{
        head = NULL;
    }
    
	delete temp;
}

//Delete Head Function
void deleteStart() 
{
    Node* temp = head;
    head = head->next;
    if (head != NULL) 
	{
        head->prev = NULL;
    }
    else 
	{
        tail = NULL;
    }

    delete temp;
}

//Delete After any Position
void deletePosition(int pos) 
{
    Node* curr = head;
    for (int i = 1; i < pos; i++) 
	{
        curr = curr->next;
    }
    if (curr->prev != NULL) 
	{
        curr->prev->next = curr->next;
    } 
	else 
	{
        head = curr->next;
    }
    if (curr->next != NULL) 
	{
		curr->next->prev = curr->prev;
    } 
	else 
	{
        tail = curr->prev;
    }
    
    delete curr;
}

};

int main()
{
	Doubly dll;
    dll.insertTail(14);
    dll.insertStart(12);
    dll.insertAfter(1, 13);
    dll.Display();
    dll.Search(12);
    dll.Reverse();
    dll.insertTail(15);
    dll.Display();
    dll.deleteEnd();
    dll.Display();

    return 0;
}
