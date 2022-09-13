class Solution {
public:
    int numDecodings(string s) {
        map<int, int> cache;
        cache[s.size()] = 1;

        for(int i=s.size()-1; i>-1; i--){
            if(s[i]=='0'){
                cache[i] = 0;
            } else {
                cache[i] = cache[i+1];
            }

            if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1] < 55))){
                cache[i] = cache[i] + cache[i+2];
            }
        }
        return cache[0];
    }
};
