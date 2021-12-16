#include <iostream>

using namespace std;

struct Node {

    int d;

    Node* father;    //указатель на родителя

    Node* left;

    Node* right;

    Node() { father = right = left = NULL; }

};

Node* root = NULL;



Node* makeTree(Node* root, int N) {

    int NL, NR, val;

    if (N == 0) return NULL;

    NL = N / 2;

    NR = N - NL - 1;

    Node* temp = new Node;

    cout << "Значение вершины : " << endl; cin >> val;

    temp->d = val;

    temp->left = makeTree(root, NL);

    temp->right = makeTree(root, NR);

    return temp;

}

//------------------------------------------------------------------

void preorderTree(Node* p, int l) {

    if (p) {

        for (int i = 0; i < l; i++) cout << ' '; //вывод отступов

        cout << p->d << endl;         //вывод значения из вершины     

   // рекурсивный вызов увеличивает номер уровня

        preorderTree(p->left, l + 1);

        preorderTree(p->right, l + 1);

    }

}

void insertBST(Node*& root, int val) {
    Node* z = new Node;
    z->d = val;
    if (root == NULL) {
        root = z;
        return;
    }
    Node* y = NULL, * x = root;
    while (x) {
        y = x;
        if (z->d < x->d) x = x->left;
        else x = x->right;
    }
    z->father = y;
    if (y->d > z->d)
        y->left = z;
    else y->right = z;
}


int main()
{
    root = makeTree(root, 5);
    preorderTree(root, 0);

}
