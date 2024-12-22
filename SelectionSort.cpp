#include<iostream>
using namespace std;
int main(){
int a[4]={6,8,1,0};
int i,j,temp;
int n=4;
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(a[i]>a[j]){
temp=a[j];
a[j]=a[i];
a[i]=temp;
}
}
}
for(i=0;i<n;i++){
cout<<a[i]<<endl;
}
}

