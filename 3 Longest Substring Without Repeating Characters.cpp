class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> Hash;
        int ret  = 0, cur = -1;
        for(int i = 0; i< s.size(); i++)
        {
            if(Hash.find(s[i]) != Hash.end())
                cur = max(Hash[s[i]],cur);
            ret = max(ret, i - cur);
            Hash[s[i]] = i;
        }
        return ret;
    }
};
