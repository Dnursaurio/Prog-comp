#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	double cows,cars,show;
	while(cin>>cows>>cars>>show)
	{
		double total = cows + cars;
		double remaining = total - 1.0 - show;
		double ans = (cars * (total - 1.0)) / (total * remaining);
		cout<<fixed<<setprecision(5)<<ans<<"\n";
	}
	return 0;
}
