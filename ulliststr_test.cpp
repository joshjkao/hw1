/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test;
  cout << "ARRSIZE = " << ARRSIZE << endl;

  test.pop_back();
  cout << "pop_back on empty list: " << test.size() << endl;
  test.pop_front();
  cout << "pop_front on empty list " << test.size() << endl;

  test.push_front("1");
  test.push_front("2");
  test.push_front("3");
  cout << "pushing 3 items to front of empty list: ";
  int size = test.size();
  for (int i = 0; i < size; i++) {
    cout << test.get(i) << " ";
  }
  test.clear();

  test.push_back("4");
  test.push_back("5");
  test.push_back("6");
  test.push_back("7");
  test.push_back("8");
  test.push_back("9");
  test.push_back("10");
  test.push_back("11");
  test.push_back("12");
  test.push_back("13");
  test.push_back("14");
  test.push_back("15");
  
  size = test.size();
  cout << endl << "pushing 12 items to back of empty list: ";
  for (int i = 0; i < size; i++) {
    cout << test.get(i) << " ";
  }

  test.push_front("3");
  test.push_front("2");
  test.push_front("1");
  cout << endl << "pushing 3 items to front of list: ";
  size = test.size();
  for (int i = 0; i < size; i++) {
    cout << test.get(i) << " ";
  }

  for (int i = 0; i < 4; i++) {
    test.pop_front();
  }
  cout << endl << "popping first 4 items: ";
  size = test.size();
  for (int i = 0; i < size; i++) {
    cout << test.get(i) << " ";
  }

  for (int i = 0; i < 4; i++) {
    test.pop_back();
  }
  cout << endl << "popping last 4 items: ";
  size = test.size();
  for (int i = 0; i < size; i++) {
    cout << test.get(i) << " ";
  }

  cout << endl << "front: " << test.front();
  cout << endl << "back: " << test.back() << endl;

}
