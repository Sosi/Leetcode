#include <bits/stdc++.h>

using namespace std;


map< multiset<int>, int> SG;
map<int,int> _SG;
int sg(multiset<int> x)
{
    if(SG.find(x) != SG.end()) return SG[x];
    vector<int> s;  // ��׺��ֵ
    for(auto itm:x)
    {
        if(itm >= 2)
        {
            multiset<int> y(x);
            y.erase(y.find(itm));
            for(int i = 0; i<= (itm - 2)/2;i++)
            {
                y.insert(i);
                y.insert(itm - i-2);
                s.push_back(sg(y));
                y.erase(y.find(i));
                y.erase(y.find(itm-i-2));
            }

        }
    }

    int p = 0;
    sort(s.begin(), s.end());

//    if( x == {2,2})
//    {
//        multiset<int> y = {2,2};
//        if(x == y)
//        {
//            for(auto xx: s) cout<<xx<<" ";
//            cout<<"???"<<endl;
//        }
//
//    }
    for(int i = 0;i< s.size();i++)
    {
        if(s[i] == p) p++;
        else if(s[i] < p) continue;
        else break;
    }
    SG[x]  = p;
    return p;
}

int _sg(int x)
{
    if(_SG.find(x) != _SG.end()) return _SG[x];
    vector<int> p;
    for(int i = 0;i<= (x-2)/2; i++)
    {
        p.push_back(_SG[i]^_SG[x - 2- i]);
    }
    int y = 0;
    sort(p.begin(), p.end());
    for(int i = 0;i< p.size();i++)
    {
        if(p[i] == y) y++;
        else if(p[i] < y ) continue;
        else break;
    }
    _SG[x]  = y;
    return y;
}
int main()
{
    SG[{}] = 0;
    SG[{0}] = 0; SG[{1}] = 0;
    SG[{0,0}] = 0; SG[{0,1}] = 0;
    SG[{1,1}] = 0;

//    for(int i = 1;i< 30; i++)
//    {
//        cout<<i<<" "<<sg({i})<<endl;
//
////        for(auto a : SG)
////        {
////            cout<<"{ ";
////            for(auto b: a.first)
////                cout<<b<<" ";
////            cout<<"} ";
////            cout<<a.second<<endl;
////        }
////
////        cout<<"-------------"<<endl;
//
//    }

    _SG[0] = 0; _SG[1] = 0;
     for(int i = 1;i< 60; i++)
     {
         cout<<i<<"----"<<endl;
         if(sg({i}) == _sg(i)) continue;
         else cout<<"====================="<<endl;
     }
//        cout<<i<<" "<<_sg(i)<<endl;
//    }


//
//    for(int i = 1; i<25; i++)
//    {
//        string s;
//        s.resize(i);
//        for(int j = 0; j< i; j++) s[j] = '+';
//        cout<<i<<" "<<s<<canW(s)<<endl;
//    }

}
