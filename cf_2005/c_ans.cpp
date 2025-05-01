#include <bits/stdc++.h>
using namespace std;

const string narek = "narek";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; // test cases

	while (t--) {
		int n, m; cin >> n >> m;

		vector<string> s(n);
		for (int i = 0; i < n; i++) cin >> s[i];

		vector<int> dp(5, int(-1e9)), ndp;
		dp[0] = 0;

		for (int i = 0; i < n; i++) {
			ndp = dp; // overwriting dp

			for (int j = 0; j < 5; j++) {
				if (dp[j] == int(-1e9)) continue;

				int counted_score = 0, next = j;

				for (int k = 0; k < m; k++) {
					int ind = narek.find(s[i][k]);

					if (ind == -1) continue; // if s[i][k] is not a letter of "narek"

					if (next == ind) { // if s[i][k] is the next letter
						next = (next + 1) % 5;
						counted_score++;
					}
					else counted_score--;
				}

				ndp[next] = max(ndp[next], dp[j] + counted_score);
			}

			dp = ndp; // overwriting dp back
		}

		int ans = 0;
		for (int i = 0; i < 5; i++) ans = max(ans, dp[i] - 2 * i); // checking all letters

		cout << ans << "\n";
	}
}
