#include <iostream>
#include <string>
#include <sstream>

#include "array.h"

using namespace std;

// Funzione ausiliaria: stampa un array
string print(int a[], int n)
{
  stringstream out;
  out<<"[ ";
  for(int i=0;i<n;i++)out<<a[i]<<" ";
  out<<"]";
  return out.str();
}

// Funzione ausiliaria: stampa un bool come stringa true/false
string bpr(bool x)
{
  return x ? string("true") : string("false");
}

// Programma di test su quattro array u, a, b, c
int main()
{
  int nb, na;
  int u[]={ 6, 1, 2, 2, 4, 3, 3, 2, 3, 4, 9, 5, 4, 5 };
  nb = sizeof u/sizeof(int);
  cout<< "u - Sorted: "<< bpr(isSorted(u,nb)) <<"; content: "<< print(u,nb) <<"\n";
  int a[]={ 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5 };
  nb = sizeof a/sizeof(int);
  cout<< "a before removeDuplicates  - Sorted: "<< bpr(isSorted(a,nb)) <<"; content: "<< print(a,nb) <<"\n";
  na=removeDuplicates(a, nb);
  cout<< nb << " --> " << na <<"\n";
  cout<< "a after removeDuplicates  - Sorted: "<< bpr(isSorted(a,na)) <<"; content: "<< print(a,na) <<"\n";
  int b[]={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  nb = sizeof b/sizeof(int);
  cout<< "b before removeDuplicates  - Sorted: "<< bpr(isSorted(b,nb)) <<"; content: "<< print(b,nb) <<"\n";
  na=removeDuplicates(b, nb);
  cout<< nb << " --> " << na <<"\n";
  cout<< "b after removeDuplicates  - Sorted: "<< bpr(isSorted(b,na)) <<"; content: "<< print(b,na) <<"\n";
  int c[]={ 1 };
  nb = sizeof c/sizeof(int);
  cout<< "c before removeDuplicates  - Sorted: "<< bpr(isSorted(c,nb)) <<"; content: "<< print(c,nb) <<"\n";
  na=removeDuplicates(c, nb);
  cout<< nb << " --> " << na <<"\n";
  cout<< "c after removeDuplicates  - Sorted: "<< bpr(isSorted(c,na)) <<"; content: "<< print(c,na) <<"\n";
}
