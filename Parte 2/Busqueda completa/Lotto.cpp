#include <iostream>
#include <vector>

using namespace std;

void solve(const vector<int>&S, int k, int start, int depth, vector<int>current)
{
	if(depth == 6)
	{
		for(int i = 0; i < 6; i++)
		{
			cout<<current[i]<< (i == 5? "":" ");
		}
		cout<<"\n";
		return ;
	}
	for(int i = start; i <= k - (6 - depth); i++)
	{
		current[depth] = S[i];
		solve(S,k,i + 1, depth + 1, current);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int k;
	vector<vector<int>>test_cases;
	
	while(cin>>k && k != 0)
	{
		vector<int>S(k);
		for(int i = 0; i < k; i++)
		{
			cin>>S[i];
		}
		test_cases.push_back(S);
	}
	for(size_t t = 0; t < test_cases.size(); t++)
	{
		if(t > 0)
		{
			cout<<"\n";
		}
		vector<int> current(6);
		solve(test_cases[t],test_cases[t].size(),0,0,current);
	}
	return 0;
}
