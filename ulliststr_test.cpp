/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("uno ");
  dat.push_front("in_da_front ");
  dat.push_front("really_in_da_front ");
  dat.push_back("dos ");
  dat.push_back("tres ");
  dat.push_back("quatro ");
  dat.push_back("cinco ");
  dat.push_back("seis ");
  dat.push_back("siete ");
  dat.push_back("ocho ");
  dat.push_back("nueve ");
  dat.push_back("diez ");
  dat.push_back("eleven");
  dat.push_back("twelve");
  cout << dat.get(0) << 0 << endl;
  cout << dat.get(1) << 1 << endl;
  cout << dat.get(2) << 2 << endl;
  cout << dat.get(3) << 3 << endl;
  cout << dat.get(4) << 4 << endl;
  cout << dat.get(5) << 5 << endl;
  cout << dat.get(6) << 6 << endl;
  cout << dat.get(7) << 7 << endl;
  cout << dat.get(8) << 8 << endl;
  cout << dat.get(9) << 9 << endl;
  cout << dat.get(10) << 10 << endl;
  cout << dat.get(11) << 11 << endl;
  cout << dat.get(12) << 12 << endl;
  cout << dat.get(13) << 13 << endl;
  cout << dat.front() << endl;
  cout << dat.back() << endl;
  cout << dat.size() << endl;
  dat.pop_back();
  dat.pop_back();
  cout << "popped 12" << endl;
  cout << "popped 11" << endl;
  cout << dat.back() << "back" << endl;
  dat.pop_front();
  dat.pop_front();
  cout << "popped front" << endl;
  cout << "popped front again" << endl;
  cout << dat.front() << " " << dat.get(0) << "front nums" << endl;
  cout << dat.size() << endl;
  return 0;
}
