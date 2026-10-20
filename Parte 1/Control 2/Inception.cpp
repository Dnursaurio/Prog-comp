#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct Consulta {
	string tipo;
	string nombre;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	if (!(cin >> n)) return 0;
	
	// Primero leemos todas las entradas
	vector<Consulta> q(n);
	for (int i = 0; i < n; i++) {
		cin >> q[i].tipo;
		if (q[i].tipo == "Sleep") {
			cin >> q[i].nombre;
		}
	}
	
	// Procesamiento con pila (LIFO) para los sueños dentro de sueños
	stack<string> suenos;
	for (int i = 0; i < n; i++) {
		if (q[i].tipo == "Sleep") {
			suenos.push(q[i].nombre);
		} else if (q[i].tipo == "Kick") {
			if (!suenos.empty()) {
				suenos.pop();
			}
		} else if (q[i].tipo == "Test") {
			if (suenos.empty()) {
				cout << "Not in a dream\n";
			} else {
				cout << suenos.top() << "\n";
			}
		}
	}
	
	return 0;
}
