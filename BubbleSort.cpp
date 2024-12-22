#include<iostream>
using namespace std;
int main(){
int a[4]={5,2,1,9};
int i,j,temp;
int n=4;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[j]>a[j+1]){
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
for(i=0;i<n;i++){
cout<<a[i]<<endl;
}
}
