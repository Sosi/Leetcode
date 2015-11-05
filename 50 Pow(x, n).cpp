class Solution {
public:
    double myPow(double x, int m) {
        double tmp = x;
        double ret = 1.0;
        int n = abs(m);
        while(n > 0)
        {
            if(n%2 == 1) ret *= tmp;
            tmp = tmp*tmp;
            n/=2;
        }
        if(m < 0) return 1.0/ret;
        return ret;
    }
};
