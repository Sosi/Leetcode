#include <bits/stdc++.h>

using namespace std;

#define INF 400

class Solution
{
public:
    vector<string> greedy(vector<string> &words, int L)
    {
        vector<string> ret;
        string cur = words[0];
        for(int i = 1; i< words.size(); i++)
        {
            if(cur.size() + words[i].size() + 1 <=L)
            {
                cur += " " + words[i];
            }
            else
            {
                ret.push_back(cur);
                cur = words[i];
            }
        }
        ret.push_back(cur);
        int num = 0;
        for(int i = 0; i< ret.size(); i++)
        {
            num += L - ret[i].size();
        }
        return ret;
    }


    vector<string> dp(vector<string> &words, int L)
    {
        int n = words.size();
        vector<vector<int> > S(n+1, vector<int>(n+1, INF));
        for(int i = 1; i<= n; i++)
            S[i][i] = L - words[i-1].size();
        for(int i = 1; i<= n; i++)
        {
            for(int j = i+1; j<= n; j++)
            {
                if(S[i][j-1] == INF) continue;
                int len =S[i][j-1] - words[j-1].size() -1;
                if(len >= 0)
                    S[i][j] = len;
                else S[i][j] = INF;
            }
        }
        vector<int> dp(n+1, words.size() * L);
        dp[0] = 0;
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<=i; j++)
                dp[i] = min(S[j][i]+ dp[j-1], dp[i]);
        }
        vector<string> ret;
        function<void (vector<string>&, int)> dfs =[&](vector<string> & re, int k)
        {
            if(k == 0) return;
            for(int j = 1; j<= k; j++)
            {
                if(S[j][k] != INF && dp[k]- dp[j-1] == S[j][k])
                {
                    dfs(re, j-1);
                    string stmp = "";
                    for(int i = j; i<k; i++) stmp += words[i-1]+" ";
                    stmp+= words[k-1];
                    re.push_back(stmp);
                    return;
                }
            }
        };
        dfs(ret, n);
        int num = 0;
        for(int i = 0; i< ret.size(); i++)
            num += L - ret[i].size();
        return ret;
    }
};


int main()
{
    vector<string> s = {"This", "is", "a", "an","whatthefu", "fuck", "you", "boy", "peopel", "example", "of", "text", "justification.","wee", "are", "the ", "b", "segeinge", "gegein","xa","is","bass","he"};
    Solution S;

    for(int len = 16; len<=40; len++)
    {
        vector<string> gd = S.greedy(s, len);
        vector<string> dpp = S.dp(s, len);
        int numgd = 0;
        for(int i = 0; i< gd.size(); i++)
            numgd += len - gd[i].size();

        int numdp = 0;
        for(int i = 0;i< dpp.size(); i++)
        {
            numdp += len - dpp[i].size();
        }
        cout<<"LEN  " <<len <<" "<<numgd<<" "<<numdp<<endl;
        if(numgd != numdp) assert(0);

        if( numgd != numdp)
        {
            cout<<"gd "<<endl;
            for(auto itm: gd) cout<< itm<<endl;
            cout<<"dp "<<endl;
            for(auto itm: dpp) cout<< itm<<endl;
        }

    }
}
