#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
int spf[N + 1], pi[N + 1];
double dp[N + 1];

int main()
{
	for(int i = 2; i <= N; i++)
	{
		if(!spf[i])for(int j = i; j <= N; j+= i) if(!spf[j])spf[j] = i;
		pi[i] = pi[i - 1] + (spf[i] == i);
		int x = i, c = 0;
		double s = pi[i];
		while(x>1)
		{
			int p = spf[x];
			while(x % p == 0) x/= p;
			s += dp[i / p], ++c;
		}
		dp[i] = s/c;
	}
	int t,cs = 0,n;
	for(scanf("%d",&t);t-- && scanf("%d",&n) == 1;)
		printf("Case %d: %.10f\n", ++cs,dp[n]);
}
