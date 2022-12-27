class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> resultado;
        
        for(int i=0; i<intervals.size(); i++){
            if (newInterval[1] < intervals[i][0]){
                resultado.push_back(newInterval);
                resultado.insert( resultado.end(), intervals.begin()+i, intervals.end() );
                return resultado;
            } else if (newInterval[0] > intervals[i][1]){
                resultado.push_back(intervals[i]);
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        resultado.push_back(newInterval);
        return resultado;
    }
};
