class ZigzagIterator
{
    int idx;
    int sz1;
    int sz2;
    vector<int> vec1;
    vector<int> vec2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        idx = 0;
        sz1 = v1.size();
        sz2 = v2.size();
        vec1 = v1;
        vec2 = v2;
    }

    int next()
    {
        int v;
        if(idx/2<sz1 && idx/2<sz2)
        {
            if(idx%2==0) v = vec1[idx/2];
            else v = vec2[idx/2];
        }
        else
        {
            if(sz1<sz2) v = vec2[idx-sz1];
            else v = vec1[idx-sz2];
        }
        idx++;
        return v;
    }

    bool hasNext()
    {
        return idx<sz1+sz2;
    }
};

