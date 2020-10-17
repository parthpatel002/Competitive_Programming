unordered_map<string, int> umap;

// Insert a key val pair - ("hi", 1)
umap["hi"] = 1;

// Find a key
if (umap.find(key) == umap.end())
  cout << "Key not found" << endl;
else
  cout << "Val is " << umap[key] << endl;
  
// Iterate over elements
for(auto it = umap.begin(); it != umap.end(); it++)
  cout << "Key :" << it->first << "; Val :" << it->second << endl;
  
