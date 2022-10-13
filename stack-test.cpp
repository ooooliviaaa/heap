#include<iostream> 
#include "stack.h"
using namespace std;


int main(){
  //declare a new stack int type s 
  Stack<int> s;
  //test push function 
  s.push(1);
  //test top function
  cout << s.top() << endl;
  // test pop 
  s.pop();
  s.pop();
  //test if empty()
  cout << s.top() << endl;
  return 0;
}