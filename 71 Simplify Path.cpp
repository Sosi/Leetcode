// tip 1 最后的一个 / 是可以省略的.
// tip 2 ./ 是可以省略的.
// tip3 ../ 可以向前进一级.
// tip4 输入为空的时候, 返回 "/"

//以/ 分割可以简单的使用 getline

class Solution
{
public:
    string simplifyPath(string path)
    {
        string result="", token;
        stringstream ss(path);
        vector<string> tokens;
        while(getline(ss, token, '/'))
        {
            if(token=="." || token=="") continue;
            else if(token=="..")
            {
                if(tokens.size()!=0)  tokens.pop_back();
            }
            else tokens.push_back(token);
        }
        if(tokens.size()==0) return "/";
        for(int i=0; i<tokens.size(); ++i)
            result=result+'/'+tokens[i];
        return result;
    }
};
