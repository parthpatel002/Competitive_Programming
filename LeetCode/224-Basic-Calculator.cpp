class Solution {
public:
    
    int evaluate(string str){
        if(str[0] == '-' || str[0] == '+')
            str = "0" + str;
        int N = str.size();
        list<int> ls;
        vector<bool> vec;
        for(int i = 0; i < N; ){
            if(str[i] >= '0' && str[i] <= '9'){
                int j = i+1;
                while(j < N && str[j] >= '0' && str[j] <= '9')
                    j++;
                ls.push_back(stoi(str.substr(i, j - i)));
                i = j;
            }
            else{
                bool val = (str[i] == '+') ? true : false;
                int j = i+1;
                while(j < N && (str[j] == '+' || str[j] == '-')){
                    if(str[j] == '-')
                        val = !val;
                    j++;
                }
                vec.push_back(val);
                i = j;
            }
        }
        for(int i = 0; i < vec.size(); i++){
            int val1 = ls.front();
            ls.pop_front();
            int val2 = ls.front();
            ls.pop_front();
            int res = (vec[i]) ? (val1 + val2) : (val1 - val2);
            ls.push_front(res);
        }
        return ls.front();
    }
    
    int calculate(string s) {
        int N = s.size();
        if(N == 1)
            return stoi(s);
        stack<string> st;
        for(int i = 0; i < N; i++){
            if(s[i] == ' ')
                continue;
            else if(s[i] == ')'){
                string str;
                while(st.top() != "("){
                    str = st.top() + str;
                    st.pop();
                }
                st.pop();
                int val = evaluate(str);
                st.push(to_string(val));
            }
            else{
                string str (1, s[i]);
                st.push(str);
            }
        }
        string str;
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return evaluate(str);
    }

};
