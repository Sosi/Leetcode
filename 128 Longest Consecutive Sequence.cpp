#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int ret = 0;
        unordered_map<int,int> m;

        for(auto k: nums)
        {
            if(m.find(k) == m.end())
            {
                int left = m.find(k-1) == m.end()?0:m[k-1];
                int right = m.find(k+1) == m.end()?0: m[k+1];

                int interval = left + right + 1;

                m[k] = interval;

                m[k - left] = interval;
                m[k + right] = interval;

                ret = max(ret, interval);
            }
            else continue;
        }
        return ret;
    }
};


int main()
{

}
