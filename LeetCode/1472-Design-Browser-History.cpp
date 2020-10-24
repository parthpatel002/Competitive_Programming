// Solution 1: Using Deque
// #include <deque> 
// class BrowserHistory {
// private:
//     deque<string> history;
//     int curr;
// public:
//     BrowserHistory(string homepg) : history(deque<string>(1, homepg)) , curr(0) { }
    
//     void visit(string url) {
//         if(curr != 0){
//             auto itr = history.begin();
//             history.erase(itr, itr+curr);
//         }
//         history.push_front(url);
//         curr = 0;
//     }
    
//     string back(int steps) {
//         if(curr+steps >= history.size())
//             curr = history.size()-1;
//         else
//             curr += steps;
//         return history.at(curr);
//     }
    
//     string forward(int steps) {
//         if(steps > curr)
//             curr = 0;
//         else
//             curr -= steps;
//         return history.at(curr);
//     }
// };

// Solution 2: Using Vector
// class BrowserHistory {
// private:
//     vector<string> history;
//     int curr;
//     int sz;
// public:
//     BrowserHistory(string homepg) : history(vector<string>(1, homepg)) , curr(0) , sz(0) { }
    
//     void visit(string url) {
//         sz = curr+1;
//         if(curr == history.size()-1)
//             history.push_back(url);
//         else
//             history[curr+1] = url;
//         curr += 1;
//     }
    
//     string back(int steps) {
//         if(steps > curr)
//             curr = 0;
//         else
//             curr -= steps;
//         return history[curr];
//     }
    
//     string forward(int steps) {
//         if(steps > sz-curr)
//             curr = sz;
//         else
//             curr += steps;
//         return history[curr];
//     }
// };

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
