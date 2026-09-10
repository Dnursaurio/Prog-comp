#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <string>

using namespace std;

struct estado
{
	deque<int>  baraja;
	vector<vector<int>> montones;
	int turno;
	bool operator<(const estado& o) const
	{
		if(baraja != o.baraja)
		{
			return baraja < o.baraja;
		}
		if(turno != o.turno)
		{
			return turno < o.turno;
		}
		return montones < o.montones;
	}
};

bool procesar_montones(vector<int>&monton, deque<int>&baraja)
{
	bool cambio = 0;
	while(monton.size() >= 3)
	{
		int n = monton.size();
		int sum1 = monton[0] + monton[1] + monton[n - 1];
		int sum2 = monton[0] + monton[n - 2] + monton [n - 1];
		int sum3 = monton[n - 3] + monton[n - 2] + monton [n - 1];
		
		if(sum1 == 10 || sum1 == 20 || sum1 == 30)
		{
			baraja.push_back(monton[0]);
			baraja.push_back(monton[1]);
			baraja.push_back(monton[n - 1]);
			monton.erase(monton.begin() + (n - 1));
			monton.erase(monton.begin() + 1);
			monton.erase(monton.begin());
			cambio = 1;
		}
		else if(sum2 == 10 || sum2 == 20 || sum2 == 30)
		{
			baraja.push_back(monton[0]);
			baraja.push_back(monton[n - 2]);
			baraja.push_back(monton[n - 1]);
			monton.erase(monton.begin() + (n - 1));
			monton.erase(monton.begin() + (n - 2));
			monton.erase(monton.begin());
			cambio = 1;
		}
		else if(sum3 == 10 || sum3 == 20 || sum3 == 30)
		{
			baraja.push_back(monton[n - 3]);
			baraja.push_back(monton[n - 2]);
			baraja.push_back(monton[n - 1]);
			monton.pop_back();
			monton.pop_back();
			monton.pop_back();
			cambio = 1;
		}
		else
		{
			break;
		}
	}
	return cambio;
}

void resolver()
{
	int primera_carta;
	vector<string> rptas;
	while(cin>> primera_carta && primera_carta != 0)
	{
		deque<int>baraja;
		baraja.push_back(primera_carta);
		for(int i = 0; i < 51; i++)
		{
			int c;
			cin>>c;
			baraja.push_back(c);
		}
		
		vector<vector<int>> montones(7);
		int cartas_repartidas = 0;
		for(int i = 0; i < 7; i++)
		{
			montones[i].push_back(baraja.front());
			baraja.pop_front();
			cartas_repartidas ++;
		}
		set<estado> visitados;
		int pila_actual = 0;
		string resultado = "";
		while(true)
		{
			if(montones[pila_actual].empty())
			{
				pila_actual = (pila_actual + 1) % 7;
				bool vacio = 1;
				for(int i = 0; i < 7; i++)
				{
					if(montones[i].empty())
					{
						vacio = 0;
						break;
					}
				}
				if(vacio)
				{
					resultado = "Win ";
					break;
				}
				continue;
			}
			estado estado_actual = {baraja, montones, pila_actual};
			if(visitados.count(estado_actual))
			{
				resultado = "Draw";
				break;
			}
			visitados.insert(estado_actual);
			if(baraja.empty())
			{
				resultado = "Loss";
				break;
			}
			montones[pila_actual].push_back(baraja.front());
			baraja.pop_front();
			cartas_repartidas++;
			
			procesar_montones(montones[pila_actual],baraja);
			bool vacio = 1;
			for(int i = 0; i < 7; i++)
			{
				if(!montones[i].empty())
				{
					vacio = 0;
					break;
				}
			}
			if(vacio)
			{
				resultado ="Win ";
				break;
			}
			pila_actual = (pila_actual + 1) % 7;
			while(montones[pila_actual].empty())
			{
				pila_actual = (pila_actual + 1) % 7; 
			}
		}
		rptas.push_back(resultado + ": " + to_string(cartas_repartidas));
	}
	for(const string res: rptas)
	{
		cout<<res<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	resolver();
	return 0;
}
