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



using namespace std;
string pNgreedy(string, int);
void printNeatly(vector<string>, int);

int main() {
    int n = 70;
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

    for (int i = 0; i < n; i++)
	{
		cout << i % 10;
	}
	cout << "  |  padding spaces" << endl;
	cout << "<";
	for (int i = 0; i < n - 2; i++)
	{
		cout << "-";
	}
	cout << ">  |" << endl;

        vector<string> words;
        string word;
    while (mytextfile >> word) {

        words.push_back(word);

    }

    stringstream ss;
    for (int i = 0; i <= words.size() - 1; i++) {
            if (i != 0)
            ss << " ";
            ss << words[i];
    }

        string text = ss.str();


     //cout << text << endl; //

    cout << endl;
    cout << endl;


    printNeatly(words, n);
    

    return 0;



}





