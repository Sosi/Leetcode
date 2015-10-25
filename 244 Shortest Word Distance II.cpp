class WordDistance
{
    unordered_map<string, vector<int>> hash;
public:
    WordDistance(vector<string> words)
    {
        int n = words.size();
        for(int i=0; i<n; ++i)
        {
            hash[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2)
    {
        vector<int> pos1 = hash[word1];
        vector<int> pos2 = hash[word2];
        int dist = INT_MAX;
        for(auto p1:pos1)
        {
            for(auto p2:pos2)
            {
                dist = min(dist, abs(p1-p2));
            }
        }
        return dist;
    }
};
