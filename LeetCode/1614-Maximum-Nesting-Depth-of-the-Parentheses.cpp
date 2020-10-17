class Solution {
public:
    
    int maxDepth(string s) {
    
        if (s.size() == 0)
            return 0;
        int stack = 0;
        int maxdepth = 0;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                stack += 1;
                maxdepth = max(stack, maxdepth);
            }
            else if (s[i] == ')'){
                stack -= 1;
            }
        }
        return maxdepth;
    
    }
};
