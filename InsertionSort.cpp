#include<iostream>
using namespace std;
int main(){
int a[4]={6,8,1,0};
int i,j,temp;
int n=4;
for(i=1;i<n;i++){
j=i;
while(j>0 && a[j]<a[j-1]){
temp=a[j];
a[j]=a[j-1];
a[j-1]=temp;
j=j-1; //to end while loop
}
}
for(i=0;i<n;i++){
cout<<a[i]<<endl;
}
}

