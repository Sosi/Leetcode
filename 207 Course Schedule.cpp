class Solution
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> matrix(numCourses); // save this directed graph
        for(int i = 0; i < prerequisites.size(); ++ i)
            matrix[prerequisites[i].second].insert(prerequisites[i].first);

        vector<int> d(numCourses, 0); // in-degree
        for(int i = 0; i < numCourses; ++ i)
            for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
                ++ d[*it];

        for(int j = 0, i; j < numCourses; ++ j)
        {
            for(i = 0; i < numCourses && d[i] != 0; ++ i); // find a node whose in-degree is 0

            if(i == numCourses) // if not find
                return false;

            d[i] = -1;
            for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
                -- d[*it];
        }

        return true;
    }
};
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<unordered_set<int>> matrix(numCourses); // save this directed graph
        for(int i = 0; i < prerequisites.size(); ++ i)
            matrix[prerequisites[i].second].insert(prerequisites[i].first);

        unordered_set<int> visited;
        vector<bool> flag(numCourses, false);
        for(int i = 0; i < numCourses; ++ i)
            if(!flag[i])
                if(DFS(matrix, visited, i, flag))
                    return false;
        return true;
    }
    bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
    {
        flag[b] = true;
        visited.insert(b);
        for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
            if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
                return true;
        visited.erase(b);
        return false;
    }
};
