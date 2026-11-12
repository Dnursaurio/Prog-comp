#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	double p;
	while(cin>>n>>p && n != 0)
	{
		vector<double> powP(n + 1, 1.0);
		for(int i = 1; i <= n; i++)powP[i] = powP[i - 1] * p;
		vector<vector<double>>dp(n+1, vector<double>(n + 1, 0.0));
		
		for(int k = 0; k<=n; k++)
		{
			for(int i = 0; i <= n; i++)
			{
				if(i <= k)
				{
					dp[i][k] = 1.0;
				}
				else if(i == k + 1)
				{
					dp[i][k] = 1.0 - powP[k + 1];
				}
				else
				{
					dp[i][k] = dp[i - 1][k] - dp[i - k - 2][k] * (1.0 - p) * powP[k + 1];
				}
			}
		}
		double expected = 0;
		for(int k = 1; k <= n; k++)
		{
			expected += (1.0 - dp[n][k - 1]);
		}
		cout<<fixed<<setprecision(6)<<expected<<"\n";
	}
	return 0;
}
