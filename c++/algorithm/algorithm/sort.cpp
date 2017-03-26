#include "sort.h"

void BasicSort::_quickSort(int * originalData, int startIndex, int endIndex, CompareFunc func)
{
	if (startIndex >= endIndex) {
		return;
	}

	int pivot = originalData[(startIndex + endIndex) / 2];

	int tmpStartIndex = startIndex;
	int tmpEndIndex = endIndex;
	int middleIndex = startIndex;

	while (tmpStartIndex < tmpEndIndex) {
		while (func(originalData[tmpStartIndex], pivot) != 1) {
			++tmpStartIndex;
		}
		while (func(originalData[tmpEndIndex], pivot) == 1) {
			--tmpEndIndex;
		}
		if (tmpStartIndex < tmpEndIndex) {
			int tmpValue = originalData[tmpEndIndex];
			originalData[tmpEndIndex] = originalData[tmpStartIndex];
			originalData[tmpStartIndex] = tmpValue;
		}
	}
	middleIndex = tmpStartIndex;
	_quickSort(originalData, startIndex, middleIndex - 1, func);
	_quickSort(originalData, middleIndex + 1, endIndex, func);
}

int isBigger(int value1, int value2)
{
	if (value1 >= value2) return 1;
	else return -1;
}
