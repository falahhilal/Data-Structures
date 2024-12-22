#include<iostream>
using namespace std;
void interpolation(int arr[],int el,int s,int e){
    int pos=s+((e-s)/(arr[e]-arr[s]))*(el-arr[s]);
    if(el>arr[e] || el<arr[s]){
        cout<<"Element not found in array"<<endl;
        return;
    }
    if(arr[pos]==el){
        cout<<"Element found at index "<<pos<<endl;
        return;
    }
    else if(el>arr[pos]){
        interpolation(arr,el,pos+1,e);
    }
    else{
        interpolation(arr,el,s,pos-1);
    }
}
int main(){
    int arr[9]={1,2,4,6,7,10,11,14,15};
    interpolation(arr,7,0,8);
}
