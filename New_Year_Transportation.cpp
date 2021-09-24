//bfs with build solution of the route if exist 
#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include<queue>
#define lp(x,y) for(auto i=x;i<y;i++)
#define lpj(x,y) for(auto j=x;j<y;j++)
using namespace std;
typedef long long ll;
int n, t, a;
vector<vector<int>>graph;
vector<int>parent;
void solution(int from, int to)
{
    list<int>l;
    for (int node = to;node != from;node = parent[node])
    {
        l.push_back(node);
    }
    l.push_back(from);
    auto it = l.rbegin();
    cout << *it;
    it++;
    for (;it != l.rend();it++)cout << "=>"<<*it;cout << endl;
}
bool bfs(int from,int to)
{
    vector<bool>visited(n + 1);
    queue<int>q;
    q.push(from);
    while (q.size())
    {
        int front = q.front();
        if (to == front) { solution(from,to);return true; }
        visited[front] = true;
        q.pop();
        for (auto& child : graph[front])
        {
            if (!visited[child])
            {
                parent[child] = front;
                visited[child] = true;
                q.push(child);
            }
        }
    }
    return false;
}
int main() {
    cin >> n >> t;
    graph.resize(n+1);
    parent.resize(n + 1);
    lp(1, n)
    {
        cin >> a;
        graph[i].push_back(i + a);
    }
    if (bfs(1,t))cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
