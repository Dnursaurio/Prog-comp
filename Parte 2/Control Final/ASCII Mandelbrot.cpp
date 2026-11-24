#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	double mini,maxi,minr,maxr,preci,precr;
	char s[128];
	if(scanf("%d",&t) != 1) return 0;
	while(t--)
	{
		scanf("%s %lf %lf %lf %lf %lf %lf", s,&mini,&maxi,&preci,&minr,&maxr,&precr);
		s[0] = s[13] = ' ';
		for(double a = mini; a <= maxi + 1e-8f; a += preci, puts(""))
		{
			for(double b = minr; b <= maxr + 1e-8f; b += precr)
			{
				float za = 0, zb = 0, ta;
				int i = 0;
				for(;i<12 && za * za + zb * zb <= 4; i++)
				{
					ta = za * za - zb * zb, zb = 2 * za  * zb + a, za = ta + b;
				}
				putchar(s[i + 1]);
			}
		}
		if(t)puts("");
	}
}
