class Solution {
public:

    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        if (vec1[0] == vec2[0]){
            return vec1[1] < vec2[1];
        }
        return vec1[0] < vec2[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int resultado = 0;
        int ref = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= ref){
                ref = intervals[i][1];
            } else {
                resultado++;
                ref = min(intervals[i][1],ref);
            }
        }

        return resultado;
    }
};
