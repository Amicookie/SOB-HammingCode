#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <string>
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

template<class T>
string MainWindow::valueToString(T value) {
    ostringstream oss;
    oss << value;
    return oss.str();
}

template<class T>
T MainWindow::stringToValue(string str) {
    istringstream iss(str);
    T value;
    iss >> value;
    return value;
}

string MainWindow::mistake(string data, int rn) {
    srand(time(NULL));
        int l = data.length();
        for (int i = 0; i<rn; i++) {
            int rd = rand() % l;
            //cout << endl << "Bit: " << rd + 1;
            if (data[rd] == '1')
                data[rd] = '0';
            else
                data[rd] = '1';
            }
        //cout << endl << data;
        return data;
}

string MainWindow::Dec2Bin(int n) {
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
        binStr = "0000000"; binStr.append(valueToString(bin));}
    else if (bin < 100) {
        binStr = "000000"; binStr.append(valueToString(bin));}
    else if (bin < 1000) {
        binStr = "00000"; binStr.append(valueToString(bin));}
    else if (bin < 10000) {
        binStr = "0000"; binStr.append(valueToString(bin));}
    else if (bin < 100000) {
        binStr = "000";	binStr.append(valueToString(bin));}
    else if (bin < 1000000) {
        binStr = "00"; binStr.append(valueToString(bin));}
    else if (bin < 10000000) {
        binStr = "0"; binStr.append(valueToString(bin));}
    else
        binStr = valueToString(bin);

    return binStr;
}

int MainWindow::Bin2Dec(string m) {
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



string MainWindow::generateRandom(int length) {
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

void MainWindow::hammingAlgorithm(string input) {

    //hamming code (7,4) - we can only have an input of 1-4 bits!
    if (input == "" || input.empty()) {
        //cout << "We cannot use Hamming Algorithm on empty string!" << endl;
        //ui->PoleTekstowe->setText("U R STOOPID :/");
        ui->PoleTekstowe->setText("We cannot use Hamming Algorithm on empty string!");

        // JESLI PODAMY NA WEJSCIU PUSTOSC, TO WTEDY BEDZIE NICZEGO, i okienko sobie samo z tym poradzi

    } else {

        int inputLength = input.length(); // DLUGOSC INPUTA, DEFINICJA ZE WYNOSI DLUGOSC ZMIENNEJ INPUT (PARAMETR METODY, A TAKZE)
        string bitWord = ""; // DEFINICJA STRINGA BITWORD, NA RAZIE JEST ON ZADEKLAROWANY JAKO PUSTY PUSTY (MOZNABY ZROBIC Z BITWORDA PRYWATNY PARAMETR)
        vector<int> elementsWithValueOfOne; // DEKLARACJA WEKTORA INTOW O NAZWIE ELEMENTSWIHVALUEOFONE


        int parityBitsNumber = 0; // DEFINICJA PARITYBITSNUMBER, INICJALNIE WYNOSI ZERO

        if (inputLength == 1) parityBitsNumber = 2; // JEZELI DLUGOSC WYRAZENIA BITOWEGO MA JEDEN ZNAK, TO WTEDY ILOSC BITOW PARZYSTOSCI WYNOSI DWA
        else if (inputLength > 1 && inputLength <= 4) parityBitsNumber = 3; // JEZELI DLUGOSC WYRAZENIA BITOWEGO MA OD DWOCH DO CZTERECH ZNAKOW, TO WTEDY ILOSC BITOW PARZYSTOSCI WYNOSI TRZY
        else if (inputLength > 4 && inputLength <= 11) parityBitsNumber = 4; // JEZELI DLUGOSC WYRAZENIA BITOWEGO MA OD PIECIU DO JEDENASTU ZNAKOW, TO WTEDY ILOSC BITOW PARZYSTOSCI WYNOSI CZTERY
        else if (inputLength > 11 && inputLength <= 26) parityBitsNumber = 5; // JEZELI DLUGOSC WYRAZENIA BITOWEGO MA OD DWUNASTU DO DWUDZIESTU SZESCIU ZNAKOW, TO WTEDY ILOSC BITOW PARZYSTOSCI WYNOSI PIEC
        else if (inputLength > 26 && inputLength <= 57) parityBitsNumber = 6; // JEZELI DLUGOSC WYRAZENIA BITOWEGO MA OD DWUDZIESTU SIEDMIU DO PIECDZIESIECIU SIEDMIU ZNAKOW, TO WTEDY ILOSC BITOW PARZYSTOSCI WYNOSI SZESC
        else if (inputLength > 57 && inputLength <= 120) parityBitsNumber = 7; // JEZELI DLUGOSC WYRAZENIA BITOWEGO MA OD PIECDZIESIECIU OSMIU DO STU DWUDZIESTU ZNAKOW, TO WTEDY ILOSC BITOW PARZYSTOSCI WYNOSI SIEDEM
        else if (inputLength > 120 && inputLength <= 247) parityBitsNumber = 8; // JEZELI DLUGOSC WYRAZENIA BITOWEGO MA OD STU DWUDZIESTU JEDNEGO DO DWUSTU CZTERDZIESTU SIEDMIU ZNAKOW, TO WTEDY ILOSC BITOW PARZYSTYCH WYNOSI OSIEM I FINITO



        int counter = inputLength - 1; // DEFINICJA LICZNIKA KTORY MA WARTOSC DLUGOSCI INPUTA MINUS JEDEN
        for (int i = 0; i < inputLength + parityBitsNumber; i++) { // OD ZERA DO DLUGOSCI INPUTA + BITY PARZYSTOSCI

            if ((fmod(log2(i + 1), 1.0)) == 0) { // JEZELI wut????????????? SKAD TO?
                bitWord.append("0"); // DODAJ DO STRINGA BITWORD ZERO
            } else { // INACZEJ
                bitWord.append(valueToString(input[counter])); // DODAJ DO STRINGA BITWORD BITA ZE STRINGA INPUT O ID COUNTER (????)
                counter--; // ZMNIEJSZ COUNTER O 1
            }
        }


        for (int i = 0; i < inputLength + parityBitsNumber; i++) { // OD ZERA DO DLUGOSCI INPUTA + BITY PARZYSTOSCI
            if (bitWord[i] == '1') { // JEZELI ELEMENT SLOWA BITOWEGO JEST ROWNE 1
                elementsWithValueOfOne.push_back(i + 1); // PRZESUN COS TAM W TYM WEKTORZE
            }
        }

        //cout << "Bit word (with zeros at parity): " << bitWord << endl; // WYPISZ ZEROESY

        string zmienna; // DEKLARACJA STRINGA O NAZWIE ZMIENNA
        vector<string> parityMatrix; // DEKLARACJA WEKTORA STRINGÓW O NAZWIE PARITYMATRIX
        vector<int> wynik(8); // DEKRARACJA WEKTORA STRINGOW O NAZWIE WYNIK I DLUGOSCI 8
        string resultMatrix; // DEKLARACJA STRINGA O NAZWIE RESULTMATRIX

        for (unsigned i = 0; i < 8; i++) { // OD 0 DO 7
            wynik.at(i) = 0; //ELEMENT WEKTORA I = ZERO
        } // SERIO NIE DA SIE ZAINICJALIZOWAC WEKTORA O JEDNAKOWYCH WARTOSCIACH BEZ PETLI FOR? XD

        //cout << "Elements with value of 1: " << elementsWithValueOfOne << endl; // WYPISZ ELEMENTY O WARTOSCIACH 1, CO WIDOCZNIE PRZECHOWUJE SIE W WEKTORZE ELEMENTS WITH VALUE OF ONE

        for (unsigned i = 0; i < elementsWithValueOfOne.size(); i++) { // OD 0 DO ROZMIARU WEKTORA ELEMENTSWITHVALUEOFONE

            zmienna = Dec2Bin(elementsWithValueOfOne.at(i)); // PRZYPISANIE DO STRINGA ZMIENNA WARTOSCI KOLEJNEGO ELEMENTSWITHVALUEOFONE WARTOSCI BINARNEJ
            parityMatrix.push_back(zmienna); //PRZYPISANIE DO WEKTORA STRINGOW PARITYMATRIX WARTOSC ZMIENNEJ
            for (unsigned j = 0; j < parityMatrix.at(i).length(); j++) { //OD ZERA DO ROZMIARU KOLEJNEGO STRINGA STRINGA

                if (parityMatrix.at(i)[j] == '1') wynik.at(j)++; // JESLI COS TAM JEST JEDEN TO KOLEJNY WYNIK SIE ZWIEKSZA O 1 (??)
            }

        }


        for (unsigned i = 0; i < parityMatrix.at(0).length(); i++) { // DOBRA NIE WIEM CO TU SIE DZIEJE
            if (wynik.at(i) % 2 == 1) resultMatrix.append("1");
            else resultMatrix.append("0");
        }



        //cout << resultMatrix << endl; //WYPISZ STRINGA RESULT MATRIX


        int counter2 = resultMatrix.length() - 1; // TUTAJ TEZ NIE WIEM CO SIE DZIEJE
        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
            if ((fmod(log2(i + 1), 1.0)) == 0) {
                bitWord[i] = resultMatrix[counter2];
                counter2--;
            }
        }

        //cout << "Bit word (complete, with parity bits): " << bitWord << endl; // WYPISZ KOMPLETNE SLOWO BITOWE Z PRAWIDLOWYMI BITAMI PARZYSTOSCI, A NIE SAMYMI ZERAMI JAK WCZESNIEJ

        ui->Bit->setText(QString::fromStdString(bitWord));

        bitWord = mistake(bitWord, ui->errorBox->value()); //POPSUJ BITOWE SLOWO, ALBO NIE, BO TO RANDOM JEST
        //cout << endl;

        elementsWithValueOfOne.clear(); // WYCZYSC ELEMENTY Z TEGO WEKTORA
        parityMatrix.clear(); // I Z TEGO TEZ

        for (int i = 0; i < inputLength + parityBitsNumber; i++) { // OD ZERA DO DLUGOSCI CALEGO SLOWA
            if (bitWord[i] == '1') { // JESLI BIT JEST ROWNY JEDEN TO WRZUC JEGO ID DO ELEMENTOW Z WARTOSCIA JEDEN
                elementsWithValueOfOne.push_back(i + 1);
            }
        }

        for (unsigned i = 0; i < 8; i++) { // WYPELNIJ ZNOWU TA TABLICE ZERAMI
            wynik.at(i) = 0;
        }

        for (unsigned i = 0; i < elementsWithValueOfOne.size(); i++) { // WYKONAJ RAZY ILOSC JEDYNEK W SLOWIE BITOWYM

            zmienna = Dec2Bin(elementsWithValueOfOne.at(i)); // PRZYPISZ DO STRINGA ZMIENNA BINARNA WARTOSC ELEMENTU O JEDYNCE?
            parityMatrix.push_back(zmienna);

            for (unsigned j = 0; j < parityMatrix.at(i).length(); j++) {

                if (parityMatrix.at(i)[j] == '1') wynik.at(j)++;
            }

        }


        resultMatrix.clear(); // WYCZYSC RESULT MATRIX

        for (unsigned i = 0; i < parityMatrix.at(0).length(); i++) {
            if (wynik.at(i) % 2 == 1) resultMatrix.append("1");
            else resultMatrix.append("0");
        }


        if (resultMatrix == "00000000") { //JESLI WYNIKOWY STRING RESULT MATRIX WYNOSI 00000000 TO
            //cout << "There were no mistakes found in the Hamming Word." << endl; // NIE ZNALAZLO BLEDOW W HAMMINGU
            //cout << "Proceeding with decoding..." << endl;

            int countr = 0; // DEFINICJA LICZNIKA COUNTR ROWNEGO 0
            for (int i = 0; i < inputLength + parityBitsNumber; i++) { // OD ZERA DO ROZMIARU CALEGO SLOWA
                if ((fmod(log2(i + 1), 1.0)) == 0) { // IDK
                    bitWord.erase(countr, 1);
                }
                else countr++; // ZWIEKSZ LICZNIK
            }

            reverse(bitWord.begin(), bitWord.end()); // ODWROC SLOWO BINARNE TYL NA PRZOD

            //cout << bitWord << endl; // WYPISZ STRINGA BITWORD

            if (bitWord == input) { // JESLI TEN BITWORD JEST TAKI SAM JAK INPUT, TO TO JEST FAJNE
                //cout << "Decoded bit word: " << bitWord << endl; // WYPISZ ZE TO JEST FAJNE (Ten bitWord sie wypisuje tutaj juz drugi raz)
                //pick Mercy
                QString bbitWord = QString::fromStdString(bitWord);
                bool ok;
                int bin = bbitWord.toInt(&ok, 2);
                if (ok==true) ui->outsert->display(bin);
                //Tracer switch
                ui->PoleRezultatu->setText(bbitWord);

            }
            else { // A INACZEJ NIE JEST FAJNE
                //cout << "We have occurred an error in decoding!" << endl; // WYPISZ ZE TO JEST NIE JEST FAJNE
                ui->PoleRezultatu->setText("We have occurred an error in decoding!");
            }

        } else { // JESLI MATRIX NIE JEST 00000000

            int positionValue = Bin2Dec(resultMatrix); // WYTLUMACZCIE MI CO TU SIE DZIEJE

            //cout << "There was a mistake in the Hamming Word occurring at: " << positionValue << " position." << endl;

            char liedBit = bitWord[positionValue - 1];

            //cout << "Your mistaken bit's value was: " << liedBit << endl;

            if (liedBit == '0') liedBit = '1';
            else if (liedBit == '1') liedBit = '0';

            bitWord[positionValue - 1] = liedBit;

            //cout << "Your mistaken bit has been changed to: " << liedBit << endl;
            //cout << "Proceeding with decoding..." << endl;

            int countr = 0;
            for (int i = 0; i < inputLength + parityBitsNumber; i++) {
                if ((fmod(log2(i + 1), 1.0)) == 0) {
                    bitWord.erase(countr, 1);
                } else countr++;
            }

            reverse(bitWord.begin(), bitWord.end()); // ODWROC SLOWO BINARNE TYL NA PRZOD

            //cout << bitWord << endl; // WYPISZ STRINGA BITWORD

            if (bitWord == input) {
                //cout << "Decoded bit word: " << bitWord << endl;
                QString bbitWord = QString::fromStdString(bitWord);
                bool ok;
                int bin = bbitWord.toInt(&ok, 2);
                if (ok==true) ui->outsert->display(bin);
                ui->PoleRezultatu->setText(bbitWord);
            } else {
                //cout << "We have occurred an error in decoding!" << endl;
                ui->PoleRezultatu->setText("We have occurred an error in decoding!");
            }
        }
    }
}

void MainWindow::on_Quit_clicked()
{
    MainWindow::close();
}

void MainWindow::on_StartButton_clicked()
{
    QString v = ui->PoleTekstowe->text();
    bool ok;
    int dec = v.toInt(&ok, 10);
    if (ok==true) ui->insert->display(dec);
    int bin = v.toInt(&ok, 2);
    if (ok==true) ui->insert->display(bin);
    std::string bitCode = v.toStdString();
    //if(x->IsEmpty(bitCode)) ui->PoleTekstowe->setText("U R STOOPID :/");
    hammingAlgorithm(bitCode);


}

void MainWindow::on_RandomButton_clicked()
{
    int number = qPow(2, ui->RandomBoxer->value());
    int randomValue = qrand() % number;
    ui->PoleTekstowe->setText(QString::number(randomValue));
    ui->insert->display(randomValue);
}
