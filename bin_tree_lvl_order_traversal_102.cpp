/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultado;
        list<TreeNode*> fila;
        vector<int> mesmo_nivel;
        int qntd_nivel;
        fila.push_back(root);

        while (fila.size() > 0){
            qntd_nivel = fila.size();
            mesmo_nivel.clear();
            for(int i=0; i<qntd_nivel; i++){
                if (fila.front()){
                    mesmo_nivel.push_back(fila.front()->val);
                    fila.push_back(fila.front()->left);
                    fila.push_back(fila.front()->right);   
                }
                fila.pop_front();
            }
            if (mesmo_nivel.size() > 0){
                resultado.push_back(mesmo_nivel);
            }
        }

        return resultado;

    }
};

