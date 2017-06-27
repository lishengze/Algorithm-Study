#include "test.h"
#include "sort.h"
#include <exception>
using std::exception;

void testSort() {
	try {
		int dataLength = 10;
		int* originalData = new int[dataLength];
		if (!originalData) {
			cout << "分配内存失败!" << endl;
		}

		for (int i = 0; i < dataLength; ++i) {
			originalData[i] = dataLength - i;
		}

		PrintData("Original Data: ", originalData, dataLength);

		BasicSort baseSortObj = BasicSort();

		// baseSortObj._quickSort(originalData, 0, dataLength - 1, isBigger);
		// PrintData("QuickSorted Data: ", originalData, dataLength);

		baseSortObj.bubbleSort(originalData, dataLength);
		PrintData("BubbleSorted Data: ", originalData, dataLength);

		if (originalData) {
			delete[] originalData;
			originalData = NULL;
		}

	}
	catch (exception* exceptionPointer) {
		PrintData("发生异常， 异常为: ", exceptionPointer->what());
	}

}

void testMerge() {
	try {
		const int dataLength = 10;
		// int originalData[dataLength] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
		int originalData[dataLength] = {10, 8, 7, 7, 6, 5, 4, 3, 2, 1};
		BasicSort baseSortObj = BasicSort();

		PrintData("Original Data: ", originalData, dataLength);

		// baseSortObj._merge(originalData, 0, dataLength-1, isBigger);
		baseSortObj.mergeSort(originalData, dataLength);
		PrintData("MergeSort Data: ", originalData, dataLength);

	} catch (exception* exceptionPointer) {
		PrintData("发生异常， 异常为: ", exceptionPointer->what());		
	}
}

void testGetHeapRootIndex () {
	try {
		const int dataLength = 5;
		int originalData[dataLength] = {1, 3, 4, 6, 8};
		BasicSort baseSortObj = BasicSort();
		for (int i=0; i < dataLength; ++i) {
			baseSortObj.getHeapRootIndex(0, originalData[i]);
		}

		int a[] = {16,7,3,20,17,8};

	} catch (exception* exceptionPointer) {
		PrintData("发生异常， 异常为: ", exceptionPointer->what());		
	}	
}

void testMakeHeap() {
	try {
		const int dataLength = 6;
		int originalData[dataLength] = {20, 7, 3, 16, 17, 8};
		BasicSort baseSortObj = BasicSort();

		PrintData("original data: ", originalData, dataLength);

		baseSortObj.makeHeap(originalData, 0, dataLength-1, isBigger);

		PrintData("Heap data: ", originalData, dataLength);

	} catch (exception* exceptionPointer) {
		PrintData("发生异常， 异常为: ", exceptionPointer->what());		
	}
} 

void testHeapSort() {
	try {
		const int dataLength = 6;
		int originalData[dataLength] = {20, 7, 3, 16, 17, 8};
		BasicSort baseSortObj = BasicSort();

		PrintData("original data: ", originalData, dataLength);

		baseSortObj._heapSort(originalData, 0, dataLength-1, isBigger);

		PrintData("HeapSorted data: ", originalData, dataLength);

	} catch (exception* exceptionPointer) {
		PrintData("发生异常， 异常为: ", exceptionPointer->what());		
	}	
}

void testHeap() {
	// testMakeHeap();
	testHeapSort();
}