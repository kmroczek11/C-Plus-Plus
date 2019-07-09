#include <iostream>
#include <cstdlib>

using namespace std;
struct node{
	int value;
	node *left;
	node *right;
	node *top;
}*root = NULL;

void addNode(node *&nd, int x){
	node *E = new node;
	E->value = x;
	E->left = NULL;
	E->right = NULL;
	E->top = NULL;
	
	if(nd == NULL){
		nd = E;
	}
	else{
		if(x>nd->value){
			nd->top = nd->right;
			addNode(nd->right,x);
		}
		else{
			nd->top = nd->left;
			addNode(nd->left,x);
		}
	}
}

void preOrder(node * nd){
	cout << nd -> value << endl;
	if(nd->left!=NULL){
		cout << "Lewy element:";
		cout << endl;
		preOrder(nd->left);
	}
	if(nd->right!=NULL){
	cout << "Prawy element:";
	cout << endl;
	preOrder(nd->right);
	}
}

void minKey(node * nd){
    while (nd->left != NULL)
        nd = nd->left;
    cout << nd->value;
}

void Succesor(node * nd){
    if (nd->right != NULL){
        return minKey(nd->right);
    }
    node * tmp = nd->top;
    while (tmp != NULL && tmp->left != nd){
        nd = tmp;
        tmp = tmp->top;
    }
    cout << tmp->value;
}


void przeszukajDrzewo(node * nd, int value){
    if (nd == NULL || nd->value == value)
        cout << nd;
    if (value < nd->value)
        return przeszukajDrzewo(nd->left,value);
    return przeszukajDrzewo(nd->right,value);
}

//////////do zmiany///////////////////////////////////
/*
void usunElement(node * nd, node *&usun){
	if (usun->left==NULL || usun->right==NULL)
	{
		nd *y=usun;
	}
	else{
		*y=Succesor(usun);
	}
	if (y->left != NULL){
		x=y->left;
	}
	else{
		x=y->right;
	}
	if (x!=NULL){
		x->top = y->parent;
	}
	if (y->top == NULL){
		nd->root = x;
	}
	else
	{
		if (y == y->parent->Left){
			y->parent->left = x;
		}
		else{
			y->parent->right = x;
		}
	}
	if (y != usun){
		usun->value = y->value;
	}
	return y;
}
//////////////////////////////////////////////////////////////////
*/

int main(){
	addNode(root,4);
	addNode(root,8);
	addNode(root,6);
	addNode(root,1);
	addNode(root,9);
	addNode(root,2);
	//preOrder(root);
	Succesor(root);
	//usunElement(root,przeszukajDrzewo(root,1));
	//minKey(root);
}
