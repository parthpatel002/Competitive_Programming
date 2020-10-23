class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        if(T.size() == 1)
            return vector<int>(1, 0);
        vector<int> vec(T.size(), 0);
        stack<int> st;
        st.push(T.size()-1);
        for(int i = T.size()-2; i >= 0; i--){
            while(!st.empty()){
                if(T[i] < T[st.top()]){
                    vec[i] = st.top()-i;
                    st.push(i);
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(st.empty()){
                st.push(i);
            }
        }
        return vec;
        
    }
};
