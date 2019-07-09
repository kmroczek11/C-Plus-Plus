#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class matrixClass{
	private:
		int m;
		int n;
		int** k; //wskaznik podwojny na element, pod tym tablica dwuwymiarowa
//		string name; //nazwa tablicy
	public:
		matrixClass();
		setValues(int M, int N);
		zeroMatrix(int M);
		int getM();
		int getN();
		int** getArray();
//		setMatrix();
//		void getMatrix();
		friend matrixClass operator +(matrixClass m1, matrixClass m2);
		friend matrixClass operator *(matrixClass macierz, int k);
		friend matrixClass operator *(matrixClass m1, matrixClass m2);
		friend ostream& operator <<(ostream &wyj, matrixClass &X);
		friend istream& operator >>(istream &wyj, matrixClass &X);
};	

matrixClass operator +(matrixClass m1, matrixClass m2){
	if (m1.getM() == m2.getM() && m1.getN() == m2.getN()){
			matrixClass macierz3;
			int m = m1.getM();
			int n = m1.getN();
			macierz3.setValues(m, n);
			int** k1 = m1.getArray();
			int** k2 = m2.getArray();
			macierz3.zeroMatrix(m);
			int** k3 = macierz3.getArray();
		for(int i=0; i<m; i++){
			for(int j=0;j<n;j++){
			k3[i][j] = k1[i][j] + k2[i][j];
			}
		}
		return macierz3;
	}else{
		cout << "Zle wymiary macierzy.";
	}
}

matrixClass operator *(matrixClass macierz, int k){
			matrixClass macierz4;
			int m = macierz.getM();
			int n = macierz.getN();
			macierz4.setValues(m, n);
			macierz4.zeroMatrix(m);
			int** k1 = macierz.getArray();
			int** k2 = macierz4.getArray();
		for(int i=0; i<m; i++){
			for(int j=0;j<n;j++){
			k2[i][j]=k1[i][j]*k;
			}
		}
		return macierz4;
}

matrixClass operator *(matrixClass m1, matrixClass m2){
	if (m1.getN() == m2.getM()){
	//		cout << "Wykonuje sie.";
			matrixClass macierz5;
			int m = m1.getM();
			int n = m2.getN();
			int l = m1.getM();
			macierz5.setValues(m, n);
			int** k1 = m1.getArray();
			int** k2 = m2.getArray();
			macierz5.zeroMatrix(m1.getM());
			int** k3 = macierz5.getArray();
			
		  	for(int i = 0; i < m; i++){
		  		for(int j = 0; j < l; j++){
		  			int suma = 0;
		  			for(int k = 0; k < n; k++){
		  			suma += k1[i][k] * k2[k][j];
					  }
					  k3[i][j] = suma;
				  }
			  }		
			return macierz5;
	}else{
		cout << "Zle wymiary macierzy.";
	}
}

int main()
{
    matrixClass macierz1;
    int m1;
    int n1;
    cout<<"Podaj wymiary pierwszej macierzy" << endl;
	cin >> m1;
	cin >> n1;
	macierz1.zeroMatrix(m1);
 	macierz1.setValues(m1 ,n1);
 	cin >> macierz1;
 	cout << "Wypisana macierz:" << endl;
	cout << macierz1;
 		
 	matrixClass macierz2;
    int m2;
    int n2;
    cout<<"Podaj wymiary drugiej macierzy" << endl;
	cin >> m2;
	cin >> n2;
	macierz2.zeroMatrix(m2);
 	macierz2.setValues(m2 ,n2);
 	cin >> macierz2;
 	cout << "Wypisana macierz:" << endl;
 	cout << macierz2;
 	
 	char wybor;
 	cout << "Wybierz dzialanie(+ - dodawanie macierzy, k - mnozenie przez skalar, * - mnozenie macierzy):" << endl;
 	cin >> wybor;
 	switch (wybor){
 		case '+':
 			{
 			matrixClass macierz3;
 			cout << "Dodane macierze:" << endl;
 			macierz3 = macierz1 + macierz2;
 			cout << macierz3;
 			break;
 			}
 		case 'k':
 			{
 			cout << "Podaj skalar:" << endl;
 			int skalar;
 			cin >> skalar;
 			cout << "Ktora macierz chcesz pomnozyc przez skalar?(m1 - macierz 1, m2 - macierz 2)" << endl;
 			string numerMacierzy;
 			cin >> numerMacierzy;
 			if (numerMacierzy == "m1"){
 				matrixClass macierz3;
 				cout << "Macierz pomnozona przez skalar:" << endl;
 				macierz3 = macierz1 * skalar;
 				cout << macierz3;
			 }else if(numerMacierzy == "m2"){
			 	matrixClass macierz3;
			 	cout << "Macierz pomnozona przez skalar:" << endl;
			 	macierz3 = macierz1 * skalar;
 				cout << macierz3;
			 }else{
			 	cout << "Nie ma takiej macierzy.";
			 }
			}
 			break;
 		case '*':
 			{
 			matrixClass macierz3;
 			cout << "Pomnozone macierze:" << endl;
 			macierz3 = macierz1 * macierz2;
 			cout << macierz3;
 			break;
 			}
 		default:
    		cout << "Nie ma takiej operacji.";
    		break;
	 }
 	
    system("PAUSE");
    return 0;
}

matrixClass::matrixClass(){
}

matrixClass::setValues(int M, int N){
	m = M;
	n = N;
}

int matrixClass::getM(){
	return m;
}

int matrixClass::getN(){
	return n;
}

int** matrixClass::getArray(){
	return k;
}

matrixClass::zeroMatrix(int M){
	k = new int*[M];
	for(int i = 0;i < M; i++)
		k[i]=new int[M];
}

istream& operator >>(istream &wej, matrixClass &X){	
	int liczba;	
	int m = X.getM();
	int n = X.getN();
	int** k = X.getArray();
	
	for(int i=0; i<m; i++){
		for(int j=0;j<n;j++){
			cout << "Podaj liczbe:";
			cin >> liczba;
			k[i][j] = liczba;
		}
	}
}

ostream& operator <<(ostream &wyj, matrixClass &X){	
	int m = X.getM();
	int n = X.getN();
	for(int i=0; i<m; i++){
		for(int j=0;j<n;j++){
			wyj << X.k[i][j] << " ";
		}
		wyj << endl;
	}
	return wyj;
}
