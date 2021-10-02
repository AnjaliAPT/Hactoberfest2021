class Solution {
    public int numTrees(int n) {
       int catlan[] = new int[n + 2];
 
        // Initialize first two values in table
        catlan[0] = 1;
        catlan[1] = 1;
 
        // Fill entries in catalan[]
        // using recursive formula
        for (int i = 2; i <= n; i++) {
            catlan[i] = 0;
            for (int j = 0; j < i; j++) {
                catlan[i] += catlan[j] * catlan[i - j - 1];
            }
        }
 
        // Return last entry
        return catlan[n];
    }
}
