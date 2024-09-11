from typing import List
def maximalSquare(matrix: List[List[str]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        psum =[[0] * (n+1)] * (m+1)
  
        for i in range(1, m+1):
            for j in range(1, n+1):
                print(i, j)
                for x in psum:
                    print(x)
                psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + int(matrix[i-1][j-1])
                print("")
        print(psum)
        return psum[m][n]
            
matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
print(maximalSquare(matrix))