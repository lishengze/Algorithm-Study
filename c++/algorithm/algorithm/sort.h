#ifndef _SORT_H_
#define _SORT_H_

typedef int(*CompareFunc)(int, int);

int isBigger(int value1, int value2);

class BasicSort {
public:
	void _quickSort(int * originalData, int startIndex, int endIndex, CompareFunc func);
};

#endif // !_SORT_H_
