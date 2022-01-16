// if you found a valid element it becomes visited => don't use it again
// problem link => https://codeforces.com/contest/1041/problem/C

//notes 
/*
but elements in a set and a vector
use upper-lower bound function for the set
erease the selected element and repeat 
*/

#include<bits\stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define lp(x,y) for(auto i=x;i<y;i++)
#define lpj(x,y) for(auto j=x;j<y;j++)
#define W  int g;  cin>>g; while(g--)
#define SIZ ll(1e6)
using namespace std;
typedef  long long  ll;
const int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dy[8] = { 1, -1, 0, 0, -1, 1, 1, -1 };
ll dp[SIZ];
int n, k;
void solve() {
	ll n, m, d, day = 1;
	cin >> n >> m >> d;
	set<pair<ll, ll>>a;
	vector<pair<ll, ll>>aa(n);
	vector<ll>ans(n);
	lp(0, n)cin >> aa[i].first, aa[i].second = i, a.insert(aa[i]);
	while (a.size())
	{
		int pos = a.begin()->second;
		a.erase(a.begin());
		ans[pos] = day;
		while (true) {
			pair<ll, ll>pp = { aa[pos].first + d + 1,0 };
			auto it = a.lower_bound(pp);
			if (it == a.end())break;
			pos = it->second;
			a.erase(it);
			ans[pos] = day;
		}
		day++;
	}
	cout << day - 1 << endl;
	for (ll i : ans)cout << i << " ";
}
int main() {
	IO;
	solve();
	return 0;
}
