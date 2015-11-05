// tip 1 ����һ�� / �ǿ���ʡ�Ե�.
// tip 2 ./ �ǿ���ʡ�Ե�.
// tip3 ../ ������ǰ��һ��.
// tip4 ����Ϊ�յ�ʱ��, ���� "/"

//��/ �ָ���Լ򵥵�ʹ�� getline

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
