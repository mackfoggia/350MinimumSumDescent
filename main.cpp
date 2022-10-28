// Mack Foggia - CS 350 - 4/30/2021 - Minimum Sum Descent

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


#define n 5
int arr[(n * 2) - 1][n];
int T[(n * 2) - 1][n];
int T2[(n * 2) - 1][n];
int rx = n*2-1;


void clear();
void display();
void build(int, int);
int findSmallest(int x, int y);
int findSmallestM(int x, int y);
int findSmallestT();



int main(){
  srand(time(NULL));
 
  clear();
  build(n-1, 0);
  display();

  cout << "Smallest sum: " << findSmallest(n-1, 0) << endl;
  cout << "Smallest sum - M: " << findSmallestM(n-1, 0) << endl;
  cout << "Smallest sum - T: " << findSmallestT() << endl;


  return 0;
}




int findSmallest(int x, int y){
  if(y >= n) return 0;
  //if(y == (n - 2) && x == 3) cout << "Doing the thing" << endl;
  int data = arr[x][y];
  int left = data + findSmallest(x-1, y+1);
  int right = data + findSmallest(x+1, y+1);
  return min(left, right);
}

int findSmallestM(int x, int y){
  if(y >= n) return 0;
  if(T[x][y] != -1) return T[x][y];
  //if(y == (n - 2) && x == 3) cout << "Doing the thing" << endl;
  int data = arr[x][y];
  int left = data + findSmallestM(x-1, y+1);
  int right = data + findSmallestM(x+1, y+1);
  T[x][y] = min(left, right);
  return T[x][y];
}

int findSmallestT(){
  int start = 0;
  int count = n;
  int y = n-1;

  while(y >= 0){
    int x = start;
    int i = 0;
    while(i < count){
      if(y == n) T2[x][y] = arr[x][y];
      else T2[x][y] = arr[x][y] + min(T2[x-1][y+1], T2[x+1][y+1]);
      x += 2;
      ++i;
    }
    i = 0;
    --count;
    ++start;
    --y;
  }

  return T2[n-1][0];
}



void build(int x, int y){
  if(y >= n) return;
  arr[x][y] = rand() % 15 + 1;
  build(x+1, y+1);
  build(x-1, y+1);
}

void display(){
  for(int y = 0; y < n; ++y){
    for(int x = 0; x < rx; ++x){
      if(arr[x][y] == 0) cout << "  ";
      else cout << arr[x][y] << " ";
    }
    cout << endl;
  }
}

void clear(){
  for(int x = 0; x < rx; ++x){
    for(int y = 0; y < n; ++y){
      arr[x][y] = 0;
      T[x][y] = -1;
      T2[x][y] = 0;
    }
  }
}

