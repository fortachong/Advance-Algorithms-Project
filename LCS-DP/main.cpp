#include<iostream>
#include<cstring>
#include<cstdlib>
#include <string>

using namespace std;

char* lcs2(char *, char *);
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
