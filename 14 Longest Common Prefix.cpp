class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ret = strs[0];
        for(int i = 1; i< strs.size(); i++)
        {
            string cur = strs[i];
            int idx = -1;
            for(int j = 0; j< (cur.size(), ret.size()); j++)
            {
                if(cur[j]!= ret[j])
                {
                    idx = j;
                    break;
                }
            }
            if(idx == -1) ;
            else ret = ret.substr(0, idx);
        }
        return ret;

    }
};
};
