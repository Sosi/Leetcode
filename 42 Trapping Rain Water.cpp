#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:

    int ano(vector<int> height, bool flag)
    {
        if(!flag) reverse(height.begin(), height.end());
//        for(int i = 0; i< height.size(); i++) cout<<height[i]<<" "; cout<<endl;
        vector<int> left;
        for(int i = 0; i< height.size(); i++)
        {
            if(left.size() != 0 && height[i] > height[left[left.size() -1]])
                left.push_back(i);
            else if(left.size() == 0 && height[i] != 0)
                left.push_back(i);
        }
        int ret = 0;
//        for(auto itm: left) cout<<itm<<" "; cout<<endl;
        for(int i = 0; i< left.size()-1; i++)
        {
            int h = height[ left[i]];
            for(int j = left[i]+1; j< left[i+1]; j++)
                ret += h - height[j];
        }
        return ret;
    }

    int trap(vector<int>& height)
    {
        if(height.size() == 0) return 0;
        auto itr = max_element(height.begin(), height.end());
        (*itr) ++;
        return ano(vector<int>(height.begin(), itr + 1), true) + ano(vector<int>(itr, height.end()), false);
    }



    //========


    int trap(int A[], int n)
    {
        int left=0;
        int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right)
        {
            if(A[left]<=A[right])
            {
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else
            {
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }

};

int main()
{
    Solution c;
    vector<int> x = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<c.trap(x);
}
