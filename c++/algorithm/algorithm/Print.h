#ifndef _PRINT_H_
#define _PRINT_H_

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

template<class datatype>
void PrintData(string dataDescription, datatype* data, int datalength = 1) {
	cout << dataDescription << endl;
	for (int i = 0; i < datalength; ++i) {
		cout << *(data++) << " ";
	}
	cout << endl;
}

#endif // !_PRINT_H_
