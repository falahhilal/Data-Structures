#include <iostream>
using namespace std;
class Node{
	public:
        string name;
        int rn;
		Node*next;
		Node(int r,string n){
            rn=r;
            name=n;
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
		void InsertAtTail(int r,string na){
			Node*n=new Node(r,na);
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
		void Display(){
			Node * temp= head;
            while(temp != NULL){
            	cout<<temp->name<<" "<<temp->rn<<endl;
                temp=temp->next;
            }
        }
};

class record{
public:           
int tsize;            // Size of the hash table
Singly* table;
int count=0;
// Constructor 
record(int size) : tsize(size) {
   table= new Singly[tsize];
}
// quadratic probing
void insertion(int rn, string name)
{
    int hv = rn % tsize;    // Computing the hash value
    table[hv].InsertAtTail(rn,name);
    cout<<"Inserted "<<name<<","<<rn<<endl;
    count++;
}
void searching(int rn){
    int hv = rn % tsize;    // Computing the hash value
    Node* pre;
    Node* curr=table[hv].head;
    while(curr!=NULL){
        if(curr->rn==rn){
            cout<<"Record Found, Name:"<<curr->name<<endl;
            return;
        }
        pre=curr;
        curr=curr->next;
    }
    cout<<"Record not found"<<endl;
    return;
}
void deletion(int rn){
    int hv = rn % tsize;    // Computing the hash value
    Node* pre;
    Node* curr=table[hv].head;
    if(rn==curr->rn){
        table[hv].head=table[hv].head->next;
        delete curr;
        cout<<"Record deleted"<<endl;
        return;
    }
    while(curr!=NULL){
        if(curr->rn==rn){
            if(curr==table[hv].tail){
                table[hv].tail=pre;
                table[hv].tail->next=NULL;
                delete curr;
                cout<<"Record deleted"<<endl;
                return;
            }
            pre->next=curr->next;
            delete curr;
            cout<<"Record deleted"<<endl;
            return;
        }
        pre=curr;
        curr=curr->next;
    }
    cout<<"Record not found"<<endl;
    return;
}
void printtable(){
    cout<<"Hash Table"<<endl;
    for(int i=0;i<tsize;i++){
        cout<<"Data at Index "<<i<<endl;
        table[i].Display();
    }
    return;
}
};
int main()
{
    record r(5);//an instance of the record class
    // Inserting records into the hash table
    r.insertion( 31, "falah");
    r.insertion(18, "ahsn");
    r.insertion( 23, "mars");
    r.insertion( 34, "jumi");
    r.insertion( 16, "peter");
    r.insertion( 22, "jj");
    r.insertion( 90, "lala");
    // Searching for records
    r.searching(31);
    r.searching(34);
    r.searching(10);
    r.printtable();
    // Deleting a record and searching again
    r.deletion(18);
    r.searching(18);
    r.printtable();
    return 0;
}