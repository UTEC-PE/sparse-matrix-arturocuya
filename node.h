#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
public:
    int row, col;
    T data;
    Node* next;
    Node* down;

    Node() {};
    Node(T data, int row, int col): data(data), row(row), col(col), next(nullptr), down(nullptr) {};
};

#endif