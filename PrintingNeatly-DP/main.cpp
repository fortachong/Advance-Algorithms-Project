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

using namespace std;

/* char* lcs2(char *, char *);
void lcs(char *, char *);

int main()
{
  char x[] = "ABBDDBDGG";
  char y[] = "GBDBAGB";


  string result;

  result = lcs2(x, y);

  cout << "LCS using lcs2 function is : " << result;
  cout << "\n";
  cout << "LCS using lcs function is  : " ;
  lcs(x, y);

  return 0;
}
*/

void printNeatly (vector<string> , int);
int giveLines(int *, int, vector<string>, int);

int main() {

    int M = 30;

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
    for (int k = 0; k < M; k++){
        cout << k % 10;
    }
    cout << "   | spaces" << endl;
    cout << "<";

    for (int k = 0; k < M - 2; k++) {
        cout << "-";
    }
    cout << ">  |" << endl;


    vector<string> words;
    while (mytextfile >> word) {
            cout << word << endl;

        if (word.size() > M) {
            cout << "Words are larger than the size of M " << endl;
            cin.get();
            return 1;

        }
        words.push_back(word);
        cout << int(words.size()) << endl;
    }



    cout << endl;



    mytextfile.close();



    printNeatly(words, M);



    cout << "Press Enter to exit " << endl;
    cin.get();
    return 0;


}
