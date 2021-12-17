#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

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

    cout << "Enter vertex: " << endl; cin >> val;

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

Node* searchBST(Node* p, int key) {
    if (p == 0 || p->d == key) return p;
    if (key < p->d) return searchBST(p->left, key);
    else return searchBST(p->right, key);
}

Node* iterative_searchBST(Node* p, int key) {
    while (p != 0 && key != p->d)
        if (key < p->d) p = p->left;
        else p = p->right;
    return p;
}

Node* minBST(Node* p) {
    while (p->left != 0)
        p = p->left;
    return p;
}

Node* maxBST(Node* p) {
    while (p->right != 0)
        p = p->right;
    return p;
}

bool isEmpty() {
    return root == NULL;
}

Node* succBST(Node* p) {
    if (p->right) return minBST(p->right);
    Node* y = p->father;
    while (y != 0 && p == y->right) {
        p = y;
        y = y->father;
    }
    return y;
}

Node* predBST(Node* p) {
    if (p->left) return maxBST(p->left);
    Node* y = p->father;
    while (y != 0 && p == y->left) {
        p = y;
        y = y->father;
    }
    return y;
}

void deleteBST(Node*& root, Node* p) {
    Node* x = NULL, * y = NULL;
    if (root && p) {
        if (p->left == 0 || p->right == 0) {
            y = p;
        }
        else y = succBST(p);
        if (y->left) x = y->left;
        else x = y->right;
        if (x) x->father = y->father;
        if (y->father == 0) root = x;
        else {
            if (y == y->father->left)
                y->father->left = x;
            else y->father->right = x;
            if (y != p)p->d = y->d;
            delete y;
        }
    }
}

void inorderTree(const Node* p)
{
    stack<const Node *> stack;

    while (p != NULL || !stack.empty())
    {
        while (p != NULL)
        {
            stack.push(p);
            p = p->left;
        }

        cout << stack.top()->d << ' ';
        p = stack.top()->right;
        stack.pop();
    }
}

void clear() {
    root = NULL;
}


int main()
{
    root = makeTree(root, 5);
    preorderTree(root, 0);
    cout << "is empty: " << isEmpty() << endl;
    
    //inorderTree(root);

}
