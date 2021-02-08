// Initialise empty unordered set
unordered_set<int> uset();

// Insert a val
uset.insert(val);

// Find value
if (uset.find(val) == uset.end()) 
    cout << val << " not found" << endl; 
else
    cout << "Found " << val << endl;

// Remove value
uset.erase(val);

// Iterate over elements
unordered_set<int>::iterator itr; 
for (itr = uset.begin(); itr != uset.end(); itr++) 
    cout << (*itr) << endl; 

// Compute union of uset1 and uset2
unordered_set<int> union_set(uset1);
union_set.insert(uset2.begin(), uset2.end());
