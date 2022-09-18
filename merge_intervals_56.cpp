class Solution {
public:
    static bool sortbysec(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortbysec);
        vector<vector<int>> result = {intervals[0]};

        for(int i=0; i<intervals.size(); i++){
            int lastEnd = result[result.size()-1][1];

            if(intervals[i][0] <= lastEnd){
                result[result.size()-1][1] = max(lastEnd, intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
