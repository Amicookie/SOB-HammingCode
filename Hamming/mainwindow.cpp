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
    ui->frame_2->setHidden(true);
    ui->frame_3->setHidden(true);

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


string MainWindow::Dec2BinNoZeros(int n) {
    long bin = 0;
    string binStr;
    int r, i = 1;

    while (n != 0) {
        r = n % 2;
        n /= 2;
        bin += r * i;
        i *= 10;
    }
    binStr = valueToString(bin);
    return binStr;
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
        value += valueToString(random);
    }

    return value;
}

void MainWindow::hammingAlgorithm(string input) {

    ui->frame_3->setHidden(false);

    if (input == "" || input.empty()) {
        //cout << "We cannot use Hamming Algorithm on empty string!" << endl;

        QPalette palette = ui->label_9->palette();
         palette.setColor(ui->label_9->foregroundRole(), Qt::red);
        ui->label_9->setPalette(palette);

        ui->label_9->setText("We cannot use Hamming Algorithm on empty string!");

    } else {

        int inputLength = input.length();
        string bitWord = "";
        vector<int> elementsWithValueOfOne;
        string bitNumbers = "";


        int parityBitsNumber = 0;

        if (inputLength == 1) parityBitsNumber = 2;
        else if (inputLength > 1 && inputLength <= 4) parityBitsNumber = 3;
        else if (inputLength > 4 && inputLength <= 11) parityBitsNumber = 4;
        else if (inputLength > 11 && inputLength <= 26) parityBitsNumber = 5;
        else if (inputLength > 26 && inputLength <= 57) parityBitsNumber = 6;
        else if (inputLength > 57 && inputLength <= 120) parityBitsNumber = 7;
        else if (inputLength > 120 && inputLength <= 247) parityBitsNumber = 8;


        int counter = inputLength - 1;
        int cnt = inputLength+parityBitsNumber-1;
        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
            bitNumbers += valueToString(cnt+1)+" ";
            cnt--;
            if ((fmod(log2(i + 1), 1.0)) == 0) {
                bitWord.append("x");
            } else {
                bitWord.append(valueToString(input[counter]));
                counter--;
            }
        }

        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
            if (bitWord[i] == '1') {
                elementsWithValueOfOne.push_back(i + 1);
            }
        }

        reverse(bitWord.begin(), bitWord.end());

        ui->label_7->setText(QString::fromStdString(bitWord));

        reverse(bitWord.begin(), bitWord.end());


        ui->bitsNumbers->setText(QString::fromStdString(bitNumbers));

        //cout << "Bit word (with zeros at parity): " << bitWord << endl;

        string zmienna;
        vector<string> parityMatrix;
        vector<int> wynik(8);
        string resultMatrix;
        for (unsigned i = 0; i < 8; i++) {
            wynik.at(i) = 0;
        }

        //cout << "Elements with value of 1: " << elementsWithValueOfOne << endl;

        if (elementsWithValueOfOne.size() == 0) {
            resultMatrix = "00000000";
        } else {
            for (unsigned i = 0; i < elementsWithValueOfOne.size(); i++) {

                zmienna = Dec2Bin(elementsWithValueOfOne.at(i));
                parityMatrix.push_back(zmienna);
                for (unsigned j = 0; j < parityMatrix.at(i).length(); j++) {
                    if (parityMatrix.at(i)[j] == '1') wynik.at(j)++;
                }
            }


            for (unsigned i = 0; i < parityMatrix.at(0).length(); i++) {
                if (wynik.at(i) % 2 == 1) resultMatrix.append("1");
                else resultMatrix.append("0");
            }
        }
        //cout << resultMatrix << endl;


        string temp2 = "";
        int counter2 = resultMatrix.length() - 1;
        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
            if ((fmod(log2(i + 1), 1.0)) == 0) {
                bitWord[i] = resultMatrix[counter2];
                temp2 += ">tnof/<";
                temp2 += resultMatrix[counter2];
                temp2 += ">'der'=roloc tnof<";
                counter2--;
            } else {
                temp2 += bitWord[i];
            }
        }

        //cout << "Bit word (complete, with parity bits): " << bitWord << endl;

        reverse(temp2.begin(), temp2.end());
        ui->Bit->setText(QString::fromStdString(temp2));

        bitWord = mistake(bitWord, ui->errorBox->value());
        //cout << endl;

        elementsWithValueOfOne.clear();
        parityMatrix.clear();

        for (int i = 0; i < inputLength + parityBitsNumber; i++) {
            if (bitWord[i] == '1') {
                elementsWithValueOfOne.push_back(i + 1);
            }
        }

        for (unsigned i = 0; i < 8; i++) {
            wynik.at(i) = 0;
        }

        if (elementsWithValueOfOne.size() == 0) {
            parityMatrix.push_back("00000000");
        } else {
            for (unsigned i = 0; i < elementsWithValueOfOne.size(); i++) {

                zmienna = Dec2Bin(elementsWithValueOfOne.at(i));
                parityMatrix.push_back(zmienna);

                for (unsigned j = 0; j < parityMatrix.at(i).length(); j++) {

                    if (parityMatrix.at(i)[j] == '1') wynik.at(j)++;
                }

            }
        }

        resultMatrix.clear();

        for (unsigned i = 0; i < parityMatrix.at(0).length(); i++) {
            if (wynik.at(i) % 2 == 1) resultMatrix.append("1");
            else resultMatrix.append("0");
        }


        if (resultMatrix == "00000000") {

            //cout << "There were no mistakes found in the Hamming Word." << endl;
            //cout << "Proceeding with decoding..." << endl;

            ui->label_9->setText("There were no mistakes found in the Hamming Word.\nProceed with decoding...");

            int countr = 0;
            for (int i = 0; i < inputLength + parityBitsNumber; i++) {
                if ((fmod(log2(i + 1), 1.0)) == 0) {
                    bitWord.erase(countr, 1);
                }
                else countr++;
            }

            reverse(bitWord.begin(), bitWord.end());

            //cout << bitWord << endl;
            QString bbitWord = QString::fromStdString(bitWord);

            if (bitWord == input) {
                //cout << "Decoded bit word: " << bitWord << endl;
                ui->PoleRezultatu->setText(bbitWord);

               QPalette palette = ui->label_8->palette();
                palette.setColor(ui->label_8->foregroundRole(), Qt::green);
                ui->label_8->setPalette(palette);
                ui->frame_2->setHidden(false);
                ui->label_8->setText("We have successfully decoded the value!");

            } else {
                //cout << "We have occurred an error in decoding!" << endl;
                QPalette palette = ui->label_8->palette();
                 palette.setColor(ui->label_8->foregroundRole(), Qt::red);
                 ui->label_8->setPalette(palette);
                 ui->frame_2->setHidden(false);

                ui->PoleRezultatu->setText(bbitWord);
                ui->label_8->setText("We have occurred an error in decoding!");
            }

        } else {

            int positionValue = Bin2Dec(resultMatrix);

            if(positionValue-1>inputLength+parityBitsNumber-1) {
                ui->label_9->setText("The position value was higher than the length of bit word.\nThere is possibility of an error for more than 1 bit.\nProceeding with decoding...\n");

                int countr = 0;
                for (int i = 0; i < inputLength + parityBitsNumber; i++) {
                    if ((fmod(log2(i + 1), 1.0)) == 0) {
                        bitWord.erase(countr, 1);
                    } else countr++;
                }

                reverse(bitWord.begin(), bitWord.end());

                //cout << bitWord << endl;

                QString bbitWord = QString::fromStdString(bitWord);

                if (bitWord == input) {
                    //cout << "Decoded bit word: " << bitWord << endl;
                    ui->PoleRezultatu->setText(bbitWord);
                } else {
                    //cout << "We have occurred an error in decoding!" << endl;
                    QPalette palette = ui->label_8->palette();
                     palette.setColor(ui->label_8->foregroundRole(), Qt::red);
                     ui->label_8->setPalette(palette);

                    ui->frame_2->setHidden(false);
                    ui->PoleRezultatu->setText(bbitWord);
                    ui->label_8->setText("We have occurred an error in decoding!");
                }

            } else {
            //cout << "There was a mistake in the Hamming Word occurring at: " << positionValue << " position." << endl;



            ui->label_9->setText(+"There was a mistake in the Hamming Word occurring at: "+ QString::number(positionValue) + " position.\n");

            char liedBit = bitWord[positionValue - 1];



            //cout << "Your mistaken bit's value was: " << liedBit << endl;

            ui->label_9->setText(ui->label_9->text()+"Your mistaken bit's value was: "+ QString(liedBit) + ".\n");

            if (liedBit == '0') liedBit = '1';
            else if (liedBit == '1') liedBit = '0';

            bitWord[positionValue - 1] = liedBit;

            ui->label_9->setText(ui->label_9->text()+"Your mistaken bit has been changed to: "+ QString(liedBit) + ".\nProceeding with decoding...");

            //cout << "Your mistaken bit has been changed to: " << liedBit << endl;
            //cout << "Proceeding with decoding..." << endl;


            int countr = 0;
            for (int i = 0; i < inputLength + parityBitsNumber; i++) {
                if ((fmod(log2(i + 1), 1.0)) == 0) {
                    bitWord.erase(countr, 1);
                } else countr++;
            }

            reverse(bitWord.begin(), bitWord.end());

            //cout << bitWord << endl;

            QString bbitWord = QString::fromStdString(bitWord);

            if (bitWord == input) {
                //cout << "Decoded bit word: " << bitWord << endl;
                ui->PoleRezultatu->setText(bbitWord);
            } else {
                QPalette palette = ui->label_8->palette();
                 palette.setColor(ui->label_8->foregroundRole(), Qt::red);
                 ui->label_8->setPalette(palette);
                //cout << "We have occurred an error in decoding!" << endl;
                 ui->frame_2->setHidden(false);
                ui->PoleRezultatu->setText(bbitWord);
                ui->label_8->setText("We have occurred an error in decoding!");
            }
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
    v.toInt(&ok, 2);

    string bitCode = v.toStdString();

    int bitCodeInt = Bin2Dec(bitCode);

    ui->label_8->setText("");
    ui->PoleRezultatu->setText("");
    ui->label_9->setText("");
    ui->label_7->setText("");
    ui->Bit->setText("");
    ui->bitsNumbers->setText("");

    ui->PoleTekstowe_2->setText(QString::number(bitCodeInt));

    if (ok == false) {
        QPalette palette = ui->label_9->palette();
         palette.setColor(ui->label_9->foregroundRole(), Qt::red);
        ui->label_9->setPalette(palette);

        ui->label_9->setText("The input is not binary! ");
    } else
        hammingAlgorithm(bitCode);
}

void MainWindow::on_RandomButton_clicked()
{
    int x = ui->RandomBoxer->value();
    int number = qPow(2, ui->RandomBoxer->value());
    int randomValue = 0;
    //this code fragment is responsible for ensuring that the randomised bits are never equal to zero!
    while (randomValue==0) randomValue = qrand() % number;
    string temp = Dec2Bin(randomValue);
    string random = temp.substr(temp.length()-x,x);
    ui->PoleTekstowe->setText(QString::fromStdString(random));
    int randomInt = Bin2Dec(random);
    ui->PoleTekstowe_2->setText(QString::number(randomInt));
}

void MainWindow::on_StartButton_2_clicked()
{
    QString v = ui->PoleTekstowe_2->text();
   // string bitCode = "";
    bool ok;
    string bitCode = Dec2BinNoZeros(v.toInt(&ok, 10));
//    for(int i=0; i < temp.length(); i++){
//        if(temp[i]=='0') continue;
//        else bitCode += temp[i];
//    }
    //ui->temp->setText(+"Displayed value: " + QString::number(v.toInt(&ok, 10)));
    ui->label_8->setText("");
    ui->PoleRezultatu->setText("");
    ui->label_9->setText("");
    ui->label_7->setText("");
    ui->Bit->setText("");
    ui->bitsNumbers->setText("");
    ui->PoleTekstowe->setText(QString::fromStdString(bitCode));

    if (ok == false) {
        QPalette palette = ui->label_9->palette();
         palette.setColor(ui->label_9->foregroundRole(), Qt::red);
        ui->label_9->setPalette(palette);

        ui->label_9->setText("The input is not decimal! ");
    } else
        hammingAlgorithm(bitCode);

}
