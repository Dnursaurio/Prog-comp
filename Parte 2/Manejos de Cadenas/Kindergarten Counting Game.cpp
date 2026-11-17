#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	while(getline(cin,s))
	{
		int c = 0;
		for(size_t i = 0; i < s.size(); i++)
		{
			if(isalpha(s[i]) && ( i == 0 || !isalpha(s[i - 1]))) c++;
		}
		cout<<c<<"\n";
	}
	return 0;
}
