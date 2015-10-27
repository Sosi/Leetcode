
class Solution
{
public:

    // Wrong solution.
    int longestValidParentheses(string s)
    {
        stack<int> st;
        int ret = 0;

        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                if(!st.empty())
                {
                    ret = max(ret, i - st.top()+1);
                    st.pop();
                }
                else continue;
            }
        }
        return ret;
    }

    // DP  solution.
    // 以 dp[i] 结尾的最长的长度是多少?
    int longestValidParentheses(string s)
    {
        if(s.length() <= 1) return 0;
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
                    curMax = max(longest[i],curMax);
                }
                else  // if s[i-1] == ')', combine the previous length.
                {
                    if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '(')
                    {
                        longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
                        curMax = max(longest[i],curMax);
                    }
                }
            }
            //else if s[i] == '(', skip it, because longest[i] must be 0
        }
        return curMax;
    }

    // correct solution
    int longestValidParentheses(string s)
    {
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') st.push(i);
            else
            {
                if (!st.empty())
                {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) longest = n;
        else
        {
            int a = n, b = 0;
            while (!st.empty())
            {
                b = st.top();
                st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};

public int longestValidParentheses(String s)
{
    char[] S = s.toCharArray();
    int[] V = new int[S.length];
    int open = 0;
    int max = 0;
    for (int i=0; i<S.length; i++)
    {
        if (S[i] == '(') open++;
        if (S[i] == ')' && open > 0)
        {
            // matches found
            V[i] = 2+ V[i-1];
            // add matches from previous
            if(i-V[i]>0)
                V[i] += V[i-V[i]];
            open--;
        }
        if (V[i] > max) max = V[i];
    }
    return max;
}
