#include <iostream>
#include <tchar.h>
#include <vector>
#define _UNICODE
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	const int Size = 100;
	_TCHAR Str[Size];
	_TCHAR Buf[Size]=_TEXT("тестовая строка");
	//---------------------------------------------------------------1

	for (int i = 0; i < _tcslen(Buf); i++) {
		if (Buf[i] == ' ') {
			Str[i] = '\t';
		}
		Str[i] = Buf[i];
	}
	wcout << Str<<endl; 

	//---------------------------------------------------------------2

	int LetterCount = 0;
	int DigitCount = 0;
	int OtherCount = 0;
	for (int i = 0; i < _tcslen(Buf); i++) {
		if ((Buf[i] >= 'A' && Buf[i] <= 'Z')|| (Buf[i] >= 'a' && Buf[i] <= 'z')) {
			LetterCount++;
		}
		else if (Buf[i] >= '0' && Buf[i] <= '9') {
			DigitCount++;
		}
		else {
			OtherCount++;
		}
	}
	wcout <<endl<< LetterCount << endl << DigitCount << endl << OtherCount << endl;

	//---------------------------------------------------------------3

	int WordCount = 0;
	for (int i = 0; i < _tcslen(Buf); i++) {
		if (Buf[i] == ' ') {
			WordCount++;
		}
	}
	if (_tcslen(Buf) == 0) {
		wcout << 0;
	}
	else {
		wcout << endl << WordCount + 1;
	}

	//---------------------------------------------------------------4

	int VowelsCount = 0;
	for (int i = 0; i < _tcslen(Buf); i++) {
		if (Buf[i] == 'о'||Buf[i]=='у'|| Buf[i] == 'е' || Buf[i] == 'и'|| Buf[i] == 'э' || Buf[i] == 'а'|| Buf[i] == 'ы' || Buf[i] == 'ё' || Buf[i] == 'ю' || Buf[i] == 'я') {
			VowelsCount++;
		}
	}
	wcout << endl << VowelsCount;

	//---------------------------------------------------------------5

	_TCHAR Str1[Size];
	_TCHAR Str2[Size];
	for (int i = 0, int j = _tcslen(Buf); i < _tcslen(Buf), j>0; i++, j--) {
		Str1[i] = Buf[i];
		Str2[i] = Buf[j];
	}
	if (Str1 == Str2) {
		wcout << "Палиндром";
	}
	else {
		wcout << "Не палиндром";
	}

	//---------------------------------------------------------------6

	vector<_TCHAR> TChar;
	for (int i = 0; i < _tcslen(Buf); i++) {
		TChar[i] = Buf[i];
	}
	_TCHAR IndexDelete;
	cout << "Введите индекс символа, который хотите удалить";
	wcin >> IndexDelete;
	TChar.erase(TChar.begin(),TChar.begin()+IndexDelete);
	for (int i = 0; i < _tcslen(Buf); i++) {
		Buf[i] = TChar[i];
	}
	wcout << Buf << endl;

	//---------------------------------------------------------------7

	vector<_TCHAR> TChar;
	for (int i = 0; i < _tcslen(Buf); i++) {
		TChar[i] = Buf[i];
	}
	_TCHAR CharacterDelete;
	cout << "Введите символ, который хотите удалить";
	wcin >> CharacterDelete;
	for (int i = 0; i < _tcslen(Buf); i++) {
		if (TChar[i] == CharacterDelete) {
			TChar.erase(TChar.begin(), TChar.begin() + i);
		}
	}
	for (int i = 0; i < _tcslen(Buf); i++) {
		Buf[i] = TChar[i];
	}
	wcout << Buf << endl;

	//---------------------------------------------------------------8
	vector<_TCHAR> TChar;
	for (int i = 0; i < _tcslen(Buf); i++) {
		TChar[i] = Buf[i];
	}
	_TCHAR CharacterInsert;
	_TCHAR IndexInsert;
	cout << "Введите символ, который хотите вставить"; 
	wcin >> CharacterInsert;
	cout << "Введите индекс";
	wcin >> IndexInsert;
	TChar.insert(TChar.begin()+IndexInsert, CharacterInsert);
	for (int i = 0; i < _tcslen(Buf); i++) {
		Buf[i] = TChar[i];
	}
	wcout << Buf << endl;


	return 0;
}
