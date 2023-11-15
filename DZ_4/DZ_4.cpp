#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <cstring>
#include <Windows.h>

using namespace std;

void Fi() {
	ofstream fout("cppstudio.txt");
	cout << "Введите 10 чисел.\n";
	float chisl;
	for (int i = 0; i <= 9; i++) {
		cin >> chisl;
		if (chisl = float(chisl)) {fout << chisl << "\n";}
		else if (chisl == 0) {fout << chisl << "\n";}
		else { cout << "Ошибка."; break; }
	}
	fout.close();
	ifstream fin("cppstudio.txt");
	float otvet = 0;
	for (int i = 0; i <= 9; i++) {
		fin >> chisl;
		otvet += chisl;
	}
	fin.close();
	if (otvet != 0) { cout << otvet; }
	else {cout << "Ошибка."; }
}


int DopZCh(float x) {
	if (x > 0) { return 1; }
	else if (x < 0) { return -1; }
	else if (x == 0) { return 0; }
}
void ZCh() {
	float x;
	cout << "Введите число.\n";
	cin >> x;
	cout << DopZCh(x);
}


void Geo1() {
	float a, b;
	cout << "Введите две стороны прямоугольника.\n";
	cin >> a;
	cin >> b;
	cout << "Площадь прямоугольника:  " << a * b;
}
void Geo2() {
	float a, b;
	cout << "Введите сторону треугольника и высоту, проведённую у этой стороне.\n";
	cin >> a;
	cin >> b;
	cout << "Площадь треугольника:  " << (a * b)/2;
}
void Geo3() {
	float r;
	cout << "Введите радиус круга.\n";
	cin >> r;
	cout << "Площадь прямоугольника:  " << r*r * 3.1415;
}
void Geo() {
	short naz;
	cout << "Площадь какой фигуры нужно найти?\n1.Прямоугольник.\n2.Треугольник.\n3.Круг.\n";
	cin >> naz;
	switch (naz) {
	case 1: Geo1(); break;
	case 2: Geo2(); break;
	case 3: Geo3(); break;
	default: cout << "Error."; break;
	}
}


void BS() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++) {
		SetConsoleTextAttribute(h, 0x00);
		for (int pol = 0; pol < 32; pol++) {
			cout << '_';
		}
		cout << endl;
	} 
		for (int i = 0; i < 4; i++) {
			SetConsoleTextAttribute(h, 0x66);
			for (int pol = 0; pol < 32; pol++) {
				cout << '_';
			}
			cout << endl;
		}
		for (int i = 0; i < 4; i++) {
			SetConsoleTextAttribute(h, 0xFF);
			for (int pol = 0; pol < 32; pol++) {
				cout << '_';
			}
			cout << endl;
		}
		SetConsoleTextAttribute(h, 0x00);
	}


void Sin() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255)), PenSin = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 0, 85, NULL);
	LineTo(hDC, 200, 85);
	MoveToEx(hDC, 100, 0, NULL);
	LineTo(hDC, 100, 170);
	for (float x = -8.0f; x <= 8.0f; x += 0.01f)
	{
		SelectObject(hDC, PenSin);
		MoveToEx(hDC, 10 * x + 100, -10 * sin(x) + 85, NULL);
		LineTo(hDC, 10 * x + 100, -10 * sin(x) + 85);
	}
	ReleaseDC(hWnd, hDC);
	//system("pause");
}


int Rim(char a) {
	char s = a;
	switch (s) {
	case 'M': return 1000;
	case 'D': return 500;
	case 'C': return 100;
	case 'L': return 50;
	case 'X': return 10;
	case 'V': return 5;
	case 'I': return 1;
	default: return 0;
	}
}
void AR() {
	string strok;
	bool prov = true;
	int num = 0, arabCh=0;
	cout << "Введите римскую запись числа:  ";
	cin >> strok;
	while (num < strok.size()) {
		if (Rim(strok[num]) == 0) { prov = false; }
		if (Rim(strok[num + 1]) <= Rim(strok[num])) { arabCh += Rim(strok[num]); }
		if (Rim(strok[num + 1]) > Rim(strok[num])) { arabCh -= Rim(strok[num]); }
		num++;
	}
	if (prov) { cout << arabCh << endl; } else{ cout << "Ошибка.\n"; }
}


void GSCh() {
	int S[100000], m1 = 37, i1 = 3, c1 = 64, m2 = 25173, i2 = 13849, c2 = 65537;
	for (int i = 0; i < 10; i++) {
		S[i + 1] = (m1 * S[i] + i1) % c1;
		cout << S[i + 1] << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		S[i2 + 1] = (m2 * S[i2 + i2]) % c2;
		cout << S[i2 + 1]<< " ";
	}
}


void UmM() {
	float A[3][4] = { {5,2,0,10},{3,5,2,5},{20,0,0,0} }, B[4][2] = { {1.2,0.5},{2.8,0.4},{5,1},{2,1.5} };
	float C[3][2] = { {0,0},{0,0},{0,0} };
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 2; col++) {
			for (int inner = 0; inner < 4; inner++) {
				C[row][col] += A[row][inner] * B[inner][col];
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (C[i][0] == max(C[0][0], C[1][0], C[2][0])) { cout << "Больше всего выручил " << i+1 << " продавец" << endl; }
		else if (C[i][0] == min( C[1][0], C[2][0], C[0][0])) { cout << "Меньше всего выручил " << i+1 << " продавец" << endl; }
	}
	cout  << endl;
	for (int i = 0; i < 3; i++) {
		if (C[i][1] == max(C[0][1], C[1][1], C[2][1])) { cout << "Больше комиссионных получил " << i + 1 << " продавец" << endl; }
		else if (C[i][1] == min(C[1][1], C[2][1], C[0][1])) { cout << "Меньше комиссионных получил " << i + 1 << " продавец" << endl; }
	}
	cout << endl;
	cout << "Общая сумма выручки " << C[0][0] + C[1][0] + C[2][0];
	cout << endl << endl;
	cout << "Общая сумма комиссионных " << C[0][1] + C[1][1] + C[2][1];
	cout << endl  << endl;
	cout << "Всего денег " << C[0][1] + C[1][1] + C[2][1]+ C[0][0] + C[1][0] + C[2][0];
}


char Symb(int i) {
	char a[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E','F' };
	return a[i];
}
void Res(string a) {
	for (int i = 0; i < size(a); i++) {
		cout << a[size(a) - i-1];
	}
}
void SiSch() {
	int ss, nss, chisl, osnov = 0, step=0;
	string res;
	cout << "Введите число:     ";
	cin >> chisl;
	cout << "Введите основание числа:    ";
	cin >> ss;
	
	while (chisl>0) {
		osnov += (chisl % 10) * pow(2, step);
		step += 1;
		chisl /= 10;
	}
	cout << "Введите новое основание:    ";
	cin >> nss;
	
	while (osnov > 0) {
		res += Symb(osnov % nss);
		osnov /= nss;
	}
	Res(res);
}


int main() {
	setlocale(LC_ALL, "Russian");
	//Fi();
	//ZCh();
	//Geo();
	//BS();
	//Sin();
	AR();
	//GSCh();
	//UmM();
	//SiSch();
}