#include<iostream>
#include<vector>
using namespace std;
class graph{
    vector<vector<int>> arr;
    public:
    graph(int n) : arr(n, vector<int>(n, 0)) { }
    void addEdge(int u,int v,bool d){
        arr[u][v]=1;
        if(d==1){
            arr[v][u]=1;
        }
    }
    void printgraph(){
        for (const auto& row : arr) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    }
};
int main(){
    int n,m;
    cout<<"enter nodes"<<endl;
    cin>>n;
    cout<<"enter edges"<<endl;
    cin>>m;
    graph g(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u >>v;
        g.addEdge(u,v,1);
    }
    g.printgraph();
}