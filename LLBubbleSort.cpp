#include <iostream>
using namespace std;
class Node {
public:
 int data;
 Node* next;
 Node(int val){
 	 data=val;
 	 next =NULL;
 }
};
class LinkedList {
private:
 Node* head;
public:
 LinkedList(){
 	head=NULL;
 }
 // Insert a new node at the front of the list
 void insert(int val) {
 Node* newNode = new Node(val);
 newNode->next = head;
 head = newNode;
 }
 // Bubble sort function for the linked list
 void bubbleSort() {
 if (!head) return;
 bool swapped;
 do {
 swapped = false;
 Node* current = head;
 while (current && current->next) {
 if (current->data > current->next->data) {
 // Swap data directly
 int temp = current->data;
 current->data = current->next->data;
 current->next->data = temp;
 swapped = true;
 }
 current = current->next;
 }
 } while (swapped);
 }
 // Function to print the linked list
 void printList() const {
 Node* current = head;
 while (current) {
 cout << current->data << " ";
 current = current->next;
 }
 cout << endl;
 }
};
int main() {
 LinkedList list;
 list.insert(5);
 list.insert(1);
 list.insert(4);
 list.insert(2);
 list.insert(3);
 cout << "Before sorting: ";
 list.printList();
 list.bubbleSort();
 cout << "After sorting: ";
 list.printList();
 return 0;
}
