class Solution
{
public:
    string minWindow(string S, string T)
    {
        int m = S.size(), n = T.size();
        if (n <= 0 || m < n) return "";

        int require[128] = {0};
        for (int i = 0; i < n; ++i) require[T[i]]++;

        int count = 0;
        int minLen = INT_MAX, minIndex = 0;
        for (int s = 0, e = 0; e < m; ++e)
        {
            require[S[e]]--;
            if (require[S[e]] >= 0) count++;
            while (count == n)
            {
                if (e - s + 1 < minLen)
                {
                    minLen = e - s + 1;
                    minIndex = s;
                }
                require[S[s]]++;
                if (require[S[s]] > 0) count--;
                s++;
            }
        }

        if (minLen == INT_MAX) return "";
        return S.substr(minIndex, minLen);
    }
};
