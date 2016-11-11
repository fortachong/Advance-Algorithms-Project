#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cctype>
#include <math.h>
#include <cmath>
#include <sstream>
#include <algorithm>



using namespace std;
string pNgreedy(string, int);
void printNeatly(vector<string>, int);
char *lcs2(char*, char*);
char *convert(const std::string & s);
void lcs(char*, char*);

int main() {
    int n = 70;
        ifstream mytextfile;

    try {
        mytextfile.open("g4pC_taska.txt");
        if (!mytextfile) {
            cout << "Error opening file " << endl;
            return 1;
        }
    }

    catch (ifstream::failure()) {
        cout << "Exception opening file " << endl;

    }
    ifstream originalfile;

    try {
        originalfile.open("orig_taska.txt");
        if (!originalfile) {
            cout << "Error opening file " << endl;
            return 1;
        }
    }

    catch (ifstream::failure()) {
        cout << "Exception opening file " << endl;
    }

    /* for (int i = 0; i < n; i++)
	{
		cout << i % 10;
	}
	cout << "  |  padding spaces" << endl;
	cout << "<";
	for (int i = 0; i < n - 2; i++)
	{
		cout << "-";
	}
	cout << ">  |" << endl; */

        vector<string> words;
        vector<string> words_original;
        string word;
        string word_original;

    while (mytextfile >> word) {

        words.push_back(word);

    }

    while (originalfile >> word_original) {
        words_original.push_back(word_original);
    }

    stringstream ss;
    stringstream ss1;
    for (int i = 0; i <= words.size() - 1; i++) {
            if (i != 0)
            ss << " ";
            ss << words[i];
    }

    for (int i = 0; i <= words_original.size() - 1; i++) {
            if (i != 0)
            ss1 << " ";
            ss1 << words_original[i];
    }

        string text = ss.str();
        string original_text = ss1.str();

        char* wordsc = new char[text.length() + 1];
        char* words_originalc = new char [original_text.length() + 1];
        strcpy(wordsc, text.c_str());
        strcpy(words_originalc, original_text.c_str());

        string result;
        result = lcs2(wordsc, words_originalc);


     //cout << text << endl; //

    cout << endl;
    cout << endl;
    cout << "LCS is: " << result;
    cout << endl;
    cout << endl;
    lcs(wordsc, words_originalc);


    /* printNeatly(words, n);
    cout << endl;
    cout << endl;
    cout << pNgreedy(text, n) << endl; */

    delete [] wordsc;
    delete [] words_originalc;

    return 0;



}





