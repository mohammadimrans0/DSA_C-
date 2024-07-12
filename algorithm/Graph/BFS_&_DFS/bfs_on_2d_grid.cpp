#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &grid, int i, int j) {
  int rows = grid.size();
  int cols = grid[0].size();
  queue<pair<int, int>> q;

  // Directions for moving in the grid
  vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  // Mark the starting cell as visited by setting it to 0 and add it to the
  // queue
  grid[i][j] = 0;
  q.push({i, j});

  while (!q.empty()) {
    auto cell = q.front();
    q.pop();
    int ci = cell.first;
    int cj = cell.second;

    // Print the current cell coordinates
    cout << ci << " " << cj << endl;

    // Explore all four possible directions
    for (const auto &dir : directions) {
      int ni = ci + dir.first;
      int nj = cj + dir.second;

      // Check for out-of-bounds or already visited cells
      if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
        // Mark the new cell as visited
        grid[ni][nj] = 0;
        q.push({ni, nj});
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  // Starting point for the BFS
  int i = 0;
  int j = 0;

  // Perform BFS starting from the specified cell
  bfs(grid, i, j);

  return 0;
}
