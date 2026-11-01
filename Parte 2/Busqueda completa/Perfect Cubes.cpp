#include <iostream>

using namespace std;

int main() {
	// Optimización de E/S
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int max_a = 200;
	
	// Precalculamos los cubos hasta 200 para evitar recalcularlos en los bucles anidados
	long long cube[201];
	for (int i = 0; i <= max_a; ++i) {
		cube[i] = (long long)i * i * i;
	}
	
	// Búsqueda completa para a, b, c, d
	for (int a = 6; a <= max_a; ++a) {
		long long a3 = cube[a];
		for (int b = 2; b < a; ++b) {
			long long b3 = cube[b];
			for (int c = b; c < a; ++c) {
				long long c3 = cube[c];
				for (int d = c; d < a; ++d) {
					long long d3 = cube[d];
					
					if (a3 == b3 + c3 + d3) {
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")\n";
					}
				}
			}
		}
	}
	
	return 0;
}
