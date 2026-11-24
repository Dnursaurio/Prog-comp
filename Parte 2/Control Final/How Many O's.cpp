#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll z(ll x)
{
	if(x < 0) return 0;
	ll ans = 1;
	for(ll p = 1; p <= x/ 10;p*=10)
	{
		ll hi = x / (p * 10), cur = (x / p) % 10, lo = x % p;
		ans += cur? hi * p : (hi - 1) * p + lo + 1;
	}
	return ans;
}

int main()
{
	ll m,n;
	while(scanf("%lld %lld", &m,&n) == 2 && m >= 0)
		printf("%lld\n",z(n) - z(m - 1));
}
