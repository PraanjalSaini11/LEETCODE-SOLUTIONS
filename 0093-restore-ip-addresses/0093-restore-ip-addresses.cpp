class Solution {
public:
    vector<string> result;

    void solve(string s, int index, int parts, string ip) {
        if (parts == 4) {
            if (index == s.size()) {
                ip.pop_back();   // remove last '.'
                result.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero is not allowed
            if (part.size() > 1 && part[0] == '0')
                continue;

            // Value must be <= 255
            if (stoi(part) > 255)
                continue;

            solve(s, index + len, parts + 1, ip + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return result;
    }
};