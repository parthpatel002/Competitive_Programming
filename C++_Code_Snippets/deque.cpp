// In C++, deque manages its elements with a dynamic array, provides random access, and has almost the same interface as a vector.
// In C++, list manages its elements as a doubly linked list and does not provide random access.
// In C++, deque provides fast insertions and deletions at both ends but inserting and deleting elements in the middle is relatively slow.
// In C++, list provides fast insertions and deletions at each position, including both ends.
// Src: https://stackoverflow.com/a/1436418 .

#include <deque> 

// Initialise a deque with two elements
deque<int> gquiz {12, 14};

// Insert at front
gquiz.push_front(10);

// Insert at back
gquiz.push_back(16);

// Print first element
cout << gquiz.front() << endl; // 10

// Print last element
cout << gquiz.back() << endl; // 16

// Print second element
cout << gquiz.at(1) << endl; // 12

// Size of deque
cout << gquiz.size(); 

// Pop front element
gquiz.pop_front();

// Pop back element
gquiz.pop_back();

// Iterate over elements of deque 
for (deque<int>::iterator it = gquiz.begin(); it != gquiz.end(); it++)
		cout << ' ' << *it;
    
// Remove all the elements of the deque container i.e. make its size 0
gquiz.clear();

// Erase elements with indices [i, j)
gquiz.erase(gquiz.begin()+i, gquiz.begin()+j); 

