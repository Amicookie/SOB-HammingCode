#include "hamming.h"

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

Hamming::Hamming(string bitCode)
{
    bitCode = this->bitCode;
}

template<class T>
string Hamming::valueToString(T value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

template<class T>
T Hamming::stringToValue(string str) {
    istringstream iss(str);
    T value;
    iss >> value;
    return value;
}

string Hamming::mistake(string data) {
    srand(time(NULL));
    int r = rand() % 2;
    cout << "Does the error occur: " << r;
    if (r == 1)
    {
        int l = data.length();
        int rn = rand() % 4 + 1;
        cout << endl << "How many bits: " << rn;
        for (int i = 0; i<rn; i++) {
            int rd = rand() % l;
            cout << endl << "Bit: " << rd + 1;
            if (data[rd] == '1')
                data[rd] = '0';
            else
                data[rd] = '1';
            cout << endl << data;
        }
    }
    return data;
}

string Hamming::Dec2Bin(int n) {
    long bin = 0;
    string binStr;
    int r, i = 1;

    while (n != 0) {
        r = n % 2;
        n /= 2;
        bin += r * i;
        i *= 10;
    }

    if (bin < 10) {
        binStr = "0000000";
        binStr.append(valueToString(bin));
    } else if (bin < 100) {
        binStr = "000000"; binStr.append(valueToString(bin));
    } else if (bin < 1000) {
        binStr = "00000"; binStr.append(valueToString(bin));
    } else if (bin < 10000) {
        binStr = "0000"; binStr.append(valueToString(bin));
    } else if (bin < 100000) {
        binStr = "000"; binStr.append(valueToString(bin));
    } else if (bin < 1000000) {
        binStr = "00"; binStr.append(valueToString(bin));
    } else if (bin < 10000000) {
        binStr = "0"; binStr.append(valueToString(bin));
    } else binStr = valueToString(bin);
    return binStr;
}

int Hamming::Bin2Dec(string m) {
    int n = stringToValue<int>(m);
    int dec = 0, i = 0, r;
    while (n != 0) {
        r = n % 10;
        n /= 10;
        dec += r * pow(2, i);
        ++i;
    }
    return dec;
}

string Hamming::generateRandom(int length) {
    string value = "";
    int random;
    srand(time(NULL));

    for (int i = 0; i<length; i++) {
        random = rand() % 2;
        //cout << "Random generated nr: " << random << endl;
        //value += to_string(random);
        value += valueToString(random);
    }
    return value;
}

void Hamming::hammingAlgorithm(string input) {

//    //hamming code (7,4) - we can only have an input of 1-4 bits!
//    if (input == "" || input.empty()) {
//        cout << "We cannot use Hamming Algorithm on empty string!" << endl;

//    } else {

//        int inputLength = input.length();
//        string bitWord = "";
//        vector<int> elementsWithValueOfOne;


//        int parityBitsNumber = 0;

//        if (inputLength == 1) parityBitsNumber = 2;
//        else if (inputLength > 1 && inputLength <= 4) parityBitsNumber = 3;
//        else if (inputLength > 4 && inputLength <= 11) parityBitsNumber = 4;
//        else if (inputLength > 11 && inputLength <= 26) parityBitsNumber = 5;
//        else if (inputLength > 26 && inputLength <= 57) parityBitsNumber = 6;
//        else if (inputLength > 57 && inputLength <= 120) parityBitsNumber = 7;
//        else if (inputLength > 120 && inputLength <= 247) parityBitsNumber = 8;



//        //control bits are on the positions of power of 2
//        int counter = inputLength - 1;
//        for (int i = 0; i < inputLength + parityBitsNumber; i++) {

//            if ((fmod(log2(i + 1), 1.0)) == 0) {
//                //if (i == (inputLength + parityBitsNumber - 1)) {
//                //	bitWord.append(valueToString(input[counter]));
//                //	cout << "Since our code is only " << inputLength << " characters long, we don't append another 0 on position " << i+1 << "!" << endl;
//                //	counter--;
//                //} else
//                bitWord.append("0");
//            } else {
//                bitWord.append(valueToString(input[counter]));
//                counter--;
//            }
//        }

//        //	cout << bitWord[1] << endl;

//        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
//            if (bitWord[i] == '1') {
//                elementsWithValueOfOne.push_back(i + 1);
//            }
//        }

//        cout << "Bit word (with zeros at parity): " << bitWord << endl;

//        string zmienna;
//        vector<string> parityMatrix;
//        vector<int> wynik(8);
//        //int wynik1 = 0;
//        //int wynik2 = 0;
//        //int wynik3 = 0;
//        string resultMatrix;

//        for (unsigned i = 0; i < 8; i++) {
//            wynik.at(i) = 0;
//            //cout << wynik.at(i) << " ";
//        }

//        cout << "Elements with value of 1: " << elementsWithValueOfOne << endl;

//        for (unsigned i = 0; i < elementsWithValueOfOne.size(); i++) {

//            zmienna = Dec2Bin(elementsWithValueOfOne.at(i));
//            parityMatrix.push_back(zmienna);
//            //cout << parityMatrix << endl;
//            for (unsigned j = 0; j < parityMatrix.at(i).length(); j++) {

//                //while (parityMatrix.at(i)[j] == '0') continue;
//                if (parityMatrix.at(i)[j] == '1') wynik.at(j)++;
//                //cout << wynik.at(j) << " ";
//            }

//            //wynik = 0;
//            //if (parityMatrix.at(i)[0] == '1') wynik1++;
//            //if (parityMatrix.at(i)[1] == '1') wynik2++;
//            //if (parityMatrix.at(i)[2] == '1') wynik3++;
//        }


//        for (unsigned i = 0; i < parityMatrix.at(0).length(); i++) {
//            if (wynik.at(i) % 2 == 1) resultMatrix.append("1");
//            else resultMatrix.append("0");
//        }



//        cout << resultMatrix << endl;

//        //if (wynik1 % 2 == 1) resultMatrix = "1";
//    //	else resultMatrix = "0";
//        //if (wynik2 % 2 == 1) resultMatrix.append("1");
//        //else resultMatrix.append("0");
//        //if (wynik3 % 2 == 1) resultMatrix.append("1");
//        //else resultMatrix.append("0");

//        //	cout << resultMatrix << endl;

//        int counter2 = resultMatrix.length() - 1;
//        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
//            if ((fmod(log2(i + 1), 1.0)) == 0) {
//                bitWord[i] = resultMatrix[counter2];
//                counter2--;
//            }
//        }

//        cout << "Bit word (complete, with parity bits): " << bitWord << endl;

//        bitWord = mistake(bitWord);
//        cout << endl;

//        elementsWithValueOfOne.clear();
//        parityMatrix.clear();
//        //wynik.clear();

//        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
//            if (bitWord[i] == '1') {
//                elementsWithValueOfOne.push_back(i + 1);
//            }
//        }

//        for (unsigned i = 0; i < 8; i++) {
//            wynik.at(i) = 0;
//            //cout << wynik.at(i) << " ";
//        }
//        //cout << elementsWithValueOfOne << endl;

//        //wynik1 = 0;
//        //wynik2 = 0;
//        //wynik3 = 0;

//        for (unsigned i = 0; i < elementsWithValueOfOne.size(); i++) {

//            zmienna = Dec2Bin(elementsWithValueOfOne.at(i));
//            parityMatrix.push_back(zmienna);
//            //cout << parityMatrix << endl;

//            for (unsigned j = 0; j < parityMatrix.at(i).length(); j++) {

//                //while (parityMatrix.at(i)[j] == '0') continue;
//                if (parityMatrix.at(i)[j] == '1') wynik.at(j)++;
//                //cout << "Wynik at " << j << ": " << wynik.at(j) << " " << endl;
//            }

//            //if (parityMatrix.at(i)[0] == '1') wynik1++;
//            //if (parityMatrix.at(i)[1] == '1') wynik2++;
//            //if (parityMatrix.at(i)[2] == '1') wynik3++;
//        }

//        //cout << parityMatrix << endl;

//        resultMatrix.clear();

//        for (unsigned i = 0; i < parityMatrix.at(0).length(); i++) {
//            if (wynik.at(i) % 2 == 1) resultMatrix.append("1");
//            else resultMatrix.append("0");
//        }

//    //	cout << resultMatrix << endl;

//        //if (wynik1 % 2 == 1) resultMatrix = "1";
//        //else resultMatrix = "0";
//        //if (wynik2 % 2 == 1) resultMatrix.append("1");
//        //else resultMatrix.append("0");
//        //if (wynik3 % 2 == 1) resultMatrix.append("1");
//        //else resultMatrix.append("0");

//        if (resultMatrix == "00000000") {
//            cout << "There were no mistakes found in the Hamming Word." << endl;
//            cout << "Proceeding with decoding..." << endl;

//            int countr = 0;
//            for (int i = 0; i < inputLength + parityBitsNumber; i++) {
//                if ((fmod(log2(i + 1), 1.0)) == 0) {
//                    //if (i == (inputLength + parityBitsNumber - 1)) cout << "Since bit code length = possible parity bit, this will not be erased!" << endl;
//                    //else
//                    bitWord.erase(countr, 1);
//                }
//                else countr++;
//            }

//            reverse(bitWord.begin(), bitWord.end());
//            //bitWord.resize(4);

//            cout << bitWord << endl;

//            if (bitWord == input) {
//                cout << "Decoded bit word: " << bitWord << endl;
//            }
//            else {
//                cout << "We have occurred an error in decoding!" << endl;
//            }

//        } else {

//            int positionValue = Bin2Dec(resultMatrix);

//            cout << "There was a mistake in the Hamming Word occurring at: " << positionValue << " position." << endl;

//            char liedBit = bitWord[positionValue - 1];

//            cout << "Your mistaken bit's value was: " << liedBit << endl;

//            if (liedBit == '0') liedBit = '1';
//            else if (liedBit == '1') liedBit = '0';

//            bitWord[positionValue - 1] = liedBit;

//            cout << "Your mistaken bit has been changed to: " << liedBit << endl;
//            cout << "Proceeding with decoding..." << endl;

//            int countr = 0;
//            for (int i = 0; i < inputLength + parityBitsNumber; i++) {
//                if ((fmod(log2(i + 1), 1.0)) == 0) {
//                    //if (i == (inputLength + parityBitsNumber - 1)) cout << "Since bit code length = possible parity bit, this will not be erased!" << endl;
//                    //else
//                    bitWord.erase(countr, 1);
//                } else countr++;
//            }

//            reverse(bitWord.begin(), bitWord.end());

//            cout << bitWord << endl;

//            if (bitWord == input) {
//                cout << "Decoded bit word: " << bitWord << endl;
//            } else {
//                cout << "We have occurred an error in decoding!" << endl;
//            }
//        }
//    }
}

bool Hamming::IsEmpty(string input) {
    if (input == "" || input.empty())
        return true;
    //cout << "We cannot use Hamming Algorithm on empty string!" << endl;
    else return false;
}
