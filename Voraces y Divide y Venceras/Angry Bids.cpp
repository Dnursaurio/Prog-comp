#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	if(!(cin>>t))return 0;
	struct T {int p, c; vector<int> P,C;};
	vector<T>ts(t);
	for(int i = 0; i < t; i++)
	{
		cin>>ts[i].p>>ts[i].c;
		ts[i].P.resize(ts[i].p); for(int j = 0; j <ts[i].p; j++) cin>>ts[i].P[j];
		ts[i].C.resize(ts[i].c); for(int j = 0; j <ts[i].c; j++) cin>>ts[i].C[j];
	}
	vector<pair<long long, long long>> res(t);
	for(int i = 0; i < t; i++)
	{
		auto&P = ts[i].P; auto& C = ts[i].C;
		sort(P.begin(),P.end()); sort(C.begin(),C.end());
		vector<int> pts = {0};
		for(int x : P) pts.push_back(x);
		for(int x : C) pts.push_back(x);
		sort(pts.begin(),pts.end()); pts.erase(unique(pts.begin(), pts.end()), pts.end());
		long long ma = -1, bp = -1;
		for(int x : pts)
		{
			long long a = P.end() - upper_bound(P.begin(),P.end(),x);
			long long b = lower_bound(C.begin(),C.end(),x) - C.begin();
			long long tot = a + b;
			if(ma == -1 || tot < ma) {ma = tot; bp = x;}
		}
		res[i] = {bp,ma};
	}
	for(int i = 0; i < t ; i++) cout<< res[i].first << " " << res[i].second<<endl;
}
