c class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges == null)
            throw new IllegalArgumentException("edges is null");
        int[] union = new int[n];
        Arrays.fill(union, -1);
        for (int[] edge : edges) {
            int x = findUnion(union, edge[0]);
            int y = findUnion(union, edge[1]);
            if (x == y) 
                return false;
            union[y] = x;
        }
        return edges.length == n - 1;
    }
    
    
    private int findUnion(int[] union, int i) {
        if (union[i] == -1)
            return i;
        return findUnion(union, union[i]);
    }
}
