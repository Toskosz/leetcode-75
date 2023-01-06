class Solution {
public:
    bool isValid(string s) {
        vector<char> pilha;
        map<char, char> m;
        m['}'] = '{';
        m[']'] = '[';
        m[')'] = '(';



        for (int i=0; i<s.length(); i++){
            if (pilha.size() == 0){
                pilha.push_back(s[i]);
            } else {
                if (m[s[i]] == pilha[pilha.size() - 1]){
                    pilha.pop_back();
                } else {
                    pilha.push_back(s[i]);
                }
            }
        }

        return pilha.size() == 0;
    }
};
