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

void lcs( char *X, char *Y)
{
   int m = strlen(X);
   int n = strlen(Y);


   int **c = new int*[(m + 1)*sizeof(int)];
   for (int i = 0; i <= m; i++) {
        c[i] = new int[(n + 1)*sizeof(int)];

    }


   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         c[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         c[i][j] = c[i-1][j-1] + 1;
       else
         c[i][j] = max(c[i-1][j], c[i][j-1]);
     }
   }




   int index = c[m][n];

   // Create a character array to store the lcs
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character


   int i = m, j = n;
   while (i > 0 || j > 0)
   {

      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1];
          i--; j--; index--;
      }


      else if (c[i-1][j] > c[i][j-1])
         i--;
      else
         j--;
   }


    //cout << "LCS of " << X << " and " << Y << " is " << lcs;
    cout << "LCS of X and Y is: " << lcs;
   cout << "\n";
   cout << "Length of LCS is " << c[m][n];

   for (i = 0; i <= m; i++){
        delete c[i];

    }
    delete [] c;


}
