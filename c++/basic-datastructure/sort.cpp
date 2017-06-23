#include "sort.h"
#include <algorithm>
using std::swap;

int isBigger(int value1, int value2)
{
	if (value1 >= value2) return 1;
	else return -1;
}

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

void BasicSort::quickSort(int * originalData, int dataLength)
{
	_quickSort(originalData, 0, dataLength - 1, isBigger);
}

void BasicSort::_bubbleSort(int * originalData, int startIndex, int endIndex, CompareFunc compFunc)
{
	bool isSwaped = true;
	for (int curEndIndex = endIndex; curEndIndex > startIndex; --curEndIndex) {
		if (!isSwaped) break;
		isSwaped = false;
		for (int curStartIndex = startIndex; curStartIndex < curEndIndex; ++curStartIndex) {
			if (compFunc(originalData[curStartIndex], originalData[curStartIndex + 1]) == 1) {
				//int tmpValue = originalData[curStartIndex];
				//originalData[curStartIndex] = originalData[curStartIndex + 1];
				//originalData[curStartIndex + 1] = tmpValue;
				swap(originalData[curStartIndex], originalData[curStartIndex + 1]);
				isSwaped = true;
			}
		}
	}
}

void BasicSort::bubbleSort(int * originalData, int dataLength)
{
	_bubbleSort(originalData, 0, dataLength - 1, isBigger);
}


void BasicSort::_mergeSort(int * originalData, int startIndex, int endIndex, CompareFunc func){
	if (endIndex <= startIndex) return;

	int middleIndex = (startIndex + endIndex)/2;

	_mergeSort(orginalData, startIndex, middleIndex);
	_mergeSort(orginalData, middleIndex+1, endIndex);

	int dataLength = endIndex - startIndex + 1;
	int* tmpData = new int [dataLength];

	int tmpIndex = 0;
	int leftIndex = startIndex;
	int rightIndex = middleIndex + 1;
	while (leftIndex <= middleIndex && rightIndex <= endIndex) {

	}
	if (leftIndex <= middleIndex) {

	}
	if (rightIndex <= endIndex) {

	}

	memcpy(originalData + startIndex, tmpData, dataLength * sizeof(int));

	if (NULL != tmpData) {
		delete[] tmpData;
		tmpData = NULL;
	}
}

void BasicSort::mergeSort(int * originalData, int dataLength){

}