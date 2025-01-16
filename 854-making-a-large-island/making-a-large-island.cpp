class Solution {
public:
    vector<int> dx = {0, 0, -1, 1}; // Directions for moving right, left, up, down
    vector<int> dy = {1, -1, 0, 0}; // Directions for moving right, left, up, down

    int bfs(int r, int c, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& islandId, int id) {
        queue<pair<int, int>> q;
        int sz = 0;
        q.push({r, c});
        islandId[r][c] = id; // Mark the island with its unique id
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            int i = x.first;
            int j = x.second;
            sz++;
            // Check all 4 directions
            for (int dir = 0; dir < 4; dir++) {
                int nr = i + dx[dir], nc = j + dy[dir];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1 && islandId[nr][nc] == 0) {
                    islandId[nr][nc] = id; // Assign the same island id
                    q.push({nr, nc});
                }
            }
        }
        return sz; // Return the size of the island
    }

    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> islandId(m, vector<int>(n, 0)); // To store island IDs
        unordered_map<int, int> islandSizes; // To store island size by their ID
        
        int islandIdCounter = 1;
        int maxIslandSize = 0;

        // Step 1: Identify all islands and calculate their sizes
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && islandId[i][j] == 0) {
                    int size = bfs(i, j, m, n, grid, islandId, islandIdCounter);
                    islandSizes[islandIdCounter] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    islandIdCounter++;
                }
            }
        }

        // Step 2: Try flipping each water cell (0) to land and calculate the new island size
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {  // Try flipping this water cell to land
                    unordered_set<int> adjacentIslands;  // To track adjacent island IDs
                    int newIslandSize = 1;  // Include the flipped cell itself
                    for (int dir = 0; dir < 4; dir++) {
                        int nr = i + dx[dir], nc = j + dy[dir];
                        if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                            int island = islandId[nr][nc];
                            if (adjacentIslands.find(island) == adjacentIslands.end()) {
                                newIslandSize += islandSizes[island];
                                adjacentIslands.insert(island);
                            }
                        }
                    }
                    maxIslandSize = max(maxIslandSize, newIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};
