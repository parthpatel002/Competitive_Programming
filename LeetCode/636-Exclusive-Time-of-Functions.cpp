class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> res (n, 0);
        int N = logs.size();
        stack<pair<int, int>> st;
        int time;
        for(int i = 0; i < N; ){
            string s = logs[i];
            int idx1 = s.find(':', 0);
            int idx2 = s.find(':', idx1+1);
            string s1 = s.substr(0, idx1);
            string s2 = s.substr(idx1+1, idx2-idx1-1);
            string s3 = s.substr(idx2+1);
            int fid = stoi(s1);
            int stamp = stoi(s3);
            if(i == 0)
                time = stamp;
            if(s2 == "start"){
                if(!st.empty()){
                    st.top().second += (stamp-time-1);
                }
                string s_ = logs[i+1];
                int idx1_ = s_.find(':', 0);
                int idx2_ = s_.find(':', idx1_+1);
                string s1_ = s_.substr(0, idx1_);
                string s2_ = s_.substr(idx1_+1, idx2_-idx1_-1);
                string s3_ = s_.substr(idx2_+1);
                int fid_ = stoi(s1_);
                int stamp_ = stoi(s3_);
                if(s2_ == "start"){
                    st.push(make_pair(fid, stamp_-stamp));
                    i++;
                    time = stamp_-1;
                }
                else{
                    res[fid] += (stamp_ - stamp + 1);
                    i += 2;
                    time = stamp_;
                }
            }
            else{
                st.top().second += (stamp-time);
                res[st.top().first] += st.top().second;
                st.pop();
                i++;
                time = stamp;
            }
        }
        return res;
        
    }
};
