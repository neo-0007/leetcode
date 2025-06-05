class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> result;

        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i])==freq.end()){
                freq[nums[i]]=1;
            }else{
                freq[nums[i]]+=1;
            }
        }

        vector<pair<int,int>> heapfreq(freq.begin(),freq.end());

        auto comp = [](const auto &a, const auto &b){
            return a.second < b.second;
        };

        make_heap(heapfreq.begin(),heapfreq.end(),comp);

        for(int i=0;i<k && !heapfreq.empty();++i){
            pop_heap(heapfreq.begin(), heapfreq.end(), comp);
            auto top = heapfreq.back();

            result.push_back(top.first);

            heapfreq.pop_back();
        }

        return result;
    }
};