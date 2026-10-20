#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		vector<int>padre(N + 1);
		vector<int>dist(N + 1,0);
		for(int i = 1; i <= N; i++) padre[i] = i;
		char op;
		while(cin>>op && op != 'O')
		{
			if(op == 'I')
			{
				int i,j;
				cin>>i>>j;
				padre[i] = j;
				dist[i] = abs(i - j) % 1000;
			}
			else if(op == 'E')
			{
				int i;
				cin>>i;
				int total = 0;
				int actual = i;
				
				while(padre[actual] != actual)
				{
					total += dist[actual];
					actual = padre[actual];
				}
				cout<<total<<"\n";
			}
		}
	}
	return 0;
}
