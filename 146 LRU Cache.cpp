#include <bits/stdc++.h>

using namespace std;


class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator  itr= H.find(key);
        if(itr == H.end()) return -1;
        else
        {
            L.push_front(key);
            L.erase(itr->second.second);
            H[key] = {itr->second.first,L.begin()};
//            itr->second.second = L.begin();
            return itr->second.first;
        }

    }

    void set(int key, int value) {
        unordered_map<int, pair<int, list<int>::iterator>>::iterator  itr= H.find(key);
        if(itr == H.end())
        {
            if(H.size() == cap)
            {
                H.erase(L.back());
                L.pop_back();
            }
            L.push_front(key);
            H[key] = {value, L.begin()};
        }else
        {
            L.push_front(key);
            L.erase(itr->second.second);
            H[key] = {value, L.begin()};
        }
    }
    void debug()
    {
        for(auto itm: L)
        {
            cout<<itm<<endl;
        }
        for(auto itm:H)
        {
            cout<< itm.first<<" "<<itm.second.first<<" "<<*(itm.second.second) <<endl;
        }
    }

    int cap;
    // key
    list<int> L;
    // <key, <value, iterator> >
    unordered_map<int, pair<int, list<int>::iterator >> H;
};


class _LRUCache{
public:
    _LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
//        unordered_map<int, pair<int, list<int>::iterator>>::iterator  itr= H.find(key);
//        if(itr == H.end()) return -1;
//        else
//        {
//            L.push_front(key);
//            L.erase(itr->second.second);
//            H[key] = {itr->second.first,L.begin()};
////            itr->second.second = L.begin();
//            return itr->second.first;
//        }

    }

    void set(int key, int value) {
//        unordered_map<int, pair<int, list<int>::iterator>>::iterator  itr= H.find(key);
//        if(itr == H.end())
//        {
//            if(H.size() == cap)
//            {
//                H.erase(L.back());
//                L.pop_back();
//            }
//            L.push_front(key);
//            H[key] = {value, L.begin()};
//        }else
//        {
//            L.push_front(key);
//            L.erase(itr->second.second);
//            H[key] = {value, L.begin()};
//        }
    }
    void debug()
    {
        for(auto itm: L)
        {
//            cout<<itm<<endl;
        }
        for(auto itm:H)
        {
//            cout<< itm.first<<" "<<itm.second.first<<" "<<*(itm.second.second) <<endl;
        }
    }

    int cap;
    // key value
    list<int, int> L;
    // <key, , iterator>
    unordered_map<int, list<int,int>::iterator > H;
};

int main()
{
    LRUCache LRU(5);
    cout<<LRU.get(0)<<endl;
    for(int i = 0; i< 6; i++)
        LRU.set(i,i);
    LRU.debug();
    LRU.get(2);
}
