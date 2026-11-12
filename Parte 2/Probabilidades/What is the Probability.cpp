#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int s;
	if(!(cin>>s))return 0;
	while(s--)
	{
		int n ,i;
		double p;
		cin>>n>>p>>i;
		if(p == 0)
		{
			cout<<"0.0000\n";
		}
		else
		{
			double q = 1.0 - p;
			double ans = (pow(q, i - 1) * p) / (1.0 - pow(q,n));
			cout<<fixed<<setprecision(4)<<ans<<"\n";
		}
	}
	return 0;
}
