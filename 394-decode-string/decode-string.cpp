class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        int curNum = 0;
        string curStr = "";

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                curNum = curNum*10 + (s[i]-'0');
            }else if(s[i]=='['){
                nums.push(curNum);
                strs.push(curStr);
                curStr="";
                curNum=0;
            }else if(s[i]==']'){
                int topNum = nums.top(); nums.pop();
                string topStr = strs.top(); strs.pop();
                string rep;
                for(int j=0;j<topNum;j++){
                    rep += curStr;
                }

                curStr = topStr + rep;
            }else{
                curStr = curStr + s[i];
            }
        }

        return curStr;
    }
};