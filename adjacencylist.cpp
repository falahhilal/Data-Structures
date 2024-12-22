#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map< int, list<int> > adj;
    void addEdge(int u,int v,bool d){
        adj[u].push_back(v);
        if(d==1){
            adj[v].push_back(u);
        }
    }
    void printgraph(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n,m;
    cout<<"enter nodes"<<endl;
    cin>>n;
    cout<<"enter edges"<<endl;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u >>v;
        g.addEdge(u,v,1);
    }
    g.printgraph();
}