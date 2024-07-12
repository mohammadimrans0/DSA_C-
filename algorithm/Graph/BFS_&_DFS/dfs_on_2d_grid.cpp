#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j) {
  int rows = grid.size();
  int cols = grid[0].size();

  // Check for out-of-bounds or already visited cells
  if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
    return;
  }

  // Mark the current cell as visited
  grid[i][j] = 0;

  // Print the current cell coordinates
  cout << i << " " << j << endl;

  // Explore all four possible directions
  dfs(grid, i + 1, j); // Down
  dfs(grid, i - 1, j); // Up
  dfs(grid, i, j + 1); // Right
  dfs(grid, i, j - 1); // Left
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

  // Starting point for the DFS
  int i = 0;
  int j = 0;

  // Perform DFS starting from the specified cell
  dfs(grid, i, j);

  return 0;
}