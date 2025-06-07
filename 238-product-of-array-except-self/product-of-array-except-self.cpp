class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> res(n);
        prefix[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i]; 
        }
        int temp=1;
        suffix[n-1]=1;

        for(int i=n-1;i>0;i--){
             temp=temp*nums[i];
             suffix[i-1]=temp;
        }

        res[0]=suffix[0];

        for(int i=1;i<n;i++){
            res[i]=prefix[i-1]*suffix[i];
        }

        return res;
    }
};