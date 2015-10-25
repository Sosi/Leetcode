
bool canPermutePalindrome(string s)
{
    unordered_map<char, int> hash;
    int odd_cnt = 0;
    for(char c:s)
    {
        hash[c]++;
        if(hash[c]%2==1)
        {
            odd_cnt++;
        }
        else
        {
            odd_cnt--;
        }
    }
    return odd_cnt<=1;
}
