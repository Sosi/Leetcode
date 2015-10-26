
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        int ret = 0;

        for(int i = 0;i< s.size(); i++)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                if(!st.empty())
                {
                    ret = max(ret, i - st.top()+1);
                    st.pop();
                }else continue;
            }
        }
        return ret;
    }

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

public int longestValidParentheses(String s) {
    char[] S = s.toCharArray();
    int[] V = new int[S.length];
    int open = 0;
    int max = 0;
    for (int i=0; i<S.length; i++) {
        if (S[i] == '(') open++;
        if (S[i] == ')' && open > 0) {
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
