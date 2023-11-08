class Solution {
public:
    bool isEqual(vector<int> &nums, int mid, int th){
        int n = nums.size();
        double sum = 0;
        for(auto it:nums){
            sum += ceil(double(it)/double(mid));
        }
        cout<<sum<<" ";
        if(sum<=th) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = 1;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
        }
        int mn = 1;
        int mid;
        while(mn<=mx){
            mid = mn + (mx-mn)/2;
            if(isEqual(nums, mid, threshold)){
                mx = mid-1;
            }
            else {
                mn = mid+1;
            }
        }
        return (mn);
    }
};