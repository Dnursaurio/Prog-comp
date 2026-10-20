#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct I{double l,r;};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	double L; int G;
	struct T
	{
		double L; int G; vector<pair<double,double>>s;
	};
	vector<T>cases;
	while(cin>> L >> G && (L != 0 || G!= 0))
	{
		T t{L,G,vector<pair<double,double>>(G)};
		for(int i = 0; i < G; i++) cin>>t.s[i].first >> t.s[i].second;
		cases.push_back(t);
	}
	vector<int> res;
	for(auto&c:cases)
	{
		vector<I> iv;
		for(auto& st:c.s)
		{
			double l = max(0.0, st.first - st.second), r = min(c.L, st.first + st.second);
			if(l<=r) iv.push_back({l,r});
		}
		sort(iv.begin(),iv.end(),[](I a, I b){return a.l != b.l ? a.l < b.l : a.r > b.r;});
		double cur= 0; int cnt = 0, idx = 0, n = iv.size();
		while(cur<c.L)
		{
			double mx = cur;
			while(idx < n && iv[idx].l <= cur) mx = max(mx,iv[idx++].r);
			if(mx == cur){cnt = -1; break;}
			cur = mx; 
			cnt++;
		}
		res.push_back(cnt == -1 ? -1 : c.G - cnt);
	}
	for(int r: res)cout<<r<<endl;
}
