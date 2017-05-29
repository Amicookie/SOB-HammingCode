#ifndef HAMMING_H
#define HAMMING_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class Hamming
{
    string bitCode;
public:
    Hamming(string bitCode);
    ~Hamming();
    template<class T> string valueToString(T value);
    template<class T> T stringToValue(string str);
    string mistake(string data);
    string Dec2Bin(int n);
    int Bin2Dec(string m);
    string generateRandom(int length);
    void hammingAlgorithm(string input);
    bool IsEmpty(string input);
};

#endif // HAMMING_H
