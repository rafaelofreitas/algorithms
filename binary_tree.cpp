
/*
   Uma árvore binária de busca (ou árvore binária de pesquisa) é uma estrutura de
   dados de árvore binária baseada em nós, onde todos os nós da subárvore esquerda
   possuem um valor numérico inferior ao nó raiz e todos os nós da subárvore direita
   possuem um valor superior ao nó raiz (esta é a forma padrão, podendo as subárvores
   serem invertidas, dependendo da aplicação).
   O objetivo desta árvore é estruturar os dados de forma a permitir busca binária.
 */

#include <iostream>

using namespace std;

class Knot {

private:
Knot *left, *right;
int key;
// Knot builder
public:
Knot(int key) {
        this->key = key;
        left = NULL;
        right = NULL;
}

int getkey() {
        return key;
}

Knot* getLeft() {
        return left;
}

Knot* getRight() {
        return right;
}

void setLeft(Knot* knot) {
        left = knot;
}

void setRight(Knot* knot) {
        right = knot;
}

};

class Tree {

private:
Knot* root;

public:
Tree() {
        root = NULL;
}

void insert(int key) {
        if(root == NULL) {
                root = new Knot(key);
        } else {
                insertAux(root, key);
        }
}

void insertAux(Knot* knot, int key) {
        if(key< knot->getkey()) {
                if(knot->getLeft() == NULL) {
                        Knot* new_knot = new Knot(key);
                        knot->setLeft(new_knot);
                } else {
                        insertAux(knot->getLeft(), key);
                }
        } else if(key > knot->getkey()) {
                if(knot->getRight() == NULL) {
                        Knot* new_knot = new Knot(key);
                        knot->setRight(new_knot);
                } else {
                        insertAux(knot->getRight(), key);
                }
        }
}

Knot* getRoot() {
        return root;
}

void inOrder(Knot* knot) {
        if(knot != NULL) {
                inOrder(knot->getLeft());
                cout << knot->getkey() << '\n';
                inOrder(knot->getRight());
        }
}

};

int main(int argc, char *argv[]) {
        Tree tree;

        tree.insert(8);
        tree.insert(9);
        tree.insert(10);
        tree.insert(15);
        tree.insert(13);
        tree.insert(5);
        tree.insert(4);
        tree.insert(3);

        cout << "Percorrendo em Ordem:" << '\n';
        tree.inOrder(tree.getRoot());

        return 0;
}
