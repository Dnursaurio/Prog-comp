#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	vector<int> factoriales;
	for(int i = 1; i <= 8; i++)
	{
		int fact = 1;
		for(int j = 1; j <= i; j++)
		{
			fact *= j;
		}
		factoriales.push_back(fact);
	}
	while(cin >> N)
	{
		int cantidad = 0;
		for(int i = factoriales.size() - 1; i >= 0; i--)
		{
			cantidad += N / factoriales[i];
			N %= factoriales[i];
		}
		cout<<cantidad<<"\n";
	}
	return 0;
}
