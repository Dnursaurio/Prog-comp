#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int casos = 0;
	cin>>casos;
	string entrada = "";
	for(int i = 0;i < casos;i++)
	{
		cin>>entrada;
		vector<string>caso(entrada.length());
		caso.push_back(entrada);
		cout<<caso.size()<<endl;
	}
}
