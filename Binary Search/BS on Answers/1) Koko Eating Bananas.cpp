// In this question we are given a koko who loves to eat bananas.
// there are n piles and in every ith pile there are piles[i] bananas and the condition is that the koko can eat any number of bananas in one hour. 
// If the pile has k bananas and the koko can eat k in one hour then he will eat all and if there are less than k bananas in one pile then koko can eat all bananas and in that hour he will not any more 

// Example: piles = [3,4,5,6] k = 4 then it will take 6 hours for the koko to eat all bananas.

// Problem: our task is to find the min speed of koko to eat all bananas in h hours. 
// Speed => bananas/hour;


// Intuition: 
// First We need to find out the minimum and maximum speed of koko. 
// Minimum can be -> sum/h and max can be -> max among all piles.

// Then we can apply linear search to all the values to find out the minimum speed to eat all bananas in h hours. 

// But as we know the range of answer here we can apply binary search also to reduce complexity.




class Solution {
public:

    int hoursRequired(const vector<int> &piles, int mid){
        int h = 0;
        if(mid == 0) return INT_MAX;
        for(auto it:piles){
            if(it%mid != 0){
                h++;
            }
            h += (it/mid);
        }
        return (h);
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long sum = 0;
        int mx = 0;
        for(int i=0;i<n;i++){
            sum += piles[i];
            mx = max(mx,piles[i]);
        }
        int mid = 0;
        int l = sum/h, r = mx, ans = 0;
        while(l<r){
            mid = l + (r-l)/2;
            ans = hoursRequired(piles, mid);
            
            if(ans>h){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
};