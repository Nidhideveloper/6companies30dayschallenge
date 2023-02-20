class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> dp (26);
		for (int i = 0; i < s.size (); ++i) dp[s[i] - 'a'].push_back (i);
		int res = 0;

		for (auto i : words) {
			int x = -1;
			bool f = true;

			for (char c : i) {
				auto it = upper_bound (dp[c - 'a'].begin (), dp[c - 'a'].end (), x);
				if (it == dp[c - 'a'].end ()) f = false;
				else x = *it;
			}

			if (f) res++;
		}

		return res;
    }
};