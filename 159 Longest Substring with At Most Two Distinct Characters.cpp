int longest159(string s)
{
    if (s.size() == 0) return 0;
    int ans = 0;

    int p1 = 0, p2 = -1, start = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (p2 == -1)
        {
            if (s[i] == s[p1])
                continue;
            p2 = i;
        }

        if (s[i] == s[p1] || s[i] == s[p2])
            s[i] == s[p1] ? p1 = i : p2 = i;
        else
        {
            start = min(p1, p2) + 1;
            p1 < p2 ? p1 = i : p2 = i;
        }
        if (max(p1, p2) - start + 1 > ans)
            ans = max(p1, p2) - start + 1;
    }
    if (p2 == -1)
        return s.size();
    return ans;
}
