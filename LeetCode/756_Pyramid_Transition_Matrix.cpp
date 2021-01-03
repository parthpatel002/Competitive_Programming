class Solution {
public:
    
    bool recurse(string bottom, vector<string>& allowed){
        if(bottom.size() <= 1)
            return true;
        vector<string> pre;
        vector<string> post;
        for(int i = 0; i < bottom.size() - 1; i++){
            post = vector<string>();
            bool flag = false;
            for(int j = 0; j < allowed.size(); j++){
                if(allowed[j][0] == bottom.at(i) && allowed[j][1] == bottom.at(i+1)){
                    if(i == 0){
                        string top = "";
                        top += allowed[j][2];
                        post.push_back(top);
                    }
                    else{
                        for(int k = 0; k < pre.size(); k++){
                            string top = pre[k];
                            top += allowed[j][2];
                            post.push_back(top);
                        }
                    }
                    flag = true;
                }
            }
            if(!flag)
                return false;
            pre = post;
        }
        for(int i = 0; i < post.size(); i++){
            bool retVal = recurse(post[i], allowed);
            if(retVal)
                return true;
        }
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        return recurse(bottom, allowed);
    }
    
};

