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

// 

// Reverse the list in-place
ls.reverse();

// Sort the list in-place
ls.sort();

