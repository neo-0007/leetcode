class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> ht;

        for(int i=0;i<nums.size();i++){
            auto sr = ht.find(nums[i]);

            if(sr==ht.end()){
                ht.insert(make_pair(nums[i],1));
            }else{
                return true;
            }
        }
        return false;
    }
};