#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class graph{
    public:
    unordered_map<int,bool>visited;
    unordered_map<int,list<int>>adj;
    int size;    //num of nodes
    graph(int n){
        size=n;
        for(int i = 0; i<n; ++i) {
            visited[i] = false;  
        }
    }
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
    void dfs(int a){
        cout<<a<<endl;
        visited[a]=true;
        for(auto node:adj[a]){
            if(!visited[node]){
                dfs(node);
            }
        }
    }
    void dfs_all(){
        for(int i=0;i<size;i++){      
            if(!visited[i]){
                dfs(i);
            }
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
    g.dfs_all();
}