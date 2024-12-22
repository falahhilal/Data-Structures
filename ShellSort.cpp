#include<iostream>
using namespace std;
int main(){
int a[8]={3,9,5,2,8,7,4,6,};
int i,j,temp,gap;
int n=8;
for(gap=n/2;gap>0;gap=gap/2){
for(i=gap;i<n;i++){
for(j=i;j>0 && a[j-gap]>a[j];j-=gap){
   temp=a[j];
   a[j]=a[j-gap];
   a[j-gap]=temp;
}
}
}
for(i=0;i<n;i++){
cout<<a[i]<<endl;
}
}
