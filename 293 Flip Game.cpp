class Solution
{
public:
    vector<string> generatePossibleNextMoves(string s)
    {
        vector<string> result;

        for (int i = 0; i < s.length() - 1; i++)
        {
            string s1 = s;
            if (s[i] == '+' && s[i + 1] == '+')
            {
                s1[i] = s1[i + 1] = '-';
                result.push_back(s1);
            }
        }
        return result;
    }
};
