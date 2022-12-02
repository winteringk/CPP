#include<iostream>
#include "HW01.cpp"
using namespace std;

int main()
{

  CardList L;

  L.insert_back("p1");
  L.printCardList();
  L.insert_back("p2");
  L.printCardList();
  L.insert_back("p3");
  L.printCardList();
  L.insert_back("p4");
  L.printCardList();

  L.pop_back();
  L.printCardList();
  L.pop_back();
  L.printCardList();
  L.pop_back();
  L.printCardList();
  L.pop_back();
  L.printCardList();
  L.pop_back();
  L.printCardList();
  L.pop_back();
  L.printCardList();

  return 0;
}
