vector<int> vec;

// Initialising by specifying size and initializing all values with 10
vector<int> vec(size, 10);

// Initializing like arrays
vector<int> vec{10, 20, 30};

// Initializing from an array 
int arr[] = {10, 20, 30}; 
int n = sizeof(arr) / sizeof(arr[0]); 
vector<int> vec(arr, arr + n); 

// Initializing from another vector
vector<int> vec2(vec1);

// 2D Empty Array
return vector<vector<int>>{};

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
vec.insert(vec.begin() + i, 7); // With return value (as iterator to start of modified vector): itrator = vec.insert(vec.begin() + i, 7);

// inserts 4 two times at i-th index
itrator = vec.insert(vec.begin() + i, 2, 4);

// Time complexity of insert in vector is O(N + M) where N is the number of elements inserted and M is the number of the elements moved.

// Vector initialisation in a class
class ParkingSystem {
  private:
    vector<int> capacity;
    vector<int> occupied;
    vector<int> nums;
    vector<int> arr;
  public:
    ParkingSystem(int big, int medium, int small) : capacity(vector{big, medium, small}) , occupied(vector(3, 0)), nums(vector<int>()), arr({}) {}
};

