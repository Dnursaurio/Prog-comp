#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_open(int type) { return type >= 1 && type <= 5; }

int get_type(const string& line, size_t& i) {
	if (i + 1 < line.size() && line[i] == '(' && line[i + 1] == '*') { i += 2; return 5; } // (*
	if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == ')') { i += 2; return -5; } // *)
	char c = line[i++];
	if (c == '(') return 1;
	if (c == ')') return -1;
	if (c == '[') return 2;
	if (c == ']') return -2;
	if (c == '{') return 3;
	if (c == '}') return -3;
	if (c == '<') return 4;
	if (c == '>') return -4;
	return 0; // Carácter normal
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while (getline(cin, line)) {
		vector<int> st;
		size_t i = 0;
		int pos = 0, err_pos = 0;
		bool ok = true;
		
		while (i < line.size()) {
			pos++;
			int type = get_type(line, i);
			if (type == 0) continue;
			
			if (is_open(type)) {
				st.push_back(type);
			} else {
				if (st.empty() || st.back() != -type) {
					ok = false;
					err_pos = pos;
					break;
				}
				st.pop_back();
			}
		}
		
		if (ok && !st.empty()) {
			ok = false;
			err_pos = pos + 1;
		}
		
		if (ok) cout << "YES\n";
		else cout << "NO " << err_pos << "\n";
	}
	return 0;
}
