class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int p1 = -1, p2 = -1, dist = INT_MAX;
        for(int i=0; i<n; ++i){
            if(word1==word2){
                if(words[i]==word1){
                    if(p1>p2) p2 = i;
                    else p1 = i;
                }
            }else{
                if(words[i]==word1) p1 = i;
                if(words[i]==word2) p2 = i;
            }
            if(p1>=0 && p2>=0)
                dist = min(dist, abs(p1-p2));
        }
        return dist;
    }
};
