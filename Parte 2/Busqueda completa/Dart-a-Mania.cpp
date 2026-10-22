#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	set<int>s;
	s.insert(0);
	s.insert(50);
	for(int i = 1;i <=20;i++)
	{
		s.insert(i);
		s.insert(2 * i);
		s.insert(3 * i);
	}
	vector<int> v(s.begin(),s.end());
	int n = v.size();
	vector<int>inputs;
	int x;
	while(cin>> x && x > 0)
	{
		inputs.push_back(x);
	}
	for(int target : inputs)
	{
		long long c = 0, p = 0;
		for(int i = 0;i< n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					if(v[i] + v[j] + v[k] == target) p++;
				}
			}
		}
		
		for(int i = 0;i< n; i++)
		{
			for(int j = i; j < n; j++)
			{
				for(int k = j; k < n; k++)
				{
					if(v[i] + v[j] + v[k] == target) c++;
				}
			}
		}
		
		if(p > 0)
		{
			cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<target<<" IS "<<c<<".\n";
			cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<target<<" IS "<<p<<".\n";
		}
		else
		{
			cout<<"THE SCORE OF "<<target<<" CANNOT BE MADE WITH THREE DARTS.\n";
		}
		cout<<string(70,'*')<<"\n";
	}
	cout<<"END OF OUTPUT\n";
	return 0;
}
