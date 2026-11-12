#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	while(cin>>s)
	{
		int n = s.length();
		int count0 = 0, count00 = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
			{
				count0++;
				if(s[(i + 1) % n] == '0')
				{
					count00++;
				}
			}
		}
		int shoot = count00 * n;
		int rotate = count0 * count0;
		if(shoot > rotate)
		{
			cout<<"SHOOT\n";
		}
		else if(shoot < rotate)
		{
			cout<<"ROTATE\n";
		}
		else
		{
			cout<<"EQUAL\n";
		}
	}
	return 0;
}
