// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

// Example 1:

// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.


class Solution {
public:
    bool check(vector<int>& weights, int mid, int days){
        int temp = 0;
        int requiredays = 1;
        for(auto& it: weights){
            if(temp + it > mid) {
                temp = 0;
                requiredays++;
            }
            temp += it;
        }
        if(requiredays > days){
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mn = 0;
        int mx = 0;
        int n = weights.size();
        for(int i=0;i<n;i++){
            mn = max(mn, weights[i]);
            mx += weights[i];
        }
        int ans = 0, mid = 0;
        while(mn<=mx){
            mid = mn + (mx-mn)/2;
            if(check(weights, mid, days)) {
                mx = mid-1;
                ans = mid;
            }
            else{
                mn = mid+1;
            }
        }
        return (ans);
    }

};