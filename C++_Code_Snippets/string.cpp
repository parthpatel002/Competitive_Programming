// Find index of str1 in str from index 0:
if (str.find(str1, 0) != string::npos) 
        cout << "First occurrence is " << str.find(str1, 0) << endl; 

// Substring Function
string s = "Parth"; 
// Copy three characters of s1 (starting from position 1) 
string s1 = s.substr(1, 3); // "art"
string s2 = s.substr(1); // "arth"

// Compare strings
void relationalOperation(string s1, string s2){
    if (s1 != s2) {
        cout << s1 << " is not equal to " << s2 << endl;
        if (s1 > s2)
            cout << s1 << " is greater than " << s2 << endl;
        else
            cout << s2 << " is greater than " << s1 << endl;
    }
    else
        cout << s1 << " is equal to " << s2 << endl;
}

// String to Integer
string s = "123";
int fid = stoi(s);
cout << fid << endl; // 123

// Integer to String
string s = std::to_string(425);
cout << s << endl; // 425
