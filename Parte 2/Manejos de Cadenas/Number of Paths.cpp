#include <bits/stdc++.h>

using namespace std;

long long solve()
{
	string s;
	long long paths = 1;
	while(cin>>s && s != "ENDPROGRAM" && s != "ELSE" && s != "END_IF")
	{
		if(s == "IF")
		{
			long long left = solve();
			long long right = solve();
			paths *= (left + right);
		}
	}
	return paths;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	if(cin>>t)
	{
		while(t--)
		{
			cout<<solve()<<"\n";
		}
	}
	return 0;
}
