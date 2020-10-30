class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        if(answers.size()==0)
            return 0;
        unordered_map<int, int> umap;
        for(int i = 0; i < answers.size(); i++)
            umap[answers[i]] += 1;
        int cnt = 0;
        for(auto itr = umap.begin(); itr != umap.end(); itr++){
            int key = itr->first;
            int val = itr->second;
            if(val >= key+1)
                cnt += (val - val%(key+1));
            if(val%(key+1) != 0)
                cnt += (key+1);
        }
        return cnt;
        
    }
};
