#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,m;
	while(cin>>n>>m)
	{
		map<int,vector<int>>p;
		for(int i = 1,x;i<=n;i++)
		{
			cin>>x;
			p[x].push_back(i);
		}
		for(int i = 0,k,v; i<=n; i++)
		{
			cin>>k>>v;
			if(p.count(v) && p[v].size() >= k) cout<< p[v][k - 1] <<"\n";
			else cout<<0<<"\n";
		}
	}
	return 0;
}
