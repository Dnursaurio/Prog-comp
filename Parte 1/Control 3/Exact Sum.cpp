#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main()
{
	int n_books;
	while(cin>>n_books && n_books)
	{
		multiset<int>prices;
		for(int i = 0; i < n_books; i++)
		{
			int p; cin>>p;
			prices.insert(p);
		}
		int total; cin>>total;
		int mini = 1e9;
		int i,j;
		for(auto it = prices.begin(); it != prices.end(); it++)
		{
			int other = total - (*it);
			if(prices.find(other) != prices.end())
			{
				int rest = abs(other - (*it));
				if(rest < mini)
				{
					mini = rest;
					i = (*it) ; j = other;
				}
			}
		}
		cout<<"Peter should buy books whose prices are "<<i<<" and "<<j<<".\n";
		cout<<endl;
	}
	return 0;
}
