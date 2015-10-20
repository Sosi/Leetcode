#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string fractionToDecimal(long long n, long long d)
    {
        // zero numerator
        if (n == 0) return "0";

        string res;
        // determine the sign
        if (n < 0LL ^ d < 0LL) res += '-';

        // remove sign of operands
        n = abs(n), d = abs(d);

        // append integral part
        res += to_string(n / d);

        // in case no fractional part
        if (n % d == 0) return res;

        res += '.';

        unordered_map<int, int> map;

        // simulate the division process
        for (long long r = n % d; r; r %= d)
        {

            // meet a known remainder
            // so we reach the end of the repeating part
            if (map.count(r) > 0)
            {
                res.insert(map[r], 1, '(');
                res += ')';
                break;
            }

            // the remainder is first seen
            // remember the current position for it
            map[r] = res.size();

            r *= 10;

            // append the quotient digit
            res += to_string(r / d);
        }

        return res;

    }
};


int main()
{
    Solution c;
    cout<<c.fractionToDecimal(1, 7)<<endl;
    cout<<c.fractionToDecimal(-1,-2147483648)<<endl;
}
