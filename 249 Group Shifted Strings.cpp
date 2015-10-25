class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashmap;
        vector<vector<string>> res;

        for (int i = 0; i < strings.size(); ++i) {
            hashmap[calKey(strings[i])].push_back(strings[i]);
        }

        for (auto it = hashmap.begin(); it != hashmap.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            vector<string> tmp = it->second;
            res.push_back(tmp);
        }

        return res;
    }
private:
    string calKey(string input) {
        string key = "";
        for (int i = 0; i < input.length() - 1; ++i) {
            int gap = (input[i] > input[i+1]) ? (input[i] - input[i+1]) : (input[i] - input[i+1] + 26);
            char num = 'a' + gap;
            key += num;
        }
        return key;
    }
};
