#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	vector<string> in;
	while (getline(cin, line)) in.push_back(line);
	vector<string> out;
	for (size_t idx = 0; idx < in.size(); ++idx) {
		string s = in[idx];
		vector<pair<int, int> > st;
		bool ok = 1;
		int err = -1, n = s.length();
		for (int i = 0; i < n; ) {
			int p = i + 1, t = 0;
			if (i + 1 < n && s[i] == '(' && s[i+1] == '*') { t = 5; i += 2; }
			else if (i + 1 < n && s[i] == '*' && s[i+1] == ')') { t = -5; i += 2; }
			else {
				char c = s[i];
				if (c == '(') t = 1; else if (c == '[') t = 2; else if (c == '{') t = 3; else if (c == '<') t = 4;
				else if (c == ')') t = -1; else if (c == ']') t = -2; else if (c == '}') t = -3; else if (c == '>') t = -4;
				i++;
			}
			if (t > 0) st.push_back(make_pair(t, p));
			else if (t < 0) {
				if (st.empty() || st.back().first != -t) { ok = 0; err = p; break; }
				st.pop_back();
			}
		}
		if (ok && !st.empty()) { ok = 0; err = st.back().second; }
		if (ok) out.push_back("YES");
		else {
			stringstream ss;
			ss << "NO " << err - 2;
			out.push_back(ss.str());
		}
	}
	for (size_t i = 0; i < out.size(); ++i) cout << out[i] << "\n";
	return 0;
}
