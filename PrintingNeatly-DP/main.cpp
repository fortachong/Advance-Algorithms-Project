#include<iostream>
#include<cstring>
#include<cstdlib>
#include <string>
#include <vector>
#include <limits.h>
#include <fstream>
#include <stdio.h>
#include <fstream>

using namespace std;

void wrap(vector<string>, int);
int main() {

    int colNum = 25;
    ifstream mytextfile;

    try {
        mytextfile.open("testfile.txt");
        if (!mytextfile) {
            cout << "Error opening file " << endl;
            return 1;
        }
    }

    catch (ifstream::failure()) {
        cout << "Exception opening file " << endl;

    }

    string word;
    for (int k = 0; k < colNum; k++){
        cout << k % 10;
    }
    cout << "   | spaces" << endl;
    cout << "<";

    for (int k = 0; k < colNum - 1; k++) {
        cout << "-";
    }
    cout << ">  |" << endl;


    vector<string> words;
    while (mytextfile >> word) {
            cout << word << endl;
        if (word.size() > colNum) {
            cout << "Words are larger than the size of columns " << endl;
            cin.get();
            return 1;

        }
        words.push_back(word);
        cout << int(words.size()) << endl;
    }
    cout << endl;

    mytextfile.close();
    return 0;

    wrap(words, colNum);

    cout << "Press Enter to exit " << endl;
    cin.get();
    return 0;


}
