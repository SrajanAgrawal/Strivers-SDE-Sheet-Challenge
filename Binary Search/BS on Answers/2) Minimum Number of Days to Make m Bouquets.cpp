// So listen, if you practicing questions on binary search then make sure, ek baar to try kr liya ho.
// because the question is very very simple all it needs is your understanding.

// Here there is a garden and n flowers are to bloomed.
// and you are given an array that tells you ki which flower will be bloomed on which day.

// For example:
// if there are 5 flowers such that :
// [1,10,3,10,2]
// it basically means that for the first flower it needs 1 day and for the 2nd flower it needs 10 days to bloom.

// so if you consider any random day, let's suppose 3 so on 3rd day. the status of all the flowers will be like ->

// x -> bloomed
// _ -> yet to be bloomed

// so on the 3rd day. the status will be
// [x,,x,,x] so we can make 3 banquets with 1 flower each.

// I hope you get it till this point.

// Approach
// Now as we understand the problem so you can see that in the answer range.
// the minimum day is arr[min];
// and the maximum day is arr[max];
// so the very first approach is to use the linear search.
// and as you have the answer range then you can apply binary search also.

// Complexity
// Time complexity:

// O(log(arr[max]−arr[min]+1)∗N)

// Space complexity:

// O(1)




class Solution {
public:
    bool isPos(vector<int>& bloomDay, int mid, int m, int k){
        int n = bloomDay.size();
        int adj = 0;
        int temp = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid) {
                adj++;
            }
            else{
                temp += adj/k;
                adj = 0;
            }
        }
        temp += adj/k;
        if(temp >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if(n < val) {
            return (-1);
        }
        int mn = INT_MAX, mx = 0;
        for(int i=0;i<n;i++){
            mn = min(mn,bloomDay[i]);
            mx = max(mx,bloomDay[i]);
        }
        int mid = 0;
        while(mn<=mx){
            mid = mn + (mx-mn)/2;
            if(isPos(bloomDay,mid,m,k)) {
                mx = mid-1;
            }
            else{
                mn = mid+1;
            }
        }
        return (mn);
    }
};