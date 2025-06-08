class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s_lower = s.lower()
        s_f = ""
        for i in s_lower:
            if i.isalnum():
                s_f = s_f + i

        n = len(s_f)

        for i in range(0,n//2):
            if(s_f[i]!= s_f[n-i-1]):
                return False
        
        return True
        