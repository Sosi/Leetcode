
class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        int len = intervals.size(),i,cur;
        vector<Interval> res(intervals);
        if(len>1)
        {
            std::sort(res.begin(), res.end(), [](Interval i, Interval j)
            {
                return i.start<j.start;
            });
            for(cur=0, i=1; i<len; ++i)
                if(res[cur].end<res[i].start) res[++cur] = res[i]; // no overlapping, copy to cur+1,
                else res[cur].end = max(res[cur].end, res[i].end); // cur and i overlap with each other, merge
            res.resize(cur+1); // resize to remove redundant intervals
        }
        return res;
    }
};
