class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if(s1==s2)
            return true;

        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }

        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};


class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int sSize = s1.size(), len, i, j, k;
        if(0==sSize) return true;
        if(1==sSize) return s1==s2;
        bool isS[sSize+1][sSize][sSize];

        for(i=0; i<sSize; ++i)
            for(j=0; j<sSize; ++j)
                isS[1][i][j] = s1[i] == s2[j];

        for(len=2; len <=sSize; ++len)
            for(i=0; i<=sSize-len; ++i)
                for(j=0; j<=sSize-len; ++j)
                {
                    isS[len][i][j] = false;
                    for(k=1; k<len && !isS[len][i][j]; ++k)
                    {
                        isS[len][i][j] = isS[len][i][j] || (isS[k][i][j] && isS[len-k][i+k][j+k]);
                        isS[len][i][j] = isS[len][i][j] || (isS[k][i+len-k][j] && isS[len-k][i][j+k]);
                    }
                }
        return isS[sSize][0][0];

    }
};
