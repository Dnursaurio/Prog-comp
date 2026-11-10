#include <bits/stdc++.h>

using namespace std;

const int pisano[] = {0,60,300,1500,15000};
const int modulos[] = {0,10,100,1000,10000};

void solve()
{
	long long a,b,n;
	int m;
	if(!(cin>>a>>b>>n>>m)) return;
	int mod = modulos[m];
	n = n % pisano[m];
	if(n == 0)
	{
		cout<<a % mod<<"\n";
		return;
	}
	if(n == 1)
	{
		cout<<b % mod << "\n";
		return;
	}
	long long prev2 = a % mod;
	long long prev1 = b % mod;
	long long current = 0;
	
	for(int i = 2; i <= n; i++)
	{
		current = (prev1 + prev2) % mod;
		prev2 = prev1;
		prev1 = current;
	}
	cout<<current<<"\n";
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
			solve();
		}
	}
	return 0;
}
