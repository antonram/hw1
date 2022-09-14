/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat;

	//NOTE: if get() works, it's because getValAtLoc works!!

	cout << "ULLISTSTR TESTS:" << endl << endl;

//test 1: push front
  dat.push_front("1");
	dat.push_front("2");
	dat.push_front("3");
	dat.push_front("4");
	cout << "TEST 1: " << endl;
	//expected: 4
	cout << dat.size() << endl;
	//expected: 4 3
  cout << dat.get(0) << " " << dat.get(1) << endl;

	//test 2: pop front
	dat.pop_front();
	dat.pop_front();
	cout << "TEST 2: " << endl;
	//expected: 2
	cout << dat.size() << endl;
	//expected: 2 1
  cout << dat.get(0) << " " << dat.get(1) << endl;

	//test 3: pop back
	dat.pop_back();
	cout << "TEST 3: " << endl;
	//expected: 1
	cout << dat.size() << endl;
	//expected: 2
  cout << dat.get(0) << endl;

	//test 4: push back
	dat.push_back("3");
	cout << "TEST 4: " << endl;
	//expected: 2
	cout << dat.size() << endl;
	//expected: 2 3
  cout << dat.get(0) << " " << dat.get(1) << endl;

	//test 5: back()
	cout << "TEST 5: " << endl;
	//expected: 3
	cout << dat.back() << endl;

	//test 6: front()
	cout << "TEST 6: " << endl;
	//expected: 2
	cout << dat.front() << endl;

	//test 7: stress
	dat.push_back("4");
	dat.push_front("5");
	dat.push_back("6");
	dat.push_front("7");
	dat.push_back("8");
	dat.push_front("9");
	dat.push_back("10");
	dat.push_front("11");
	dat.push_back("12");
	dat.push_front("13");
	dat.push_back("14");
	dat.push_front("15");
	dat.push_back("16");
	dat.push_front("17");
	dat.push_back("18");
	dat.push_back("19");
	dat.push_back("20");
	dat.push_back("21");
	dat.push_back("22");
	cout << "TEST 7: " << endl;
	//expected: 17 15 13 11 9 7 5 2 3 4 6 8 10 12 14 16 18 19 20 21 22
	cout << dat.get(0) << " " << dat.get(1) << " " << 
	dat.get(2) << " " << dat.get(3) << " " <<
	dat.get(4) << " " << dat.get(5) << " " <<
	dat.get(6) << " " << dat.get(7) << " " <<
	dat.get(8) << " " << dat.get(9) << " " <<
	dat.get(10) << " " << dat.get(11) << " " <<
	dat.get(12) << " " << dat.get(13) << " " <<
	dat.get(14) << " " << dat.get(15) << " " <<
	dat.get(16) << " " << dat.get(17) << " " <<
	dat.get(18) << " " << dat.get(19) << " " <<
	dat.get(20) << endl;
	//expected: 21
	cout << dat.size() << endl;
	//expected: 17
	cout << dat.front() << endl;
	//expected: 22
	cout << dat.back() << endl;
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	dat.pop_front();
	//expected: 3 4 6 8 10 12 14 16 18 19 20 21 22
	cout << dat.get(0) << " " << dat.get(1) << " " << 
	dat.get(2) << " " << dat.get(3) << " " <<
	dat.get(4) << " " << dat.get(5) << " " <<
	dat.get(6) << " " << dat.get(7) << " " <<
	dat.get(8) << " " << dat.get(9) << " " <<
	dat.get(10) << " " << dat.get(11) << " " <<
	dat.get(12) << endl;
	//expected: 13
	cout << dat.size() << endl;
	//expected: 3
	cout << dat.front() << endl;
	//expected: 22
	cout << dat.back() << endl;
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	dat.pop_back();
	//expected: 3
	cout << dat.get(0) << endl;
	//expected: 1
	cout << dat.size() << endl;
	//expected: 3
	cout << dat.front() << endl;
	//expected: 3
	cout << dat.back() << endl;
	dat.pop_back();
	//expected: 0
	cout << dat.size() << endl;

	//TESTS CONCLUDED
	
  return 0;
}
