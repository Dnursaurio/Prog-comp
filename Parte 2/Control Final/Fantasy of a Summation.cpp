#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull pw(ull a,ull e, ull m)
{
	ull r = 1 % m;
	for(a%=m; e; e>>=1, a = a * a % m)
	{
		if(e & 1) r = r * a % m;
	}
	return r;
}

int main()
{
	int t,cs=0;
	if(scanf("%d",&t) != 1) return 0;
	while(t--)
	{
		int n, mod, x;
		ull k, s = 0;
		scanf("%d %llu %d", &n,&k,&mod);
		for(int i= 0; i < n; i++) scanf("%d", &x),s = (s + x) % mod;
		ull ans = (s * (k % mod) % mod) * pw(n, k - 1, mod) % mod;
		printf("Case %d: %llu\n", ++cs,ans);
	}
}
