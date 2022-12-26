class Solution {
public:

    void dfs(int l, int c, set<tuple<int,int>>& visitados, int alturaAnterior, vector<vector<int>>& heights, int LINHAS, int COLUNAS){
        tuple <int,int> t(l,c);
        bool dentro = visitados.find(t) != visitados.end();
        if ( dentro || l<0 || c<0 || l==LINHAS || c==COLUNAS|| heights[l][c] < alturaAnterior){
            return;
        }
        visitados.insert(t);
        dfs(l+1, c, visitados, heights[l][c], heights, LINHAS, COLUNAS);
        dfs(l-1, c, visitados, heights[l][c], heights, LINHAS, COLUNAS);
        dfs(l, c+1, visitados, heights[l][c], heights, LINHAS, COLUNAS);
        dfs(l, c-1, visitados, heights[l][c], heights, LINHAS, COLUNAS);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int LINHAS = heights.size();
        int COLUNAS = heights[0].size();
        std::set<tuple<int,int>> pac;
        std::set<tuple<int,int>> atl;

        for (int c=0; c<COLUNAS; c++){
            dfs(0, c, pac, heights[0][c], heights, LINHAS, COLUNAS);
            dfs(LINHAS-1, c, atl, heights[LINHAS-1][c], heights, LINHAS, COLUNAS);
        }

        for (int l=0; l<LINHAS; l++){
            dfs(l, 0, pac, heights[l][0], heights, LINHAS, COLUNAS);
            dfs(l, COLUNAS-1, atl, heights[l][COLUNAS-1], heights, LINHAS, COLUNAS);
        }

        vector<vector<int>> resultado;

        for(int l=0; l<LINHAS; l++){
            for(int c=0; c<COLUNAS; c++){
                tuple <int,int> t(l,c);
                bool dentroPac = pac.find(t) != pac.end();
                bool dentroAtl = atl.find(t) != atl.end();
                if (dentroPac && dentroAtl){
                    vector<int> vect{l,c};
                    resultado.push_back(vect);
                }
            }
        }

        return resultado;
    }
};
