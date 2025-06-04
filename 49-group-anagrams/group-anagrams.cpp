class Solution {
public:

    string customhash2(string s){
        int freq[26]={0};

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }

        string hash;
        for(int i=0;i<26;i++){
            hash+= ","+to_string(freq[i]);
        }

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<int>> tracker;

        for(int i=0;i<strs.size();i++){
            string hashval=customhash2(strs[i]);

            if(tracker.find(hashval)!=tracker.end()){
                tracker[hashval].push_back(i);
            }else{
                tracker[hashval]={i};
            }
        }

        for(auto it=tracker.begin();it!=tracker.end();++it){
            vector<string> cur={};
            vector<int>indexes=it->second;

            for(int i=0;i<indexes.size();i++){
                cur.push_back(strs[indexes[i]]);
            }
            result.push_back(cur);
        }

        return result;
    }

};