#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string w;
	vector <string> v;
	map<string, int> cnt;
	while(cin>>w && w != "#")
	{
		v.push_back(w);
		string k = w;
		for(char &c : k) c = tolower(c);
		sort(k.begin(),k.end());
		cnt[k]++;
	}
	sort(v.begin(), v.end());
	for(const auto &s : v)
	{
		string k = s;
		for(char &c : k) c = tolower(c);
		sort(k.begin(), k.end());
		if(cnt[k] == 1) cout<<s<<"\n";
	}
}
