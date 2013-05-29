#include <string>
#include <vector>

using std::vector;
using std::string;

int main()
{
    // OK!
    vector<vector<int>> ivec;

    // error: conversion from ‘std::vector<std::vector<int> >’ to non-scalar
    // type ‘std::vector<std::basic_string<char> >’ requested
    //vector<string> svec1 = ivec;

    // OK!
    vector<string> svec2(10, "null");
}
