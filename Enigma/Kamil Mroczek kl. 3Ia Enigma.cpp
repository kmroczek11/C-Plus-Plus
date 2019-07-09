#include <iostream>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alphabetEncryptionRing;
string cipherEncryptionRing;
char cipherArray[3][32];
bool encoded = false;

string caesarCipher(string alphabet, string text, int key){
	int textIndex;
	for (int i = 0; i < text.length(); i++){
		for (int j = 0; j < alphabet.length(); j++){
			if (alphabet[i] == alphabet[j]){
				textIndex = j;
				break;
			}
		}
		text[i] = alphabet[(textIndex + key) % 26];
	}
	return text;
}

string createEncryptionRing(string text){
	string encryptionRing;
	encryptionRing.append(text, text.length() - 3, 3);
  	encryptionRing.append(text, 0, text.length());
  	encryptionRing.append(text, 0, 3);
  	return encryptionRing;
}

void fillCipherArray(string text, char (&array)[3][32], int rowLength, int startIndex, int moveIndex, int rowIndex){
	for (int i = startIndex; i < rowLength; i++){
		array[rowIndex][i] = text[i - moveIndex];
	}
}

void show(char (&array)[3][32]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 32; j++){
			cout << array[i][j];
		}
	cout << endl;
	}
}

void init(char (&array)[3][32]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 32; j++){
			array[i][j] = '/';
		}
	}
}

int findIndex(string text, char letter){
	for (int i = 0; i < text.length(); i++){
		if (text[i] == letter){
			return i;
			break;
		}
	}
}

string moveRingLeft(string archetype){
	string movedRing;
	char lastLetter = archetype[archetype.length() - 1];
	movedRing.append(archetype, 1, archetype.length());
	int lastLetterIndex = findIndex(alphabet, lastLetter);
	//cout << "Index szukanej litery " << lastLetterIndex << endl;
	char nextLetter = alphabet[(lastLetterIndex + 1) % 26];
	//cout << "Nastepna litera " << nextLetter << endl;
	movedRing += nextLetter;
	return movedRing;
}

string moveRingRight(string archetype){
	string movedRing;
	char firstLetter = archetype[0];
	movedRing.append(archetype, 0, archetype.length() - 1);
	int firstLetterIndex = findIndex(alphabet, firstLetter);
	char previousLetter = alphabet[(firstLetterIndex - 1 + 26) % 26];
	movedRing.insert(0, 1, previousLetter);
	return movedRing;
}

string encode(string text){
	cout << "Tekst jawny: " + text << endl;
	cout << endl;
	for (int i = 0; i < text.length(); i++){//zakodowanie ka¿dej litery po kolei
  		show(cipherArray);
		int index = findIndex(alphabet, text[i]);//znalezienie litery z tekstu do zaszyfrowania w alfabecie
		int shiftedIndex = index + 3;
		char letterInAlphabetEncryptionRing = alphabetEncryptionRing[shiftedIndex];
		text[i] = letterInAlphabetEncryptionRing;
		cout << "Tekst po pierwszej zamianie " << text << endl;
		char letterInCipherEncryptionRing = cipherEncryptionRing[shiftedIndex];
		text[i] = letterInCipherEncryptionRing;
		cout << "Tekst po drugiej zamianie " << text << endl;
		cout << endl;
		alphabetEncryptionRing = moveRingLeft(alphabetEncryptionRing);
		cipherEncryptionRing = moveRingLeft(cipherEncryptionRing);
		fillCipherArray(alphabetEncryptionRing, cipherArray, 32, 0, 0, 1);
  		fillCipherArray(cipherEncryptionRing, cipherArray, 32, 0, 0, 2);
	}
	encoded = true;
	cout << "Szyfrogram: " + text << endl;
	for (int i = 0; i < 32; i++){
		cout << "-";
	}
	cout << endl;
	return text;
}

string decode(string text){
	cout << "Szyfrogram: " + text << endl;
	cout << endl;
	if (!encoded){
		for (int i = 0; i < text.length(); i++){
			alphabetEncryptionRing = moveRingLeft(alphabetEncryptionRing);
			cipherEncryptionRing = moveRingLeft(cipherEncryptionRing);
			fillCipherArray(alphabetEncryptionRing, cipherArray, 32, 0, 0, 1);
	  		fillCipherArray(cipherEncryptionRing, cipherArray, 32, 0, 0, 2);
		}
	}else{
		alphabetEncryptionRing = moveRingRight(alphabetEncryptionRing);
		cipherEncryptionRing = moveRingRight(cipherEncryptionRing);
		fillCipherArray(alphabetEncryptionRing, cipherArray, 32, 0, 0, 1);
	  	fillCipherArray(cipherEncryptionRing, cipherArray, 32, 0, 0, 2);
	}
	for (int i = text.length() - 1; i >= 0; i--){//zakodowanie ka¿dej litery od ty³u
	 	show(cipherArray);
	 	int index = findIndex(cipherEncryptionRing, text[i]);
		char letterInAlphabetEncryptionRing = alphabetEncryptionRing[index];
		text[i] = letterInAlphabetEncryptionRing;
		cout << "Tekst po pierwszej zamianie " << text << endl;
		int shiftedIndex = index - 3;
		char letterInAlphabet = alphabet[(shiftedIndex + 26) % 26];
		text[i] = letterInAlphabet;
		cout << "Tekst po drugiej zamianie " << text << endl;
		alphabetEncryptionRing = moveRingRight(alphabetEncryptionRing);
		cipherEncryptionRing = moveRingRight(cipherEncryptionRing);
		cout << endl;
		fillCipherArray(alphabetEncryptionRing, cipherArray, 32, 0, 0, 1);
  		fillCipherArray(cipherEncryptionRing, cipherArray, 32, 0, 0, 2);
	}
	cout << "Tekst jawny: " + text << endl;
	return text;
}

int main(){
	init(cipherArray);
	string cipher = caesarCipher(alphabet, alphabet, 5);
  	alphabetEncryptionRing = createEncryptionRing(alphabet);
  	cipherEncryptionRing = createEncryptionRing(cipher);
  	fillCipherArray(alphabet, cipherArray, 29, 3, 3, 0);
  	fillCipherArray(alphabetEncryptionRing, cipherArray, 32, 0, 0, 1);
  	fillCipherArray(cipherEncryptionRing, cipherArray, 32, 0, 0, 2);
  	string code = encode("KOT");
  	decode(code);
	system("PAUSE");
	return 0;
}
