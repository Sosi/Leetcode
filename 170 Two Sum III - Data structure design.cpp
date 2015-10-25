
include <iostream>
include <vector>
include <algorithm>
using namespace std;
class TwoSum
{
private:
    std::vector<int> v;
public:
    void add(int a);
    bool find(int a);
};
void TwoSum::add(int a)
{
    v.push_back(a);
}
bool TwoSum::find(int x)
{
    int a, b;
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        a = *it;
        b = x - a;
        auto iter = std::find(v.begin(), v.end(), b);
        if(iter != v.end() && iter != it)
            return true;
    }
    return false;
}
int main()
{
    TwoSum ts;
    ts.add(1);
    ts.add(3);
    ts.add(1);
    cout << ts.find(2) << endl;
    return 0;
}
