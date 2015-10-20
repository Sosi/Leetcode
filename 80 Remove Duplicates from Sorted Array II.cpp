int removeDuplicates(vector<int> & A)
{
    int n = A.size();
    int k = 2;
    if (n <= k) return n;
    int i = 1, j = 1;
    int cnt = 1;
    while (j < n)
    {
        if (A[j] != A[j-1])
        {
            cnt = 1;
            A[i++] = A[j];
        }
        else
        {
            if (cnt < k)
            {
                A[i++] = A[j];
                cnt++;
            }
        }
        ++j;
    }
    return i;
}
