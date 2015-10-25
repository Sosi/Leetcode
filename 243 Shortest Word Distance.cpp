
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = -1;
        int pos2 = -1;
        int mindis = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                pos1 = i;
            }
            else if (words[i] == word2) {
                pos2 = i;
            }
            if (pos1 != -1 and pos2 != -1) {
                mindis = min(mindis, abs(pos1 - pos2));
            }
        }
        return mindis;
    }
};
