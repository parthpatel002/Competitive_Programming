// Sorting a vector:
#include <bits/stdc++.h> 
sort(vec.begin(), vec.end());

// Sorting a vector of vectors [according to first element and resolving ties with subsequent elements].
// Useful for vector of size-2 vectors (https://github.com/parthpatel002/Competitive_Programming/blob/main/LeetCode/56-Merge-Intervals.cpp) .
vector<vector<int>> vec;
sort(vec.begin(), vec.end());

// Sorting a vector [named 'points' below] of some object (below, a vector of 2 elements):
#include <bits/stdc++.h> 
struct compare{
    bool operator()(vector<int>& a, vector<int>&b){
        if(a[0] == b[0])
            return a[1] < b[1];
        else
            return a[0] < b[0];
    }
};
sort(points.begin(), points.end(), compare());

