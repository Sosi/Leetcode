class Solution {
public:
int ladderLength(string start, string end, unordered_set<string> &dict)
{
    if (dict.empty() || dict.find(start) == dict.end() || dict.find(end) == dict.end())
        return 0;

    queue<string> q;
    q.push(start);
    unordered_map<string, int> visited;  // visited track the distance
    visited[start] = 1;
    unordered_set<string> unvisited = dict;  // unvisited prevent searching through the whole dict
    unvisited.erase(start);

    while (!q.empty()) {
        string word = q.front(); q.pop();
        auto itr = unvisited.begin();
        while (itr != unvisited.end()) {
            string adjWord = *itr;
            if (oneCharDiff(word, adjWord)) {
                visited[adjWord] = visited[word] + 1;
                if (adjWord == end)
                    return visited[adjWord];
                itr = unvisited.erase(itr);  // tricky here
                q.push(adjWord);
            }
            else
                ++itr;
        }
    }
    return 0;
}

inline bool oneCharDiff(const string& str1, const string& str2)
{
    int diff = 0;
    for (int i = 0; i < str1.size(); ++i)  {
        if (str1[i] != str2[i])
            ++diff;
        if (diff > 1)
            return false;  // perhaps quicker
    }
    return diff == 1;
}
};
