// Problem Statement: You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
// You are also given an integer ‘k’ which denotes the number of aggressive cows.
// You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.



// Good Question: 
bool canWePlace(vector<int>& stalls, int mid, int k, int n ){
    int countCow = k-1;
    int last = stalls[0];
    for (int i = 1;i<n;i++){
        if(stalls[i]-last >= mid) {
            last = stalls[i];
            countCow--;
        }
    }
    if(countCow <= 0) return true; // IMP Condition For this question. 
    
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int start = 1;
    int end =  stalls[n-1] - stalls[0];
    int mid = 0;
    int ans;
    while(start<=end){
        mid = start + (end - start)/2;
        if(canWePlace(stalls, mid, k, n)) {
            start = mid+1;
            ans = mid;
        }
        else {
            end = mid-1;
        }
    }
    return (ans);
}