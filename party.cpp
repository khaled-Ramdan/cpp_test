//get depth of a grapth and calculate max depth
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<bitset>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<cstdlib>
#include<iomanip>
#include<iterator>
#include<deque>
#include <conio.h>
#define lp(x,y) for(auto i=x;i<y;i++)
#define lpj(x,y) for(auto j=x;j<y;j++)
using namespace std;
typedef long long ll;
int n, a;
vector<vector<int>>graph;
vector<int>visited;
int parent[2005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        parent[i] = x;
    }
    int depth = -1;
    for (int i = 1;i <= n;i++) {
        int nodecount = 1;
        int x = i;
        while (parent[x] != -1) {
            x = parent[x];
            nodecount++;
        }
        depth = max(depth, nodecount);
    }
    cout << depth << endl;
    return 0;
}
