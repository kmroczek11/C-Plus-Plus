#include <iostream>

using namespace std;

struct Element{
	int wartosc;
	Element *lewy;
	Element *prawy;
	Element *gora;
}*root = NULL;


int dodajLisc(Element *korzen,int wartosc){
	if (korzen == NULL){
		cout << "tak";
		korzen->wartosc = wartosc;
		korzen->lewy = NULL;
		korzen->prawy = NULL;
		korzen->gora = NULL;
	}
}

int main(){
	cout << root->wartosc;
	dodajLisc(root,4);
}
