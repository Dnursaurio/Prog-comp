#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
vector<int> p;

void sieve()
{
	vector<bool> is_p(MAX, true);
	for(int i = 2; i * i < MAX; i++)
	{
		if(is_p[i]) for(int j = i * i; j < MAX; j+=i) is_p[j] = false;
	}
	for(int i = 2; i < MAX; i++)
	{
		if(is_p[i]) p.push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	sieve();
	int L,R;
	while(cin>>L>>R && (L||R))
	{
		if(L > R)swap(L,R);
		auto itL = lower_bound(p.begin(),p.end(),L);
		int start = distance(p.begin(),itL), n = p.size();
		
		for(int i = start; i + 2 < n && p[i + 2] <= R;)
		{
			int d = p[i + 1] - p[i], j = i + 1;
			while(j < n && p[j] <= R && p[j] - p[j - 1] == d) j++;
			
			bool prev_same = (i > 0 && p[i] - p[i - 1] == d);
			if(j - i >=3 && !prev_same && p[j - 1] <= R)
			{
				for(int k = i; k < j; k++) cout<<p[k]<<(k == j - 1 ? "" : " ");
				cout<<"\n";
			}
			i= max(i + 1, j - 1);
		}
	}
}
