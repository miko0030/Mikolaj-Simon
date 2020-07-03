#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <conio.h>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

vector<int> answers;
int mxWeight, mxValue;
const bool print = 1;

struct Przedmiot {
	int weight;
	int value;
	int id;
};

bool isNumber(string input) {

	for (int i = 0; i < input.length(); i++) {
		if (!((input[i] >= 48 && input[i] <= 57)))
			return false;
	}

	return true;
}

int strToInt(string tmp) {
	stringstream stream(tmp);
	int my_int;
	stream >> my_int;
	return my_int;
}

void loadCMD(int &n, int &b, Przedmiot* &plecak)
{
	cout << "Wielkosc plecaka: ";
	cin >> b;
	cout << "Liczba elementow: ";
	cin >> n;
	plecak = new Przedmiot[n];
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << endl;
		cout << "Waga: ";
		cin >> plecak[i].weight;
		cout << "Wartosc: ";
		cin >> plecak[i].value;
		cout << endl;
	}
};

void generatePlecak(int &n, int &b, struct Przedmiot* plecak) {
	cout << "Wielkosc plecaka: ";
	cin >> b;
	cout << "Liczba elementow: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		plecak[i].weight = rand() % 10 + 1;
		plecak[i].value = rand() % 10 + 1;
	}
}

void printPlecak(Przedmiot* plecak, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Index: " << i + 1 << "\tWeight:" << plecak[i].weight << "\tValue: " << plecak[i].value << endl;
	}
}

int** generateMatrix(int b, int n) {
	int** arr = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = new int[b + 1];
		for (int j = 0; j < b + 1; j++) {
			arr[i][j] = -1;
		}
	}
	return arr;
}

void printMatrix(int** arr, int b, int n) {
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < b + 1; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

//dynamiczny
int APD(Przedmiot* plecak, int** matrix, int b, int n) {
	for (int i = 0; i < b + 1; i++) {
		matrix[0][i] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < b + 1; j++) {
			if (plecak[i - 1].weight > j) {
				matrix[i][j] = matrix[i - 1][j];
			}
			else {
				matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - plecak[i - 1].weight] + plecak[i - 1].value);
			}
		}
	}
	return matrix[n][b];
}

void przedmiotyAPD(Przedmiot* arr, int** matrix, int b, int n) {
	int currWeight = 0;
	bool flag = false;
	int i = n;
	int j = b;
	while (i > 0) {
		if (matrix[i][j] != matrix[i - 1][j]) {
			answers.push_back(i);
			currWeight += arr[i - 1].weight;
			j -= arr[i - 1].weight;
		}
		i--;
	}
	mxWeight = currWeight;
}

void sortP(Przedmiot* plecak, int n)
{
	int i, j;
	float key;
	Przedmiot key_item;
	for (i = 1; i < n; i++)
	{
		key_item = plecak[i];
		key = float(plecak[i].value) / float(plecak[i].weight);
		j = i - 1;

		while (j >= 0 && float(plecak[j].value) / float(plecak[j].weight) < key)
		{
			plecak[j + 1] = plecak[j];
			j = j - 1;
		}
		plecak[j + 1] = key_item;
	}
}

//siłowy
int AW(Przedmiot* plecak, int n, int b) {
	int bin;
	//int maxValue = 0;
	int currValue = 0, currWeight = 0;
	//int mxWeight = 0;
	vector<int> array;

	for (int i = 1; i < pow(2, n); i++) {
		currValue = 0;
		currWeight = 0;
		int tmp = i;
		for (int j = 1; j <= n; j++) {
			if (tmp % 2 == 1) {
				currValue += plecak[j - 1].value;
				currWeight += plecak[j - 1].weight;
				array.push_back(j);
			}
			tmp /= 2;
			if (tmp == 0) {
				break;
			}
		}

		if (currWeight <= b && currValue > mxValue) {
			mxValue = currValue;
			mxWeight = currWeight;
			answers.clear();
			for (int i = 0; i < array.size(); i++) {
				answers.push_back(array[i]);
			}
		}
		array.clear();
	}

	return mxValue;
}

void printVec(vector<int> tab) {
	for (int i = tab.size() - 1; i >= 0; i--) {
		cout << tab[i] << " ";
	}
}

bool inputGood(int x, int a, int b) {
	if (x >= a && x <= b)
		return true;
	return false;
}

bool menu(int& choice, int& alg, int& n, int& b) {

	cout << "1. Generuj plecak" << endl;
	cout << "2. Wczytaj plecak z klawiatury" << endl;
	choice = _getch() - 48;
	if (!inputGood(choice, 1, 2))
		return 0;
	system("cls");

	cout << "Typ algorytm" << endl;
	cout << "1. Dynamiczny" << endl;
	cout << "2. Silowy" << endl;
	alg = _getch() - 48;
	if (!inputGood(alg, 1, 2))
		return 0;
	system("cls");

	return 1;
}

double head() {
	clock_t start, stop;
	Przedmiot* plecak;

	int** matrix;
	int alg = 2;
	int choice = 2;
	int n = 0, b = 0;
	plecak = new Przedmiot[n];


	if (!menu(choice, alg, n, b)) {
		cout << "Bledne wprowadzenie" << endl;
		return -1;
	}

	if (choice == 1) {
		generatePlecak(n, b, plecak);     
	}
	else if (choice == 2) {
		loadCMD(n, b, plecak);
	}

	if (print) {
		printPlecak(plecak, n);
		cout << endl;
	}

	if (alg == 1) {
		cout << "Algorytm dynamiczny" << endl;
		matrix = generateMatrix(b, n);
		mxValue = APD(plecak, matrix, b, n);
		przedmiotyAPD(plecak, matrix, b, n);
	}
	else if (alg == 2) {
		cout << "Algorytm silowy" << endl;
		AW(plecak, n, b);
	}

	cout << "Elementy: ";
	printVec(answers);
	cout << endl << "Maksymalna wartosc: " << mxValue << endl;
	cout << "Waga plecaka: " << mxWeight << endl;

	return 0;
}

int main()
{
	srand(time(NULL));
	while (true) {
		mxValue = 0;
		mxWeight = 0;
		answers.clear();
		head();
		_getch();
		system("cls");
	}
}
