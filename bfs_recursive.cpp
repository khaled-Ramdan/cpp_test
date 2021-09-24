//new year transportation in recursive solution 
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
vector<int>visited;
void solution_recursive(int from, int to, list<int>&l)
{
    if (to == from) {
        l.push_front(to);
        return;
    }
    solution_recursive(from, parent[to],l);
    l.push_back(to);
}
bool dfs_recursive(int i, int to) {
    if (i == to)return true;//found a route
    for (auto& child : graph[i]) {
        if (!visited[child]) {
            visited[child] = true;
            parent[child] = i;
            if (dfs_recursive(child, to))return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> t;
    graph.resize(n+1);
    parent.resize(n + 1);
    visited.resize(n + 1);
    lp(1, n)
    {
        cin >> a;
        graph[i].push_back(i + a);
    }

    if (dfs_recursive(1, t))
    {
        list<int>l;
        solution_recursive(1, t, l);
        for (int child : l)cout << child << "=>";
        cout << "YES\n";
    }
    else cout << "NO\n";
    return 0;
}
