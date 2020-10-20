class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1)
            return true;
        int st = 0;
        int end = s.size()-1;
        while(1){
            while(!((s[st]>='a' && s[st]<='z') || (s[st]>='A' && s[st]<='Z') || (s[st]>='0' && s[st]<='9'))){
                st++;
                if (st == s.size())
                    break;
            }
            if (st == s.size())
                break;
            while(!((s[end]>='a' && s[end]<='z') || (s[end]>='A' && s[end]<='Z') || (s[end]>='0' && s[end]<='9'))){
                end--;
                if (end == -1)
                    break;
            }
            if (end == -1)
                break;
            if (st >= end)
                break;
            if ((s[st]>='0' && s[st]<='9') && !(s[end]>='0' && s[end]<='9'))
                return false;
            if (!(s[st]>='0' && s[st]<='9') && (s[end]>='0' && s[end]<='9'))
                return false;
            if ((s[st]>='0' && s[st]<='9') && (s[end]>='0' && s[end]<='9')){
                if (s[st] != s[end])
                    return false;
                st++;
                end--;
                continue;
            }
            if (!((s[st]==s[end]) || (s[st]-s[end]=='a'-'A') || (s[st]-s[end]=='A'-'a')))
                return false;
            st++;
            end--;
        }
        return true;
    }
};
