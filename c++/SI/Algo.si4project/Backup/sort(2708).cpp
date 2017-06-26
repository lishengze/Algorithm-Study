#include "sort.h"
#include <algorithm>
#include<cstring>
#include "Print.h"
using std::swap;
using std::memcpy;

int isBigger(int value1, int value2)
{
	if (value1 >= value2) return 1;
	else return 0;
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

void BasicSort::_merge(int * originalData, int startIndex, int endIndex, CompareFunc func) {
	int dataLength = endIndex - startIndex + 1;
	int middleIndex = (startIndex + endIndex)/2;
	int* tmpData = new int [dataLength];
	int tmpIndex = 0;
	int leftIndex = startIndex;
	int rightIndex = middleIndex + 1;

	while (leftIndex <= middleIndex && rightIndex <= endIndex) {
		// cout << "leftIndex: " << leftIndex << "	leftData: " << originalData[leftIndex] << "	"
		//      << "rightIndex: " << rightIndex <<"	rightData: "<< originalData[rightIndex] <<endl;		
		if (func(originalData[leftIndex], originalData[rightIndex])) {
			tmpData[tmpIndex++] = originalData[rightIndex++];
		} else {
			tmpData[tmpIndex++] = originalData[leftIndex++];
		}

	}

	if (leftIndex <= middleIndex) {
		memcpy(tmpData + tmpIndex, originalData + leftIndex, (middleIndex-leftIndex + 1) * sizeof(int));
	}
	if (rightIndex <= endIndex) {
		memcpy(tmpData + tmpIndex, originalData + rightIndex, (endIndex - rightIndex + 1) * sizeof(int));
	}

	// PrintData("tmpData: ", tmpData, dataLength);

	memcpy(originalData + startIndex, tmpData, dataLength * sizeof(int));

	if (NULL != tmpData) {
		delete[] tmpData;
		tmpData = NULL;
	}
}

void BasicSort::_mergeSort(int * originalData, int startIndex, int endIndex, CompareFunc func){
	if (endIndex <= startIndex) return;

	int middleIndex = (startIndex + endIndex)/2;

	_mergeSort(originalData, startIndex, middleIndex, func);
	_mergeSort(originalData, middleIndex+1, endIndex, func);

	_merge(originalData, startIndex, endIndex, func);
}

void BasicSort::mergeSort(int * originalData, int dataLength){
	_mergeSort(originalData, 0, dataLength-1, isBigger);
}