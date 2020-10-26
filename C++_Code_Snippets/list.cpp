// In C++ STL, list implements doubly linked list.

#include <list> 
#include <iterator> 

// Initialise empty list
list<int> ls;

// Initialise a list of size N with each element as val
list<int> ls (N, val);

// Initialise a list of size N with each element as val
ls.assign(N, val);

// Copy elements from an existing list to a new list.
ls.assign(ls2.begin(), ls2.end());

// Get size of list
cout << ls.size() << endl;

// Return whether list is empty or not
cout << ls.empty() << endl;

// Push element at front of list
ls.push_front(val);

// Push element at back of list
ls.push_back(val);

// Get front element
cout << ls.front() << endl;

// Get back element
cout << ls.back() << endl;

// Remove element from front of list
ls.pop_front();

// Remove element from back of list
ls.pop_back();

// Remove all elements from the list
ls.clear();

// Iterate over elements of the list
list<int>::iterator it; 
for(it = ls.begin(); it != ls.end(); it++) 
    cout << " " << *it; 

// Insert element into list
list<int>::iterator it = ls.begin(); 
advance(it, 2); // iterator to point to 3rd position 
ls.insert(it, 5); // using insert to insert 1 element (i.e. 5) at the 3rd position 
    
// Insert elements into list
list<int>::iterator it = ls.begin(); 
advance(it, 2); // iterator to point to 3rd position 
ls.insert(it, 2, 7); // insert 2 occurrences of 7 at the 3th position 

// Delete element from list
list<int>::iterator it = ls.begin(); 
advance(it, 2); // iterator to point to 3rd position 
ls.erase(it); // remove element at 3rd position 

// Delete elements from list
list<int>::iterator itr1, itr2; 
itr1 = demoList.begin(); 
itr2 = demoList.begin(); 
advance(itr2, 3); // Incrementing itr2 by 3 positions 
demoList.erase(itr1, itr2); // deleting range of elements from index [0, 3) 

// Remove element with certain value from list
ls.remove(20); // delete all elements with value 20 

// Reverse the list in-place
ls.reverse();

// Sort the list in-place
ls.sort();

