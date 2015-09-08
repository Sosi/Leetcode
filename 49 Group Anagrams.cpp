class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, int> hash;
        string ori;
        for(int i=0; i<strs.size(); i++)
        {
            ori = strs[i];
            sort(ori.begin(), ori.end());
            if(hash.count(ori)>0)
            {
                ans[hash[ori]].push_back(strs[i]);
            }
            else
            {
                hash[ori]=ans.size();
                ans.push_back(vector<string>(1, strs[i]));
            }
        }
        for(int i=0; i<ans.size(); i++)
        {
            sort(ans[i].begin(), ans[i].end()); //can use other method
        }
        return ans;
    }

};

