#include<iostream>
#include <conio.h>

using namespace std;
 
int main()
{
	string text;
	string szyfr;
	string alfabet = "abcdefghijklmnouprstuwyz";
	int txi;
	int prz;
	
	cout << "Podaj tekst: " << endl;
	cin >> text;
	
	cout << "Podaj przesuniecie: " << endl;
	cin >> prz;
		
	for (int i = 0; i < text.length(); i++){
		for (int j = 0; j < alfabet.length(); j++){
			if (text[i] == alfabet[j]){
				txi = j;
				break;
			}
		}
		text[i] = alfabet[(txi + prz)% 24];
	}
	
	cout << text << endl;

	getch();
	system("pause");
	return 0;
}
