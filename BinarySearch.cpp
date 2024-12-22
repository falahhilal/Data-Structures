#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
	int start=0;
	int end=size-1;
	int mid=start+ (end-start)/2; //(start+end)/2; this is done to avoid out of bound val of int
	
	while(start<=end){
		
		if(arr[mid]==key){
			return mid;
		}
		
		//going right
		if(arr[mid]<key){
			start=mid+1;
		}
		//going left
		else{
			end=mid-1;
		}
		mid=start+ (end-start)/2;
	}
	return -1;
}
int main(){
	int arr1[6]={2,4,6,8,10,12};
	int arr[5]={1,6,14,24,37};
	int index;
	index=binarySearch(arr1,6,2);
	cout<<"Index of 2"<<" is "<<index<<endl;
	
}
