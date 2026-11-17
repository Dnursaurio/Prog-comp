#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, c = 1;
	if(cin >> t)
	{
		string s,j,ns;
		getline(cin,s);
		while(t--)
		{
			getline(cin,s);
			getline(cin,j);
			ns = "";
			for(char ch: s) if(ch != ' ') ns += ch;
			cout<<"Case "<<c++<<": ";
			if(s == j) cout<<"Yes\n";
			else if (ns == j) cout<<"Output Format Error\n";
			else cout<<"Wrong Answer\n";
		}
	}
	return 0;
}
