class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        // Solution 1: Deciding whether each asteroid will blow up or not and storing info. in 'destroyed' vector. 
        // int N = asteroids.size();
        // if (N == 1)
        //     return asteroids;
        // vector<bool> destroyed(N, false);
        // for(int i = 0; i < N; i++){
        //     if (asteroids[i] > 0){
        //         vector<int> maxi = vector<int>(1, asteroids[i]);
        //         for(int j = i+1; j < N; j++){
        //             if (asteroids[j] > 0){
        //                 if(asteroids[j] >= maxi[maxi.size()-1]){
        //                     maxi.push_back(asteroids[j]);
        //                 }
        //             }
        //             else{
        //                 if (abs(asteroids[j]) > maxi[maxi.size()-1]){
        //                     destroyed[i] = true;
        //                     break;
        //                 }
        //                 else if(abs(asteroids[j]) == maxi[maxi.size()-1]){
        //                     maxi.pop_back();
        //                     if (maxi.size() == 0){
        //                         destroyed[i] = true;
        //                         break;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     else{
        //         vector<int> maxi = vector<int>(1, abs(asteroids[i]));
        //         for(int j = i-1; j >= 0; j--){
        //             if(asteroids[j] < 0){
        //                 if(abs(asteroids[j]) >= maxi[maxi.size()-1]){
        //                     maxi.push_back(abs(asteroids[j]));
        //                 }
        //             }
        //             else{
        //                 if(asteroids[j] > maxi[maxi.size()-1]){
        //                     destroyed[i] = true;
        //                     break;
        //                 }
        //                 else if(asteroids[j] == maxi[maxi.size()-1]){
        //                     maxi.pop_back();
        //                     if (maxi.size() == 0){
        //                         destroyed[i] = true;
        //                         break;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<int> result;
        // for(int i = 0; i < N; i++)
        //     if (!destroyed[i])
        //         result.push_back(asteroids[i]);
        // return result;
        
        // Solution 2: Using a stack.
        // int N = asteroids.size();
        // if (N == 1)
        //     return asteroids;
        // stack<int> st;
        // st.push(asteroids[0]);
        // for(int i = 1; i < N; i++){
        //     if(st.empty()){
        //         st.push(asteroids[i]);
        //         continue;
        //     }
        //     if(asteroids[i] > 0 || st.top() < 0){
        //         st.push(asteroids[i]);
        //         continue;
        //     }
        //     bool flag = true;
        //     while(!st.empty()){
        //         if(st.top() > 0){
        //             if(st.top() < abs(asteroids[i]))
        //                 st.pop();
        //             else if(st.top() == abs(asteroids[i])){
        //                 st.pop();
        //                 flag = false;
        //                 break;
        //             }
        //             else
        //                 break;
        //         }
        //         else{
        //             st.push(asteroids[i]);
        //             break;
        //         }
        //     }
        //     if(st.empty() && flag)
        //         st.push(asteroids[i]);
        // }
        // vector<int> result;
        // while(!st.empty()){
        //     int val = st.top();
        //     result.insert(result.begin(), val);
        //     st.pop();
        // }
        // return result;
        
    }
};
