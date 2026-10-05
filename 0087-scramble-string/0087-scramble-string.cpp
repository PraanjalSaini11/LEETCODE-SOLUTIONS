class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string s1, string s2) {
        if (s1 == s2)
            return true;

        string key = s1 + "#" + s2;

        if (dp.count(key))
            return dp[key];

        int n = s1.size();

        // If character frequencies are different,
        // they cannot be scrambled versions.
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0)
                return dp[key] = false;
        }

        for (int i = 1; i < n; i++) {

            // Case 1: No swap
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i))) {
                return dp[key] = true;
            }

            // Case 2: Swap
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        return solve(s1, s2);
    }
};