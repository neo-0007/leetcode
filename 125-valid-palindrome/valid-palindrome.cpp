class Solution {
public:
    bool isPalindrome(string s) {
        string s_form = "";

        for(char &c : s){
            if(isalnum(c)){
                c = tolower(c);
                s_form+=c;
            }
        }


        int left = 0, right = s_form.length() - 1;

        while(left<right){
            if(s_form[right]!=s_form[left]) return false;
            left++;
            right--;
        }

        return true;

    }
};