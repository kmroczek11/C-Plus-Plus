#include <iostream>
#include <cstdlib>

using namespace std;
struct node{
	int value;
	node *left;
	node *right;
	node *parent;
}*root = NULL;

void addNode(node *&nd, int x){
	node *E = new node;
	E->value = x;
	E->left = NULL;
	E->right = NULL;
	E->parent = NULL;
	
	if(nd == NULL){
		nd = E;
	}
	else{
		if(x>nd->value){
			nd->parent = nd->right;
			addNode(nd->right,x);
		}
		else{
			nd->parent = nd->left;
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

node * minKey(node * nd){
    while (nd->left != NULL)
        nd = nd->left;
    return nd;
}

node * Succesor(node * nd){
    if (nd->right != NULL){
        return minKey(nd->right);
    }
    node * tmp = nd->parent;
    while (tmp != NULL && tmp->left != nd){
        nd = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

void przeszukajDrzewo(node * nd,int value){
    while (nd != NULL && nd->value != value){
        if (value < nd->value)
            nd = nd->left;
        else
            nd = nd->right;
        }
    cout << nd;
}

node * usunElement(node * nd, node *&usun){
	node * x;
	node * y;
	if (usun->left==NULL || usun->right==NULL)
	{
		y=usun;
	}
	else{
		y=Succesor(usun);
	}
	if (y->left != NULL){
		x=y->left;
	}
	else{
		x=y->right;
	}
	if (x!=NULL){
		x->parent = y->parent;
	}
	if (y->parent == NULL){
		root = x;
	}
	else
	{
		if (y == y->parent->left){
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

int main(){
	addNode(root,4);
	addNode(root,8);
	addNode(root,6);
	addNode(root,1);
	addNode(root,9);
	addNode(root,2);
	preOrder(root);
	przeszukajDrzewo(root,8);
	//usunElement(root,przeszukajDrzewo(root,2));
}
