
ol isOneDifL(string s, string t)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == t[i])
                continue;
            return s.substr(i) == t.substr(i+1);
        }
        return true; // 说明前面的都相等只有最后一个不匹配
    }
    bool isSameLen(string s, string t)
    {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
                cnt++;
        }
        return cnt == 1;
    }
    bool isOneEditDistance(string s, string t)
    {
        if (abs(s.size() - t.size()) > 1) return false;
        if (s.size() == t.size()) return isSameLen(s, t);
        else if (s.size() < t.size()) return isOneDifL(s, t);
        else return isOneDifL(t, s);
    }
