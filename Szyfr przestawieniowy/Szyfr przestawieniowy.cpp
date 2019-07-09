#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
 
using namespace std;

void zakoduj(int szyfr [], int rozmiar, string odPlikTxt, string doPlikTxt){
	string linia;
    fstream plik;
	plik.open(odPlikTxt.c_str(), ios::in);
	ofstream zapis(doPlikTxt.c_str());
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            getline(plik, linia);
            int index = 0;
            for (int i = 0; i < linia.length(); i++){
            		if (i % rozmiar == 0 && i != 0){ 
						char tmp = linia[i];
            			linia[i] = linia[szyfr[i % rozmiar] - 1];
						linia[szyfr[i % rozmiar] - 1] = tmp;
						index = 1;
						}else{
            				char tmp = linia[i];
            				linia[i] = linia[szyfr[index] - 1];
							linia[szyfr[index] - 1] = tmp;
							index++;
							}
			}
			zapis << linia << endl;
			cout << linia << endl;
        }
        plik.close();
        zapis.close();
    }
}

void dekoduj(int szyfr [], int rozmiar, string odPlikTxt, string doPlikTxt){
	string linia;
    fstream plik;
	plik.open(odPlikTxt.c_str(), ios::in);
	ofstream zapis(doPlikTxt.c_str());
    if(plik.good() == true)
    {
        while(!plik.eof())
        {
            getline(plik, linia);
            int index = 0;
            for (int i = linia.length() - 1; i >= 0; i--){
				char tmp = linia[i];
            	linia[i] = linia[szyfr[i % rozmiar] - 1];
				linia[szyfr[i % rozmiar] - 1] = tmp;
			}
			zapis << linia << endl;
			cout << linia << endl;
        }
        plik.close();
        zapis.close();
    }
}

int main()
{
	int klucz1 [] = {13 ,2 ,10 ,50 ,1 ,28 ,37 ,32 ,30 ,46 ,19 ,47 ,33 ,41 ,24 ,34 ,27 ,42 ,49 ,18 ,9 ,48 ,23 ,35 ,31 ,8 ,7 ,12 ,6 ,5 ,3 ,22 ,43 ,36 ,11 ,40 ,26 ,4 ,44 ,17 ,39 ,38 ,15 ,14 ,25 ,16 ,29 ,20 ,21 ,45};
	int size1 = sizeof(klucz1)/sizeof(*klucz1);
	zakoduj(klucz1, size1, "szyfr1.txt", "wyniki_szyfr1.txt");
	cout << endl;
	int klucz2 [] = {13 ,10 ,2 ,3 ,1 ,12 ,8 ,4 ,5 ,7 ,9 ,6 ,15 ,14 ,11};
	int size2 = sizeof(klucz2)/sizeof(*klucz2);
	zakoduj(klucz2, size2, "szyfr2.txt", "wyniki_szyfr2.txt");
	cout << endl;
	int klucz3 [] = {6 ,2, 4, 1, 5, 3};
	int size3 = sizeof(klucz3)/sizeof(*klucz3);
	dekoduj(klucz3, size3, "szyfr3.txt", "wyniki_szyfr3.txt");
    system("PAUSE");
    return(0);
}
