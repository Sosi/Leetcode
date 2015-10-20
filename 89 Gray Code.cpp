vector<int> grayCode(int n) {
    vector<int>r;
    for (int i = 0; i < 1<<n; i++)
    {
        r.push_back(i>>1 ^ i);
    }
    return r;
}
