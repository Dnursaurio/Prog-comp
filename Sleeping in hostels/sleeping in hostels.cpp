#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dist(vector<string>caso)
{
	int dist_max = 0;
	
	return 0;
}

int main()
{
	int casos = 0;
	cin>>casos;
	string entrada = "";
	vector<vector<string>>casos_totales;
	for(int i = 0;i < casos;i++)
	{
		cin>>entrada;
		vector<string>caso(entrada.length());
		caso.push_back(entrada);
		casos_totales.push_back(caso);
		cout<<caso.size()<<endl;
	}
	vector<vector<string>>::iterator j = casos_totales.begin();
	for(;j<casos_totales.end();j++)
	{
		dist(*j);
	}
	return 0;
}
