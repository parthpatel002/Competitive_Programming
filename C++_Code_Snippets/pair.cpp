// Initialise a pair
pair<int, char> PAIR1; 
PAIR1.first = 100; 
PAIR1.second = 'G'; 

// Initialise a pair
pair<string,double> PAIR2 ("GeeksForGeeks", 1.23); 

// Initialise a pair
pair<string, double> PAIR3;
PAIR3 = make_pair("GeeksForGeeks is Best", 4.56);

// Access first and second elements of a pair
cout << PAIR1.first;
cout << PAIR1.second;

// Comparison (==) operator with pair : For given two pairs pair1 and pair2, the == operator compares the first value and second value of those two pairs 
// i.e. if pair1.first is equal to pair2.first or not AND if pair1.second is equal to pair2.second or not.
// Similar behaviour with Not Equal (!=) operator.

// Logical (>=, <=, <, >) operators with pair: 
// For given two pairs pair1 and pair2, the logical operators returns 0 or 1 by only comparing the first value of the pair.

// Swap the contents of one pair object with the contents of another pair object. The pairs must be of same type.
pair1.swap(pair2);
