#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int **macierz1;
int **macierz2;
int **macierz3;
int m,n;
char operacja;
	
int main(){
	srand(time(NULL));
	cout<<"Wymiary macierzy: ";
	cout << "Ilosc kolumn:" << endl;
	cin >> m;
	cout << "Ilosc wierszy: " << endl;
	cin >> n;
	
	//wype³nianie macierzy nr 1
	macierz1 = new int*[m];
	for(int i = 0;i < m; i++)
		macierz1[i]=new int[m];
		
	//wype³nienie zerami macierzy, która powstanie po obliczeniach
	macierz3 = new int*[m];
	for(int i = 0;i < m; i++)
		macierz3[i] = new int[m];
	for(int i = 0; i < m; i++){
		for(int j = 0;j < n; j++){
			macierz3[i][j] = 0;
		}
	}
	
	//wype³nienie losowymi liczbami macierzy nr 1 z przedzia³u 0-10
	for(int i=0; i<m; i++){
		for(int j=0;j<n;j++){
			macierz1[i][j] = rand()%10;
		}
	}
	
	//wypisanie na ekranie pierwszej macierzy
	cout << "Macierz nr 1" << endl;
	for(int i = 0; i< m; i++){
		for(int j = 0;j < n; j++)
			cout << macierz1[i][j] << " ";
		cout << endl;
	}
	
	//stworzenie drugiej macierzy
	macierz2 = new int*[m];
	for(int i = 0;i < m; i++)
		macierz2[i] = new int[m];
		
	for(int i = 0; i < m; i++){
		for(int j = 0;j < n; j++){
			macierz2[i][j] = rand()%10;
		}
	}
	
	//wypisanie macierzy nr 2
		cout << "Macierz nr 2" << endl;
	for(int i = 0;i < m; i++){
		for(int j = 0;j < n; j++)
			cout << macierz2[i][j] << " ";
		cout<<endl;
	}
	
	//decyzja o dzia³aniu na macierzy
	cout << "Dodawanie "+", Odejmowanie "-", Mno¿enia "*"" << endl;
	cin >> operacja;
	if(operacja == '+'){
		for(int i=0; i<m; i++){
			for(int j=0;j<n;j++){
			macierz3[i][j] = macierz1[i][j] + macierz2[i][j];
			}
		}
	
	//wypisanie nowej macierzy po dodaniu	
	cout << "Wykonana operacja dodawania na 2 macierzach:" << endl;
	for(int i=0;i < m ;i++){
		for(int j=0;j < n; j++)
			cout << macierz3[i][j] << " ";
		cout << endl;
	}	
}
	else if(dzialanie=='-'){
		for(int i=0; i<m; i++){
			for(int j=0;j<n;j++){
			tab4[i][j]=tab2[i][j]-tab3[i][j];
			}
		}
		cout<<"Po odjeciu"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<tab4[i][j]<<" ";
		cout<<endl;
	
	}
}
else if(dzialanie=='*'){
		int k;
		cout<<"Podaj k"<<endl;
		cin>>k;
		for(int i=0; i<m; i++){
			for(int j=0;j<n;j++){
			tab4[i][j]=tab2[i][j]*k;
			}
		}
		cout<<"Po mnozeniu"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<tab4[i][j]<<" ";
		cout<<endl;
	
	}
}
	return 0;
}

