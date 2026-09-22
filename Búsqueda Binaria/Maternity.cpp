#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct City
{
	string name;
	long long pop;
	long long x, y;
};

struct Testcase
{
	int C;
	vector<City> cities;
	int M;
	vector<string> maternity;
	int N;
};

long long manhattan(long long x1, long long y1, long long x2, long long y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	vector<Testcase> all_cases;
	Testcase current;
	while(cin>>current.C)
	{
		current.cities.resize(current.C);
		for(int i = 0; i < current.C; i++)
		{
			cin>>current.cities[i].name>>current.cities[i].pop>> current.cities[i].x>>current.cities[i].y;
		}
		cin>>current.M;
		current.maternity.resize(current.M);
		for(int i = 0; i < current.M;i++)
		{
			cin>>current.maternity[i];
		}
		cin>>current.N;
		all_cases.push_back(current);
	}
	
	vector<vector<string>>all_outputs;
	for(const auto& tc: all_cases)
	{
		vector<long long>initial_min_dist(tc.C,2e18);
		for(int i = 0; i < tc.C;i++)
		{
			for(const string& m_name :tc.maternity)
			{
				auto it = find_if(tc.cities.begin(),tc.cities.end(),[&](const City& c){return c.name == m_name;});
				long long dist = manhattan(tc.cities[i].x,tc.cities[i].y,it->x,it->y);
				if(dist<initial_min_dist[i])
				{
					initial_min_dist[i] = dist;
				}
			}
		}
		long long best_cost = 2e18;
		vector<string> best_combination;
		int M = tc.M;
		int N = tc.N;
		vector<int>mask(M,0);
		fill(mask.end()-N,mask.end(),1);
		do
		{
			vector<string>closed_set;
			vector<string>remaining;
			for(int i = 0; i < M; i++)
			{
				if(mask[i]) closed_set.push_back(tc.maternity[i]);
				else remaining.push_back(tc.maternity[i]);
			}
			long long current_extra_cost = 0;
			for(int i = 0; i < tc.C ; i++)
			{
				long long min_d = 2e18;
				for(const string& m_name : remaining)
				{
					auto it = find_if(tc.cities.begin(),tc.cities.end(),[&](const City& c){return c.name == m_name;});
					long long dist = manhattan(tc.cities[i].x,tc.cities[i].y,it->x,it->y);
					if(dist < min_d)
					{
						min_d = dist;
					}
				}
				current_extra_cost += (min_d - initial_min_dist[i]) * tc.cities[i].pop;
			}
			sort(closed_set.begin(),closed_set.end());
			if(current_extra_cost < best_cost)
			{
				best_cost = current_extra_cost;
				best_combination = closed_set;
			}
			else if(current_extra_cost == best_cost)
			{
				if(closed_set < best_combination)
				{
					best_combination = closed_set;
				}
			}
		}
		while(next_permutation(mask.begin(),mask.end()));
		all_outputs.push_back(best_combination);
	}
	for(size_t i = 0; i <all_outputs.size();i++)
	{
		for(const string& name: all_outputs[i])
		{
			cout<<name<<"\n";
		}
		if(i + 1 < all_outputs.size())
		{
			cout<<"\n";
		}
	}
	return 0;
}
