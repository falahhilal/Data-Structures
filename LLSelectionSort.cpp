#include <iostream>
using namespace std;
class Node {
public:
 int data;
 Node* next;
  Node(int val){
 	 data=val;
 	 next =NULL;}
};
class LinkedList {
public:
 Node* head;
 LinkedList(){
 	head=NULL;}
 // Function to insert a new node at the end
 void insert(int data) {
 Node* newNode = new Node(data);
 newNode->next = head;
 head = newNode;
 }
 // Function to print the list
 void printList() {
 Node* temp = head;
 while (temp) {
 cout << temp->data << " ";
 temp = temp->next;
 }
 cout << endl;
 }
 // Function to perform selection sort
 void selectionSort(){
 	if(!head) return;
	Node* temp= head;
	while(temp->next!=NULL){
		Node* temp2=temp->next;
		while(temp2!=NULL){
			if((temp->data)>(temp2->data)){
				int t = temp->data;
                temp->data = temp2->data;
                temp2->data = t;
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}
 }
};
int main() {
 LinkedList list;
 list.insert(3);
 list.insert(0);
 list.insert(6);
 list.insert(2);
 list.insert(5);
 cout << "Original list: ";
 list.printList();
 list.selectionSort();
 cout << "Sorted list: ";
 list.printList();
 return 0;
};
