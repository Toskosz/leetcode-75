class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> grouped_anagrams;
        map<string,vector<string>> sort_to_string;
        for(int i=0; i<strs.size(); i++){
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            sort_to_string[sortedWord].push_back(strs[i]);
        }
        map<string,vector<string>>::iterator it;
        for (it = sort_to_string.begin(); it != sort_to_string.end(); it++){
            grouped_anagrams.push_back(it->second);
        }
        return grouped_anagrams;
    }
};

