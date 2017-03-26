#include "test.h"
#include "sort.h"

void testSort()
{
	int dataLength = 10;
	int* originalData = new int[10];
	if (!originalData) {
		cout << "·ÖÅäÄÚ´æÊ§°Ü!" << endl;
	}

	for (int i = 0; i < dataLength; ++i) {
		originalData[i] = dataLength - i;
	}

	PrintData("Original Data: ", originalData, dataLength);

	BasicSort baseSortObj = BasicSort();
	baseSortObj._quickSort(originalData, 0, dataLength - 1, isBigger);

	PrintData("QuickSorted Data: ", originalData, dataLength);

	if (originalData) {
		delete[] originalData;
		originalData = NULL;
	}

}
