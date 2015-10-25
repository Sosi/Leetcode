class ValidWordAbbr
{
    unordered_map<string, vector<string>> abbs;
public:
    string getAbb(string s)
    {
        int n = s.size();
        if(n<=2) return s;
        else return s.substr(0,1)+to_string(n-2)+s.substr(n-1,1);
    }

    ValidWordAbbr(vector<string> &dictionary)
    {

        for(auto w:dictionary)
        {

            abbs[getAbb(w)].push_back(w);

        }

    }

    bool isUnique(string word)
    {

        string key = getAbb(word);

        return abbs.count(key)==0 || ((int)abbs[key].size()==1&&abbs[key][0]==word);

    }

};
