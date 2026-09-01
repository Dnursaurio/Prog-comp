#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void recrear(vector<pair<int, int>> carros)
{
	vector<int>pole(carros.size());
	for(auto it = carros.begin();it<carros.end();it++)
	{
		int indice = it - carros.begin();
		int pos_actual = indice + it->second;
		if(pos_actual != carros.size())
		{
			cout<<-1<<endl;
			return;
		}
		pole[pos_actual] = it->first();
	}
}

int main()
{
	int casos = 5;
	int nro_carros = 0;
	int posicion = 0;
	int carro = 0;
	int indice = 0;
	int pos_actual = 0;
	for(int i = 0; i < casos;i++)
	{
		cin>>nro_carros;
		if(nro_carros == 0)
		{
			break;
		}
		vector<pair<int,int>> carros(nro_carros);
		for(auto it = carros.begin();it<carros.end();it++)
		{
			cin>>carro;
			it->first = carro;
			cin>>posicion;
			it->second = posicion;
			indice = it - carros.begin();
			pos_actual = indice + it->second;
		}
		void recrear(carros);
	}
	return 0;
}
