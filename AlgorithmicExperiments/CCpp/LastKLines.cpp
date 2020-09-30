#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printLast5Lines(const char* filename)
{
	const int K = 5;
	
	ifstream file (filename);
	string L[K];
	int size = 0;

	/*using a circular array which replaces oldest item when
	 * new one is read as opposed to shifting array
	 * which is computationally expensive*/

	while (file.peek() != EOF) {
		getline(file, L[size % K]);
		size++;
	}
	int start = size > K ? (size % K) : 0;
	int count = min(K, size);

	for (int i = 0; i < count; i++) {
		cout << L[(start + i) % K] << endl;
	}
}

//TODO: A dynamic version that takes in a file and number of lines from the bottom to print out
//void printLastKLines(string filename, int numLines) {
//	ifstream file(filename);
//	string L[numLines];
//
//
//}
int main() {
	/*cout << "Hi, this tool reads out the last 5 lines of an input file using c++. \n" << endl;
	cout << "Enter the full path to the file you want to use (ex. C:\filename.txt \n" << endl;
	string userFile;

	cin >> userFile;
	cout << "How many lines do you want to print? \n" << endl;
	string kLines;
	cin >> kLines;
	int numLines = stoi(kLines);
	printLastKLines(userFile, numLines);*/


	const char *filename = "C:\\Users\\alfre\\source\\repos\\GitSandbox\\AlgorithmicExperiments\\CCpp\\testfile.txt";
	
	printLast5Lines(filename);
}





