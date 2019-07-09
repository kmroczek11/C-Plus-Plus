#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

int main(){	
	string t[26]={
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
	"BCDEFGHIJKLMNOPQRSTUVWXYZA",
	"CDEFGHIJKLMNOPQRSTUVWXYZAB",
	"DEFGHIJKLMNOPQRSTUVWXYZABC",
	"EFGHIJKLMNOPQRSTUVWXYZABCD",
	"FGHIJKLMNOPQRSTUVWXYZABCDE",
	"GHIJKLMNOPQRSTUVWXYZABCDEF",
	"HIJKLMNOPQRSTUVWXYZABCDEFG",
	"IJKLMNOPQRSTUVWXYZABCDEFGH",
	"JKLMNOPQRSTUVWXYZABCDEFGHI",
	"KLMNOPQRSTUVWXYZABCDEFGHIJ",
	"LMNOPQRSTUVWXYZABCDEFGHIJK",
	"MNOPQRSTUVWXYZABCDEFGHIJKL",
	"NOPQRSTUVWXYZABCDEFGHIJKLM",
	"OPQRSTUVWXYZABCDEFGHIJKLMN",
	"PQRSTUVWXYZABCDEFGHIJKLMNO",
	"QRSTUVWXYZABCDEFGHIJKLMNOP",
	"RSTUVWXYZABCDEFGHIJKLMNOPQ",
	"STUVWXYZABCDEFGHIJKLMNOPQR",
	"TUVWXYZABCDEFGHIJKLMNOPQRS",
	"UVWXYZABCDEFGHIJKLMNOPQRST",
	"VWXYZABCDEFGHIJKLMNOPQRSTU",
	"WXYZABCDEFGHIJKLMNOPQRSTUV",
	"XYZABCDEFGHIJKLMNOPQRSTUVW",
	"YZABCDEFGHIJKLMNOPQRSTUVWX",
	"ZABCDEFGHIJKLMNOPQRSTUVWXY"
	};
	
	int wyst[26];	
	string wyraz1;
	string klucz1 = "LUBIMYCZYTAC";
	int i_znak = 0;	
	int powtorzenia = 1;
	int licznik = 0;
	int pos_klucz;
	int pos_wyraz;
	ifstream plik1;
	ifstream plik2;	
	plik1.open("dokad.txt");
	
	if(plik1.good()){ 				 	
			getline(plik1, wyraz1); 	 
			 plik1.close();
		 }
	else{
		cout << "Blad otwarcia pliku";
	}		 
	for(int i = 0; i < wyraz1.length(); i++){
	 	if(wyraz1[i] >= 'A' && wyraz1[i] <= 'Z'){
	 		pos_klucz = t[0].find(klucz1[i_znak % klucz1.length()]);	 				
	 		pos_wyraz = t[0].find(wyraz1[i]);	
	 		wyraz1[i] = t[pos_klucz][pos_wyraz];						
	 		i_znak++;
			licznik++;			
			if(licznik == klucz1.length()){
				licznik = 0;
				powtorzenia++;
			}
	 	}
	}
		
	i_znak = 0;
	string tekst2;
	string klucz2;

	plik2.open("szyfr.txt");
	if(plik2.good()){ 				 	
			getline(plik2, tekst2);
			getline(plik2, klucz2);
			plik2.close();
	}
	else{
		cout << "Blad otwarcia pliku"<<endl;
	}	
	string kopia = tekst2;	
	for (int i = 0; i < tekst2.length(); i++){
	 	if(tekst2[i] >= 'A' && tekst2[i] <= 'Z'){
	 		pos_klucz = t[0].find(klucz2[i_znak % klucz2.length()]);	 				
	 		pos_wyraz = t[pos_klucz].find(tekst2[i]);						
	 		tekst2[i] = t[0][pos_wyraz];					 				
	 		i_znak++;		
					
	 	}				 	 			
	}	
	for(int i = 0; i < tekst2.length();i++){
		wyst[i] = 0;
	}
	for(int i = 0; i < tekst2.length();i++){
		wyst[int(kopia[i]) - 65]++;
	}	
	float ko = 0;
	string wystapienia;
	float suma = 0;	
	for(int i = 0; i < 26;i++){
		wystapienia += char(i + 65);		
		wystapienia += " - ";
		string output;
		stringstream ss;
		ss << wyst[i];
		output = ss.str();
		wystapienia += output;
		wystapienia += "\n";	
		ko += wyst[i] * (wyst[i] - 1);
		suma = suma + wyst[i];
	}
	ko = ko / (suma * (suma - 1));
	float d = 0.0285 / (ko - 0.0385);
	float przyblizone = roundf(d * 100) / 100;
	
	ofstream print;
	print.open("Vigenere_wyniki.txt");
	if(print.good()){
		print << "77.1" << endl;
		print << wyraz1 << endl;
		print << powtorzenia << endl;
		print << "77.2" << endl;
		print << tekst2 << endl;
		print << "77.3" << endl;
		print << wystapienia << endl;
		print << przyblizone << endl;
		print << klucz2.length() << endl;
	}
	else{
		cout << "Blad otwarcia pliku";
	}	
	system("PAUSE");
	return 0;
}
