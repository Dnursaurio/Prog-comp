#include <iostream>

using namespace std;

long long rev(long long n)
{
	long long r = 0;
	while(n > 0)
	{
		r = r * 10 + n % 10;
		n /= 10;
	}
	return r;
}

int main()
{
	int n;
	if(!(cin>>n))return 0;
	while(n--)
	{
		long long p, steps = 0;
		cin>> p;
		while(p != rev(p))
		{
			p += rev(p);
			steps++;
		}
		cout<<steps<<" "<<p<<"\n";
	}
	return 0;
}
