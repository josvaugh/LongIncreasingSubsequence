/*
	Joseph Vaughn Extra Credit Dynamic Programming
*/
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_ELE 15

int main(){
	int Seq[MAX_ELE];
	int array[MAX_ELE];
	int subSeq[MAX_ELE];
	int currentSize = 0;
	int maxLen = 0;
	int max;
	int index = 0;
	int inc = 0;
	int num;
	
	ifstream myFile;
	//Open file here
	myFile.open("incseq.txt");
	bool keepOnGoing = true;

	while (myFile >> num){
		if (keepOnGoing){
			currentSize = num;

			if (currentSize > MAX_ELE){
				cout << "Try again, this time with fewer than 15 elements";
			}
			keepOnGoing = false;
		}
		else{
			Seq[inc] = num;
			inc++;
		}

	}
	myFile.close();
	//Close file here

	cout << "Input Sequence from file: ";

	//This is the output from the file, used for debugging purposes
	for (int i = 0; i < currentSize; i++){
		cout << Seq[i];
		cout << " ";
		
	}
	cout << "\n";

	//Find the LIS
	for (int i = 1; i < currentSize; i++){
		for (int j = i; j > -1; j--){
			max = Seq[i];
	
			if (Seq[j] < max){
				//Check to see if the length is higher than the others
				if (array[j] > maxLen)
				{
					maxLen = array[j];
				}
			}

			//hit the end; add sequence to the array
			if (j == 0){
				array[i] = maxLen + 1;
				maxLen = 0;
			}
		}

	}
	//Now find the Max Length
	for (int n = currentSize - 1; n >= 0; n--){
		max = array[n];

		if (maxLen == 0){
			maxLen = max;
			index = n;
			currentSize = maxLen;
		}
		else{
			if (max > maxLen){
				maxLen = max;
				index = n;
				currentSize = maxLen;
			}
		}
	}

	cout << "\nLength of the LIS is: " << maxLen;
	cout << "\n";
	//Now insert the max input into the subsequence 
	subSeq[array[index] - 1] = Seq[index];
	inc = 1;

	//Now find the sequence
	for (int i = index; i >= 0; i--){
		maxLen = array[i];

		if (maxLen == array[index] - inc)
		{
			maxLen = i;
			subSeq[array[maxLen] - 1] = Seq[maxLen];
			inc++;
		}
	}

	cout << "\nLongest Subsequence is: ";

	//Lastly, print the output of the subsequence
	for (int j = 0; j < currentSize; j++){
		cout << subSeq[j];
		cout << " ";
	}
	cout << "\n";

	cin.get(); //pause
	return 0;

}