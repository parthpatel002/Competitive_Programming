vector<int> vec;

// Append element at end of vector
vec.push_back(element);

// Remove last element
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

