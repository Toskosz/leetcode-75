class Solution {
public:
    unordered_map<int, vector<int>> prereqMap;
    unordered_map<int, bool> existenceMap;

    bool dfs(int curso){
        if(existenceMap.count(curso)){
            return false;
        }
        if (prereqMap[curso].size() == 0){
            return true;
        }

        existenceMap[curso] = true;
        for(int i=0; i<prereqMap[curso].size(); i++){
            if (!dfs(prereqMap[curso][i])){
                return false;
            }
        }

        existenceMap.erase(curso);
        vector<int> x;
        prereqMap[curso] = x;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<prerequisites.size();i++){
            prereqMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0; i<numCourses; i++){
            if (!dfs(i)){
                return false;
            }
        }

        return true;
    }
};
