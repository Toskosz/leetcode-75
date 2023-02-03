class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> contador;
        for(int i=0; i<nums.size(); i++){
            if (contador.find(nums[i]) == contador.end()) {
                contador[nums[i]] = 1;
            } else {
                contador[nums[i]]++;
            }
        }

        vector<vector<int>> qntd_elementos(nums.size()+1);
        for (auto i : contador){
            qntd_elementos[i.second].push_back(i.first);
        }

        vector<int> resultado;
        for (int i=qntd_elementos.size()-1; i>=0; i--){
            for (int j=0; j<qntd_elementos[i].size(); j++){
                resultado.push_back(qntd_elementos[i][j]);
                if (resultado.size() == k) {
                    return resultado;
                }
            }
        }
        return resultado;
    }
};

