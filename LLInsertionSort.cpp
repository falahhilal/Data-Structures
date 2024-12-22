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
 if (!head) {
 head = newNode;
 } else {
 Node* temp = head;
 while (temp->next) {
 temp = temp->next;
 }
 temp->next = newNode;
 }
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
 // Function to perform insertion sort
 
 void insertionSort() {
 if (head == NULL || head->next == NULL) return; // If the list is empty or has only one element, it's already sorted.
 // Initialize the sorted part of the list with the first node.
 Node* sorted = NULL;
 Node* current = head;
 while (current) {
 Node* nextNode = current->next; // Save the next node
 // If the sorted list is empty or the current node should be placed at the beginning
 if (sorted == NULL || current->data <= sorted->data) {
 current->next = sorted; // Insert the current node at the start of sorted
 sorted = current;
 } else {
 // Find the correct position to insert current in the sorted part
 Node* temp = sorted;
 while (temp->next && temp->next->data < current->data) {
 temp = temp->next;
 }
 // Insert the current node after temp
 current->next = temp->next;
 temp->next = current;
 }
 // Move to the next node in the original list
 current = nextNode;
 }
 // Update the head to point to the sorted list
 head = sorted;
 }
 
};
int main() {
 LinkedList list;
 list.insert(30);
 list.insert(100);
 list.insert(4);
 list.insert(20);
 list.insert(5);
 cout << "Original list: ";
 list.printList();
 list.insertionSort();
 cout << "Sorted list: ";
 list.printList();
 return 0;
}
