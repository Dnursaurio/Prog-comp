#include <bits/stdc++.h>

using namespace std;

vector<int>p;

void sieve()
{
	bitset<1000001>is_p;
	is_p.set();
	is_p[0] = is_p[1] = false;
	for(long long i = 2; i < 1000001; i++)
	{
		if(is_p[i])
		{
			p.push_back(i);
			for(long long j = i * i; j < 1000001; j += i)is_p[j] = false;
		}
	}
}

int main()
{
	sieve();
	int n;
	while(scanf("%d",&n) && n)
	{
		vector<int>f;
		if(n < 0) f.push_back(-1);
		else if(n==1) f.push_back(1);
		
		long long temp = abs(n);
		for(int prime : p)
		{
			if(1LL * prime * prime > temp) break;
			while(temp % prime == 0) {f.push_back(prime); temp /= prime;}
		}
		if(temp > 1) f.push_back(temp);
		
		printf("%d =", n);
		for(size_t i = 0; i < f.size(); i++)
		{
			printf("%s %d", (i == 0 ? "" : " x"), f[i]);
		}
		printf("\n");
	}
}
