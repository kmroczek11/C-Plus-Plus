#include <iostream>
#include <conio.h>

using namespace std;

int ile = 0;
struct Element {
	int value;//wartoœæ elementu na stosie
	Element* next;//wskaznik do nastêpnego elementu
}*stos;//nowa struktura w oparciu o strukturê element

void push(int val){
	struct Element *e = new Element;
	e->value = val;
	e-> next = stos;
	stos = e;
};

int pop(void){
	if (stos->next != NULL){
		struct Element *tmp = stos;
		stos = stos->next;
		delete tmp;	}
}

void show(void){
	while(stos != NULL){
		cout << stos->value << endl;
		stos = stos->next;
	}
}

int top(void){
	}
int main(){
	push(10);
	push(2);
	push(34);
	push(9);
	show();
	cout << endl;
	pop();
	show();
}
