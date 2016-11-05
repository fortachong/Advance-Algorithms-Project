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

string pNgreedy(string text, int n){
    istringstream words(text);
    ostringstream print_greedy;
    string word;

    if (words >> word) {
        print_greedy << word;
        size_t space_left = n - word.length();

        while (words >> word) {
            if (space_left < word.length() + 1) {
                print_greedy << '\n' << word;
                space_left = n - word.length();
            }
            else {
                print_greedy << ' ' << word;
                space_left -= word.length() + 1;
            }
        }
    }
    return print_greedy.str();
}

