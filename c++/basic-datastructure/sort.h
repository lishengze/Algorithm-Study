#ifndef _SORT_H_
#define _SORT_H_

typedef int(*CompareFunc)(int, int);

int isBigger(int value1, int value2);

// double log2(double value);

class BasicSort {
public:
	void _quickSort(int * originalData, int startIndex, int endIndex, CompareFunc func);

	void quickSort(int * originalData, int dataLength);

	void _bubbleSort(int * originalData, int startIndex, int endIndex, CompareFunc func);

	void bubbleSort(int * originalData, int dataLength);

	void _merge(int * originalData, int startIndex, int endIndex, CompareFunc func);

	void _mergeSort(int * originalData, int startIndex, int endIndex, CompareFunc func);

	void mergeSort(int * originalData, int dataLength);

	int getHeapRootIndex(int startIndex, int endIndex);

	void makeHeap(int * originalData, int startIndex, int endIndex, CompareFunc func);

	void _heapSort(int * originalData, int startIndex, int endIndex, CompareFunc func);

	void heapSort(int * originalData, int dataLength);
};

#endif // !_SORT_H_
