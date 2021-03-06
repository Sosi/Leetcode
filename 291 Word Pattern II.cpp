class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_set<string> st;
        unordered_map<char, string> mp;
        return match(str, 0, pattern, 0, st, mp);
    }
private:
    bool match(string& str, int i, string& pat, int j, unordered_set<string>& st, unordered_map<char, string>& mp) {
        int m = str.length(), n = pat.length();
        if (i == m && j == n) return true;
        if (i == m || j == n) return false;
        char c = pat[j];
        if (mp.find(c) != mp.end()) {
            string s = mp[c];
            int l = s.length();
            if (s != str.substr(i, l)) return false;
            return match(str, i + l, pat, j + 1, st, mp);
        }
        for (int k = i; k < m; k++) {
            string s = str.substr(i, k - i + 1);
            if (st.find(s) != st.end()) continue;
            st.insert(s);
            mp[c] = s;
            if (match(str, k + 1, pat, j + 1, st, mp)) return true;
            st.erase(s);
            mp.erase(c);
        }
        return false;
    }
};
