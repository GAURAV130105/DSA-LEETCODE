class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            sort(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[idx]<nums[i]){
                swap(nums[idx],nums[i]);
                break;
            }
        }

        sort(nums.begin()+idx+1,nums.end());
    }
};