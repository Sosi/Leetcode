class Solution
{
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res)
    {
        if (i == j-1)
        {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++)
        {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};


class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int> &S)
    {
        // res.clear();
        sort(S.begin(), S.end());
        res.push_back(S);
        int j;
        int i = S.size()-1;
        while (1)
        {
            for (i=S.size()-1; i>0; i--)
            {
                if (S[i-1]< S[i])
                {
                    break;
                }
            }
            if(i == 0)
            {
                break;
            }

            for (j=S.size()-1; j>i-1; j--)
            {
                if (S[j]>S[i-1])
                {
                    break;
                }
            }
            swap(S[i-1], S[j]);
            reverse(S, i, S.size()-1);
            res.push_back(S);
        }
        return res;
    }
    void reverse(vector<int> &S, int s, int e)
    {
        while (s<e)
        {
            swap(S[s++], S[e--]);
        }
    }

    vector<vector<int> > res;
};
