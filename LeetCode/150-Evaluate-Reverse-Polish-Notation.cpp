class Solution {
public:
    
    bool isOperation(string str){
        if(str.size() > 1)
            return false;
        char ch = str[0];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return true;
        return false;
    }
    int eval(int a, int b, string op){
        if(op == "+")
            return a + b;
        else if(op == "-")
            return a - b;
        else if(op == "*")
            return a * b;
        else 
            return a / b;
    }
    
    int evalRPN(vector<string>& tokens) {
        int N = tokens.size();
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(!isOperation(tokens[i])){
                st.push(stoi(tokens[i]));
            }
            else{
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(eval(a, b, tokens[i]));
            }
        }
        return st.top();
    }
    
};
