#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	while(cin>>s && s != "#")
	{
		int c[26] = {}, odd = 0;
		for(char ch : s) c[ch - 'a']++;
		for(int i = 0; i < 26; i++) if(c[i] & 1) odd++;
		string ans;
		if(odd > 1)
		{
			int k = odd - 1;
			for(int i = 0; i < 26 && k; i++)
			{
				if(c[i] & 1) ans += char('a' + i), k--;
			}
		}
		cout<<ans<<"\n";
	}
}
