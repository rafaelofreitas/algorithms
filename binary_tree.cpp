
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

int get_key() {
        return key;
}

Knot* get_left() {
        return left;
}

Knot* get_right() {
        return right;
}

void set_left(Knot* knot) {
        left = knot;
}

void set_right(Knot* knot) {
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
                insert_aux(root, key);
        }
}

void insert_aux(Knot* knot, int key) {
        if(key< knot->get_key()) {
                if(knot->get_left() == NULL) {
                        Knot* new_knot = new Knot(key);
                        knot->set_left(new_knot);
                } else {
                        insert_aux(knot->get_left(), key);
                }
        } else if(key > knot->get_key()) {
                if(knot->get_right() == NULL) {
                        Knot* new_knot = new Knot(key);
                        knot->set_right(new_knot);
                } else {
                        insert_aux(knot->get_right(), key);
                }
        }
}

Knot* get_root() {
        return root;
}

void in_order(Knot* knot) {
        if(knot != NULL) {
                in_order(knot->get_left());
                cout << knot->get_key() << '\n';
                in_order(knot->get_right());
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
        tree.in_order(tree.get_root());

        return 0;
}
