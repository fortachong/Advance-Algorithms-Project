#include<iostream>
#include<cstring>
#include<cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <fstream>

/* INT_MAX defines the maximum number an int can have */
#define MAXINT INT_MAX

using namespace std;

int printingNeatly(int ps[], int n, vector<string> words, int colNum){
        int x;
        if (ps[n] == 1)
            x = 1;
        else
            x = printingNeatly(ps, ps[n], words, colNum) + 1;
        int s = 0; /* size */
        int wordsNumInLine = 0;
        for (int i = ps[n]; i <= n; i++){
            s += words[i - 1].size();
            cout << words[i - 1] << " ";
            wordsNumInLine++;
        }
        int spaces = colNum - s;
        if (wordsNumInLine > 1){
            spaces = spaces - (wordsNumInLine - 1);
        }
        cout << std::string(spaces, ' ') << " |  " << spaces << endl;
        return x;

}

void wrap(vector<string> words, int colNum){
    int s_words = words.size();

    /* We need to define spaces in a table where we store the words
    from i to j in a single line */

    int tableSpace[s_words + 1][s_words + 1];

    /* Then, we need to define a table where we put the cost
    of a line from words i to j */

    int costLine[s_words + 1][s_words + 1];

    /* Last, a table to save the total cost */

    int totalCost[s_words + 1];

    /* Array to print the solution */
    int print_sol[s_words + 1];

    int t, u;

    /* Find extra spaces in a single line */

    for (t = 1; t <= s_words; t++){
        /* Calculate number of spaces */
        tableSpace[t][t] = colNum - words[t - 1].size();
        for (u = 1; u <= s_words; u++){
            tableSpace[t][u] = tableSpace[t][u - 1] - words[u - 1].size() - 1;

        }

    }

    /* Calculate cost based on spaces */
    for (t = 1; t <= s_words; t++ ) {
        for (u = t; u <= s_words; u++) {
            /* If we have a huge number of words
            in a single line */
            if (tableSpace[t][u] < 0)
                costLine[t][u] = MAXINT;

                /* Do not count the cost of the last line */
                else if (u == s_words && tableSpace[t][u] >= 0)
                    costLine[t][u] = 0;

                /* Cost of each line is tableSpace[i][j]^3 */
                        else
                            costLine[t][u] = tableSpace[t][u]*tableSpace[t][u]*tableSpace[t][u];


        }
    }

    totalCost[0] = 0;
    for (u = 1; u <= s_words; u++) {
        totalCost[u] = MAXINT;

        for (t = 1; t <= u; t++) {
            if (totalCost[t - 1] != MAXINT && costLine[t][u] != MAXINT && (totalCost[t - 1] + costLine[t][u] < totalCost[u])) {
                totalCost[u] = totalCost[t - 1] + costLine[t][u];
                print_sol[u] = t;
            }
        }
    }

    printingNeatly(print_sol, s_words, words, colNum);
    cout << "Penalty: " << totalCost[s_words] << endl;

}


