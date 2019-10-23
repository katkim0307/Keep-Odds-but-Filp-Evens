// kk4036_hw9_q4.cpp THIS CODE DOES NOT RUN ON VISUAL STUDIO
// Implement void oddsKeepEvensFlip (int arr[], int arrSize)
// This function gets an array of integers arr and its local size arrSize.
// When called, it should reorder the elements of arr so that
// 1) All odd #s come before all the even #s
// 2) The odd #s will keep their original relative order
// 3) The even #s will be placed in a reversed order (relative to their original order)
// e.g. arr = [5, 2, 11, 7, 6, 4]
// after calling the function, arr = [5, 11, 7, 4, 6, 2]

#include "pch.h"
#include <iostream>
using namespace std;

//THIS CODE DOES NOT RUN ON VISUAL STUDIO
int main1();	//using predefined int array
int main2();	//asking the user to define an array
int* readArr1(int& outArrSize);	//user knows how many # of values to sort
int* readArr2(int& outArrSize); //user doesn't know the # of values to sort
void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{
	main1();
	return 0;
}

int main1()
{
	int arr[] = { 5, 2, 11, 7, 6, 4 };
	int arrSize = 6;

	cout << "The initial array = { 5, 2, 11, 7, 6, 4 } \n \n";
	cout << "The oddsKeepEvensFlip array = ";
	oddsKeepEvensFlip(arr, arrSize);
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {

	int outputArr[arrSize];
	int oddCount = 0;
	int evenCount = arrSize - 1;

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 != 0) {
			outputArr[oddCount] = arr[i];
			oddCount++;
		}
		else {
			outputArr[evenCount] = arr[i];
			evenCount--;
		}
	}

	for (int i = 0; i < arrSize; i++) {
		arr[i] = outputArr[i];
	}

}

int main2()
{
	int* inputNumArr;
	int numArrSize;

	inputNumArr = readArr1(numArrSize);

	oddsKeepEvensFlip(inputNumArr, numArrSize);
	for (int i = 0; i < numArrSize; i++) {
		cout << inputNumArr[i] << " ";
	}
	cout << endl;
	delete[]inputNumArr;
	inputNumArr = NULL;
	return 0;
}

int* readArr1(int& outArrSize) {

	int arrSize;

	cout << "Please enter the number of integers you wish to sort: \n";
	cin >> arrSize;

	int* numArr;
	numArr = new int[arrSize];

	cout << "Please enter the list of integers separated by a space: \n";
	for (int i = 0; i < arrSize; i++) {
		cin >> numArr[i];
	}
	outArrSize = arrSize;
	return numArr;
}

//If users don't know how many #s they are going to enter:
int* readArr2(int& outArrSize) {
	int* numArr;
	int* newNumArr;
	bool done;
	int numArrSize;
	int numArrPhysicalSize;
	int currNum;

	cout << "Please enter a list of integers separated by a space. \n";
	cout << "End the list by entering -1: \n";

	numArr = new int[1];
	numArrSize = 0;
	numArrPhysicalSize = 1;

	done = false;
	while (done == false) {
		cin >> currNum;
		if (currNum == -1)
			done = true;
		else {
			//when you need to resize the array logical size
			if (numArrSize == numArrPhysicalSize) {
				newNumArr = new int[2 * numArrPhysicalSize];
				//you can copy old #s into the new array
				for (int i = 0; i < numArrSize; i++) {
					newNumArr[i] = numArr[i];
				}
				delete[]numArr;
				numArr = newNumArr;
				numArrPhysicalSize *= 2;
			}
			numArr[numArrSize] = currNum;
			numArrSize++;
			//linesVector.push_back(currNum); works too
		}
	}
	outArrSize = numArrSize;
	return numArr;		//return the base address of the array
}
