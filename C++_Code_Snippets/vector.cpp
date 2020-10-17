vector<int> vec;

// Append element at end of vector
// Time complexity is O(1)
vec.push_back(element);

// Remove last element
// Time complexity is O(1)
vec.pop_back();

// Size of vector
int len = vec.size();

// Get first element
cout << vec.front();

// Get last element
cout << vec.back();

// inserts 7 at i-th index 
int i = 2;
vec.insert(vec.begin() + i, 7); // With return value (as iterator to start of modified vector): iterator = vec.insert(vec.begin() + i, 7);

// inserts 4 two times at i-th index
iterator = vec.insert(vec.begin() + i, 2, 4);

// Time complexity of insert in vector is O(N + M) where N is the number of elements inserted and M is the number of the elements moved.

