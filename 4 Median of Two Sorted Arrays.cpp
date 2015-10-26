
class Solution
{
public:
    int getkth(int s[], int m, int l[], int n, int k)
    {
        // let m <= n
        if (m > n)
            return getkth(l, n, s, m, k);
        if (m == 0)
            return l[k - 1];
        if (k == 1)
            return min(s[0], l[0]);

        int i = min(m, k / 2), j = min(n, k / 2);
        if (s[i - 1] > l[j - 1])
            return getkth(s, m, l + j, n - j, k - j);
        else
            return getkth(s + i, m - i, l, n, k - i);
        return 0;
    }

    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
    {
        int m= A.size(); int n = B.size();
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (getkth(A.data(), m ,B.data(), n, l) + getkth(A.data(), m, B.data(), n, r)) / 2.0;
    }
};

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
    {
        int m= A.size(); int n = B.size();
        if (m > n) return findMedianSortedArrays(B,A);
        int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) >> 1,num2;
        while (minidx <= maxidx)
        {
            i = (minidx + maxidx) >> 1;
            j = mid - i;
            if (i<m && j>0 && B[j-1] > A[i]) minidx = i + 1;
            else if (i>0 && j<n && B[j] < A[i-1]) maxidx = i - 1;
            else
            {
                if (i == 0) num1 = B[j-1];
                else if (j == 0) num1 = A[i - 1];
                else num1 = max(A[i-1],B[j-1]);
                break;
            }
        }
        if (((m + n) & 1)) return num1;
        if (i == m) num2 = B[j];
        else if (j == n) num2 = A[i];
        else num2 = min(A[i],B[j]);
        return (num1 + num2) / 2.;
    }
};
