class Solution {
public:
    int numDecodings(string s) {
        set<string> con;
        for(int i = 1; i<= 26; i++) con.insert(to_string(i));

        if(s.size() == 0) return 0;
        vector<int> dp(s.size(), 0);
        if(con.find(s.substr(0,1))== con.end()) return 0;
        else dp[0] = 1;
        if(s.substr(0,2) == "10" || s.substr(0,2) == "20") dp[1] = 1;
        else  if(con.find(s.substr(0,2))!= con.end()) dp[1] = 2;
        else if(s[1] == '0') return 0; else dp[1] = 1;

        for(int i = 2; i< s.size(); i++)
        {
            if(con.find(s.substr(i,1))!= con.end()) dp[i] += dp[i-1];
            if(con.find(s.substr(i-1,2))!= con.end()) dp[i] += dp[i-2];
            if(con.find(s.substr(i-1,2))== con.end() && con.find(s.substr(i,1)) == con.end())
                return 0;
        }
        return dp[s.size() -1];
    }
};
