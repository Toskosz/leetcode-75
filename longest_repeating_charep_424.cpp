class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> char_freq;
        int res = 0;
        int l = 0;
        int max_freq = 0;

        for (int r=0; r<s.size(); r++){
            if (char_freq.count(s[r]) == 0){
                char_freq[s[r]] = 1;
            } else {
                char_freq[s[r]]++;
            }

            max_freq = max(max_freq, char_freq[s[r]]);

            while((r-l+1) - max_freq > k){
                char_freq[s[l]]--;
                l++;
            }

            res = max(res, r-l+1);
        }

        return res;
    }
};

