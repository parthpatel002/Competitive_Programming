// Find index of str1 in str from index 0:
if (str.find(str1, 0) != string::npos) 
        cout << "First occurrence is " << str.find(str1, 0) << endl; 

// Substring Function
string s = "Parth"; 
// Copy three characters of s1 (starting from position 1) 
string s1 = s.substr(1, 3); // "art"
string s2 = s.substr(1); // "arth"

// String to Integer
string s = "123";
int fid = stoi(s);
cout << fid << endl; // 123
