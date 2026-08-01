#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int n;

    int Find(int x, vector<int>& parent) {
        return (x == parent[x]) ? x : (parent[x] = Find(parent[x], parent));
    }

    int getnode(int i, int j) {
        return (n * i + j);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        x = Find(x, parent);
        y = Find(y, parent);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size(); 
        if (n == 1) return 0;

        int total_nodes = n * n;
        vector<int> parent(total_nodes);
        vector<int> rank(total_nodes, 1);

        for (int i = 0; i < total_nodes; i++) {
            parent[i] = i;
        }

        vector<vector<int>> cells;
        cells.reserve(total_nodes);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (const auto& cell : cells) {
            int elevation = cell[0];
            int r = cell[1];
            int c = cell[2];
            int u = getnode(r, c);

            visited[r][c] = true;

            for (const auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc]) {
                    int v = getnode(nr, nc);
                    Union(u, v, parent, rank);
                }
            }
            if (Find(0, parent) == Find(total_nodes - 1, parent)) {
                return elevation;
            }
        }

        return 0;
    }
};