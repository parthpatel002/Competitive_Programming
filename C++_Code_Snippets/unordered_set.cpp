// Initialise empty unordered set
unordered_set<int> uset();

// Insert a val
uset.insert(val);

// Compute union of uset1 and uset2
unordered_set<int> union_set(uset1);
union_set.insert(uset2.begin(), uset2.end());

