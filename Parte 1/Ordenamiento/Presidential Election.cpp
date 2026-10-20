#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Candidate {
	int id;
	long long votes;
};

bool cmp(const Candidate& a, const Candidate& b) {
	if (a.votes != b.votes)
		return a.votes > b.votes;
	return a.id < b.id;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	if (!(cin >> t)) return 0;
	bool first_case = true;
	while (t--) {
		int a, b;
		cin >> a >> b;
		vector<long long> cand_votes(a + 1, 0);
		long long total_voters = 0;
		for (int i = 0; i < b; ++i) {
			vector<double> p(a);
			for (int j = 0; j < a; ++j) {
				cin >> p[j];
			}
			long long v;
			cin >> v;
			total_voters += v;
			for (int j = 0; j < a; ++j) {
				long long cur_votes = llround(p[j] * v / 100.0);
				cand_votes[j + 1] += cur_votes;
			}
		}
		
		vector<Candidate> cands(a);
		for (int i = 1; i <= a; ++i) {
			cands[i - 1] = {i, cand_votes[i]};
		}
		sort(cands.begin(), cands.end(), cmp);
		
		if (!first_case) {
			cout << "\n";
		}
		first_case = false;
		
		double top_pct = (double)cands[0].votes * 100.0 / total_voters;
		if (top_pct >= 50.1) {
			cout << cands[0].id << " " << cands[0].votes << "\n";
		} else {
			cout << cands[0].id << " " << cands[0].votes << "\n";
			cout << cands[1].id << " " << cands[1].votes << "\n";
		}
	}
	return 0;
}
