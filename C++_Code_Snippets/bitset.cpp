// BitSet is much more efficient than unordered_map, and should be used whenever possible.
// The size of bitset is fixed at compile time, i.e. it can’t be decided at runtime.

// Initialise a bitset with M bits
# define M 8
bitset<M> bset1;
// bset2 is initialized with bits of 20 
// Converting decimal number to binary by using bitset 
bitset<M> bset2(20); // 00010100
// bset3 is initialized with bits of specified binary string 
bitset<M> bset3(string("1100")); // 00001100

cout << bset1 << endl; // 00000000

// setting first bit (or 6th index) 
bset1[1] = 1; // 00000010

// count function returns number of set bits in bitset 
cout << bset1.count() << endl; // 1
int numberof0 = bset1.size() - bset1.count(); // 7

// test function return 1 if bit is set else returns 0 
cout << bset1.test(1) << endl; // 1
cout << bset1.test(0) << endl; // 0

// any function returns true, if atleast 1 bit is set
cout << bset1.any() << endl; // true
// none function returns true, if none of the bit is set 
cout << bset1.none() << endl; // false

// bset1.set() sets all bits
// bset1.set(pos, b) makes bset1[pos] = b 
// bset1.set(pos) makes bset1[pos] = 1

// bset1.reset() makes all bits 0 
// bset1.reset(pos) makes bset1[pos] = 0 

// bset1.flip() flips all bits i.e. 1 <-> 0 and 0 <-> 1 
// bset1.flip(pos) flips bset1[pos] bit

// All bitwise operations (&, |, ^, ~, <<, >>, ==, !=, &=, |=, ^=, <<=, and >>=) can be used with bitsets.

// References: https://www.geeksforgeeks.org/c-bitset-and-its-application/ .
