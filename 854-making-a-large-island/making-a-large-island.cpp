class UnionFind {
private:
    vector<int> parent, rank, size;

public:
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[py] = px;
            size[px] += size[py];
            rank[px]++;
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        UnionFind uf(n * n);

        auto getIndex = [n](int i, int j) { return i * n + j; };

        // Step 1: Group connected 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (auto [di, dj] : dirs) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            uf.unite(getIndex(i, j), getIndex(ni, nj));
                        }
                    }
                }
            }
        }

        // Step 2: Find the largest island size
        int maxSize = 0;
        for (int i = 0; i < n * n; i++) {
            maxSize = max(maxSize, uf.getSize(i));
        }

        // Step 3: Check each 0 cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIslands;
                    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (auto [di, dj] : dirs) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            neighborIslands.insert(uf.find(getIndex(ni, nj)));
                        }
                    }

                    int size = 1;  // Start with size 1 for the current cell
                    for (int island : neighborIslands) {
                        size += uf.getSize(island);
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }

        return maxSize;
    }
};
