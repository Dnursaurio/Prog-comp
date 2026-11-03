#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char name[15];
int n,m,dist[121][16];

bool input()
{
	if(scanf(" %s %d %d",name,&n,&m) != 3) return false;
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			dist[i][j] = (i == 0 ? 0 : 1e9);
		}
	}
	
	for(int k = 0, cost; k < n - 1; k++)
	{
		for(int i = 1; i <= m; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				scanf("%d",&cost), dist[k + 1][j] = min(dist[k + 1][j], dist[k][i] + cost + 2);
			}
		}
	}
	return true;
}

int main()
{
	while(input())
	{
		int lo = 1e9;
		for(int i = 1; i <= m; i++)
		{
			lo = min(lo, dist[n - 1][i]);
		}
		printf("%s\n%d\n",name,lo);
	}
}
