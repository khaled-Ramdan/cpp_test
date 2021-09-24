//dfs on graph for a matrix
#include<iostream>
#include <string>
#include <vector>
#include <stack>
#define lp(x,y) for(auto i=x;i<y;i++)
#define lpj(x,y) for(auto j=x;j<y;j++)
using namespace std;
typedef long long ll;
vector<vector<int>>graph;
vector<bool>visitedd(n);
int n,a,b;
void dfs(int i){
    stack<int>s;
    vector<bool>visited(n);
    s.push(i);
    while(!s.empty()){
        int top=s.top();
        s.pop();
        for(auto &child:graph[top])
        if(!visited[child]){
            visited[child]=true;
            s.push(child);
        }
    }
}
void dfs_recusrion(int i)
{
    for(auto&child:graph[i]){
        if(!visitedd[child]){
            visitedd[child]=true;
            dfs_recusrion(child);
        }
    }
}
int main(){
    
    cin>>n;
    graph.resize(n);
    lp(0,n){
        cin>>a>>b;
       graph[a].push_back(b);
       graph[b].push_back(a);
    }
    dfs(0);
    return 0;
}
