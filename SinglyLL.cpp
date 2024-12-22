#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node*next;
		Node(int val){
			data=val;
			next=NULL;
		}
};
class Singly{
	public:
		Node*head;
		Node*tail;
		Singly(){
			head=NULL;
			tail=NULL;
		}
		void InsertAtTail(int val){
			Node*n=new Node(val);
			if(head==NULL){
				head=n;
				return;
			}
			Node*temp=head;
			while(temp -> next!=NULL){
				temp=temp->next;
			}
			temp -> next=n;
			n -> next=NULL;
			tail=n;
		}
		void InserAtStart(int val){
			Node *n=new Node(val); 
            n -> next= head; //new nodes next pointer is set to point to the current head node
            head=n; //new node is made the new head of the list
        }
        void InsertAtAnyPosition(int pos,int val){
        	Node* n =new Node(val);
        	Node*curr;
        	Node*pre;
        	curr=head;
        	for(int i=0;i<pos;i++){
        		pre=curr;
        		curr=curr->next;
			}
        	pre->next=n;
        	n->next=curr;
		}
		void Display(){
			Node * temp= head;
            while(temp != NULL){
            	cout<<temp->data<<"";;
                temp=temp->next;
            }
        }
        void DeleteFromEnd(){
        	Node*curr=head;
        	Node*pre;
        	while(curr->next!=NULL){
        		pre=curr;
        		curr=curr->next;
			}
			tail=pre;
			tail->next=NULL;
			delete curr;
		}
		void DeleteFromStart(){
			Node*temp=head;
			head=head->next;
			delete temp;
		}
        void DeleteAfter(int pos){
        	Node *pre;
            Node *curr=head;
            for(int i=1;i<pos;i++){
            	pre=curr;
                curr=curr->next;
            }
            pre->next=curr->next;
            delete curr;
        }
};
int main(){
return 0;
}
