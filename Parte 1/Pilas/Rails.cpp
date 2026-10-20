#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	while(cin>>n && n != 0)
	{
		int first_elem;
		while(cin>>first_elem && first_elem != 0)
		{
			vector<int>target(n);
			target[0] = first_elem;
			for(int i = 1; i < n; i++)
			{
				cin>>target[i];
			}
			stack<int> s;
			int current = 1;
			bool possible = true;
			int idx = 0;
			while(idx < n)
			{
				if(!s.empty() && s.top() == target[idx])
				{
					s.pop();
					idx++;
				}
				else if(current <= n)
				{
					s.push(current++);
				}
				else
				{
					possible = false;
					break;
				}
			}
			cout<<(possible?"Yes":"No")<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
