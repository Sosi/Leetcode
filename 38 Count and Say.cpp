class Solution
{
public:

    std::string countAndSay(int n)
    {

        if (0 == n) return "";
        if (1 == n) return "1";

        std::string res="1";
        std::string s;

        for (int i = 1; i < n; i++)     // run from starting to generate second string
        {

            int len = res.size();

            //cheack all digits in the string
            for (int j = 0; j < len; j++)
            {

                int count=1; // we have at least 1 occourence of each digit

                // get the number of times same digit occurred (be carefull with the end of the string)
                while ((j + 1 < len) && (res[j] == res[j + 1]))
                {
                    count++;
                    j++;        // we need to keep increasing the index inside of the string
                }

                // add to new string "count"+"digit itself"
                s += std::to_string(count) + res[j];
            }

            // save temporary result
            res = s;

            // clean our string-helper
            s.clear();

        }

        return res;
    }
};
