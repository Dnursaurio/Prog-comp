#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int casos;
	string name;
	vector<string>nombres;
	vector<int> limites;
	while(cin>>casos && casos > 0)
	{
		limites.push_back(casos);
		for(int i = 0; i < casos; i++)
		{
			cin>>name;
			nombres.push_back(name);
		}
	}
	int offset = 0;
	auto it = limites.begin();
	while(it < limites.end())
	{
		int n = *it;
		auto ini = nombres.begin() + offset;
		auto fin = nombres.begin() + offset + n;
		sort(ini,fin);
		string i = nombres[offset + (n/2 - 1)];
		string j = nombres[*it + offset - n/2];
		string rpta = "";
		for(int k = 0; k < i.length();k++)
		{
			if(k>=j.length())
			{
				rpta = i;
				break;
			}
			if(i[k] == j[k])
			{
				rpta += i[k];
			}
			else
			{
				rpta = i[k] + 1;
			}
		}
		for(auto &c : rpta) {
			c = toupper(c);
		}
		cout<<rpta<<endl;
		offset += *it;
		it++;
	}
}
