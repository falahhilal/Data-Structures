#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class graph{
    public:
    unordered_map<int,bool>visited;
    queue<int>q;
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
    void bfs(int a){
        q.push(a);
        do{
            int u=q.front();
            q.pop();
            if(visited[u]==false){
                cout<<u<<endl;
                visited[u]=true;
            }
            for (auto node : adj[u]) {
                if(visited[node]==false){
                    q.push(node);
                }      
            }
        }while(!q.empty());
        for(int i=0;i<size;i++){      //for disconnected graphs
            if(!visited[i]){
                bfs(i);
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
    g.bfs(0);
}