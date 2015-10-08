#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> insert(vector<Interval>& in, Interval ne)
    {
        int left_idx = -1;
        for(int i = 0; i< in.size(); i++)
        {
            if( ne.end < in[i].start || ne.start > in[i].end) continue;
            left_idx = i;
            break;
        }
        int right_idx = -1;
        for(int i = in.size() -1; i>=0; i--)
        {
            if( ne.end < in[i].start || ne.start > in[i].end) continue;
            right_idx = i;
            break;
        }

        vector<Interval> ret;
        if(left_idx != -1 && right_idx != -1)
        {
            for(int i= 0; i< left_idx; i++)
                ret.push_back(in[i]);

            ret.push_back( Interval( min(in[left_idx].start, ne.start), max(in[right_idx].end, ne.end) ));
            for(int i = right_idx+1; i< in.size(); i++)
                ret.push_back(in[i]);
        }else
        {
            if(in.size() == 0) ret.push_back(ne);
            else
            {
                for(int i = 0; i< in.size(); i++)
                {
                    if(in[i].start < ne.start)
                        ret.push_back(in[i]);
                    else break;
                }
                ret.push_back(ne);
                for(int i = 0; i< in.size(); i++)
                {
                    if(in[i].start > ne.start)
                        ret.push_back(in[i]);
                }
            }
        }
        return ret;
    }
};


int main()
{

}
