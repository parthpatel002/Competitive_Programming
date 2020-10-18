class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        // Solution 1 - Unordered Map (slower)
        // vector<string> vec;
        // if (s.size() <= 10)
        //     return vec;
        // int M = 10;
        // unordered_map<string, int> umap;
        // for(int i = 0; i <= s.size() - M; i++){
        //     string subs = s.substr(i, M);
        //     if (umap.find(subs) == umap.end())
        //         umap[subs] = 1;
        //     else if (umap[subs] == 1){
        //         vec.push_back(subs);
        //         umap[subs] = 2;   
        //     }
        // }
        // return vec;
        
        // Solution 2 - BitSet (faster)
        // vector<string> res;
        // int M = 10;
        // int L = 1 << 20; 
        // // Since we have 4 possible characters A, C, T and G, we need two bits to represent each 
        // // character uniquely, hence, we need a bitset of 2 * 10 = 20 bits, since we are focussing on
        // // 10-letter-long sequences.
        // bitset< 1 << 20 > m1, m2; // L = (1 << 20) represents no. of bits in the bitset i.e. no. of unique 10-letter-long substrings.
        // unordered_map<char, int> umap;
        // umap['A'] = 0; umap['C'] = 1; umap['T'] = 2; umap['G'] = 3;
        // int t = 0; // tracks current 10-letter substring
        // int K = L - 1; // Last 20 bits of K are 1s.
        // for (int i = 0; i < s.size(); i++){
        // 	t = ((t << 2) & K) | (umap[s[i]] & 3); 
        // 	if (i < 9) continue;
        // 	if (!m2[t] && m1[t]){
        // 		res.push_back(s.substr(i - 9, 10));
        // 		m2.set(t);
        // 	}
        // 	else m1.set(t);
        // }
        // return res;
    }
};
