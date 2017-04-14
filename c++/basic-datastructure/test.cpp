#include "test.h"
#include "sort.h"
#include <exception>
using std::exception;

void testSort()
{
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
