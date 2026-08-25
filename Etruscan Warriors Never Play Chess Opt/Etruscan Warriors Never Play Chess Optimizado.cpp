//optimizado
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long casos_prueba = 0;
	cin>>casos_prueba;
	vector<long long> i(casos_prueba);
	vector<long long>::iterator j = i.begin();
	for(;j <= i.end() - 1;j++)
	{
		long long nro = 0;
		cin>>nro;
		if(nro<0)
		{
			break;
		}
		*j = nro;
	}
	vector<long long>::iterator h = i.begin();
	for(;h < i.end();h++)
	{
		long long k = 0;
		long long min_filas = 1;
		long long max_filas = 2000000000;
		while(min_filas <= max_filas)
		{
			long long mitad = min_filas + (max_filas - min_filas)/2;
			if(mitad * (mitad + 1)/2 <= *h)
			{
				k=mitad;
				min_filas = mitad + 1;
			}
			else
			{
				max_filas = mitad - 1;
			}
		}
		cout<<k << endl;
	}
	return 0;
}
