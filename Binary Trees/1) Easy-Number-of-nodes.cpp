// Given an integer N, determine the maximum number of nodes present at level N.

// Input - N=4
// Output = 8

// Explanation : 2^(N-1);

// First Approach

    int numberOfNodes(int N){
        // Write your code here.
        int n=N-1;
        return pow(2,n);
    }

// Second Approach

/*  
    Time Complexity : O(1)
    Space Complexity : O(1)
*/
    int numberOfNodes(int N){
        // Calculate the maximum number of nodes on the last level.
        int nodes= 1<<(N-1);

        // Return the maximum number of nodes on the last level.
        return nodes;
    }
