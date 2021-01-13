class Solution {
public:
    
    bool isValid(string str){
        int N = str.size();
        if(str.find(".", 0) == string::npos){
            if(N == 1)
                return true;
            if(str[0] == '0')
                return false;
            return true;
        }
        else{
            int i = str.find(".", 0);
            if(!isValid(str.substr(0, i)))
                return false;
            bool flag = false;
            for(int j = i+1; j < str.size(); j++){
                if(str[j] != '0'){
                    flag = true;
                    break;
                }
            }
            if(!flag)
                return false;
            if(str[str.size()-1] == '0')
                return false;
            return true;
        }
    }
    
    vector<string> permute(string str){
        vector<string> vec;
        if(isValid(str))
            vec.push_back(str);
        for(int i = 1; i < str.size(); i++){
            string s = str;
            s.insert(i, ".");
            if(isValid(s))
                vec.push_back(s);
        }
        return vec;
    }
    
    vector<string> ambiguousCoordinates(string S) {
        vector<string> vec;
        int N = S.size();
        for(int i = 1; i < N-2; i++){
            vector<string> left = permute(S.substr(1, i));
            vector<string> right = permute(S.substr(i+1, N-i-2));
            if(left.size() == 0 || right.size() == 0)
                continue;
            for(string s1: left){
                for(string s2: right){
                    string s = "(" + s1 + ", " + s2 +")";
                    vec.push_back(s);
                }
            }
        }
        return vec;
    }
};
