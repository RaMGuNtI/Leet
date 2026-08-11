class Solution:
    def dfs(self, grid, vis, row, col):
        vis[row][col] = True
        direction = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dr, dc in direction:
            nr, nc = dr+row, dc+col
            if 0<=nr<len(grid) and 0<=nc<len(grid[0]):
                if grid[nr][nc]=="1" and not vis[nr][nc]:
                    self.dfs(grid, vis, nr, nc)


    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        visited = [[False] * m for _ in range(n)]
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]=="1" and not visited[i][j]:
                    self.dfs(grid, visited, i, j)
                    count+=1
        return count