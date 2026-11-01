class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string beginWord) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else {
            for (string parent : adj[word]) {
                dfs(parent, beginWord);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord)) return {};

        queue<string> q;
        unordered_map<string, int> dist;

        q.push(beginWord);
        dist[beginWord] = 0;

        int minDist = INT_MAX;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int d = dist[word];

            if (d >= minDist) continue;

            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (st.count(temp)) {
                        if (!dist.count(temp)) {
                            dist[temp] = d + 1;
                            q.push(temp);
                        }

                        if (dist[temp] == d + 1) {
                            adj[temp].push_back(word);
                        }

                        if (temp == endWord) {
                            minDist = d + 1;
                        }
                    }
                }
            }
        }

        if (dist.count(endWord)) {
            dfs(endWord, beginWord);
        }

        return ans;
    }
};