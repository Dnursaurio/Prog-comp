#include <iostream>

using namespace std;

int main()
{
	int*i = nullptr;
	int min = 0;
	int max = 1e18;
	int casos_prueba = 0;
	cout<<"ingrese el nro de casos de estudio: ";
	cin>>casos_prueba;
	cout<<"el nro de casos de prueba es: "<< casos_prueba<<endl;
	int c_p = 1;
	i = new int[casos_prueba];
	int*j = i;
	for(;j <= i + casos_prueba - 1;j++)
	{
		int nro = 0;
		cout<<"ingrese el numero de guerreros en el caso de estudio "<< c_p<<": ";
		cin>>nro;
		c_p++;
		if(nro<min || nro>max)
		{
			cout<<"fuera de rango, prueba otro numero";
			break;
		}
		*j = nro;
	}
	cout<<"organizando sus guerreros en filas"<<endl;
	
	return 0;
}
