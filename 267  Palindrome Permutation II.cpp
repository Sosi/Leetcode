class Solution
{
public:
    vector<string> generatePalindromes(string s)
    {
        vector<string> output;
        unordered_map<char,int> ht;
        for(auto &c : s)
            ht[c]++;
        char oddChar;
        int count = 0;
        string str = "";
        for(auto &pair : ht)
        {
            str += string(pair.second/2, pair.first);
            if(pair.second&1)
            {
                count++;
                oddChar = pair.first;
                if(count==2)  return output;
            }
        }
        sort(str.begin(), str.end());
        do
        {
            output.push_back(str+(count==0?"":string(1,oddChar))+string(str.rbegin(),str.rend()));
        }
        while(std::next_permutation(str.begin(), str.end()));

        return output;
    }
};
