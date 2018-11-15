#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

using namespace std;

template <typename T>
class Matrix {
private:
    Node<T>* hRows;
    Node<T>* hColumns;
    int columns;
    int rows;

public:
    Matrix();
    Matrix(int sizeColumns, int sizeRows)
    {
        columns = sizeColumns;
        rows = sizeRows;

        hColumns = new Node<T>();
        hRows = new Node<T>();

        Node<T>* tmp = hRows;
        for(size_t i = 0; i < sizeRows; i++)
        {
            Node<T>* newHeader = new Node<T>();
            tmp->next = nullptr;
            tmp->down = newHeader;
            tmp = tmp->down;
        }

        tmp = hColumns;
        for(size_t i = 0; i < sizeColumns; i++)
        {
            Node<T>* newHeader = new Node<T>();
            tmp->next = newHeader;
            tmp->down = nullptr;
            tmp = tmp->next;
        }

        /* cout << "cols: " << endl;

        tmp = hColumns;
        int i = 0;
        while(tmp->next)
        {
            cout << i << " ";
            tmp = tmp->next;
            i++;
        }

        cout << endl << "rows: " << endl;

        tmp = hRows;
        i = 0;
        while(tmp->down)
        {
            cout << i << " ";
            tmp = tmp->down;
            i++;
        } */

    };

    void set(int row, int col, T data)
    {
        cout << "col: " << col << endl;
        Node<T>* newNode = new Node<T>(data, row, col);
        if (row < rows && col < columns)
        {
            if (hRows->next == nullptr)
            {
                hRows->next = newNode;
                cout << "first insert: " << hRows->next << " | " << hRows->next->data << endl;
            }
            else
            {
                int counter = -1;
                Node<T>** tmp = &(hRows->next);

                while (counter < col && (*tmp)->next)
                {
                    counter++;
                    tmp = &((*tmp)->next);
                    cout << "c: " << counter << endl;
                }

                cout << "looking at: " << (*tmp)->data << " at position: " << (*tmp)->col << endl;
                cout << "counter: " << counter<< endl;

                if(counter == col)
                {
                    cout << "hit replace" << endl;
                    cout << "(*tmp): " << (*tmp)->data << endl;
                    cout << "(*tmp)->col: " << (*tmp)->col << endl;
                    /* newNode->next = (*tmp)->next;
                    *tmp = newNode; */
                    newNode->next = (*tmp)->next;
                    *tmp = newNode;
                }
                else
                {
                    if (col < (*tmp)->col)
                    {
                        // Add in between
                        cout << "hit between" << endl;
                        cout << "putting " << newNode->data << "->" << (*tmp)->data << endl;
                        newNode->next = *tmp;
                        *tmp = newNode;
                    }
                    else
                    {
                        // Add after
                        //fakePrint();
                        cout << "hit after" << endl;
                        cout << "(*tmp) = " << (*tmp)->data << endl; 
                        (*tmp)->next = newNode;
                    }
                }
            }
            fakePrint();
            cout<< endl << endl; 
            
            /* Node<T>* rowHeader = hRows;
            Node<T>* colHeader = hColumns;

            for(size_t i = 0; i < row; i++) rowHeader = rowHeader->down;
            for(size_t i = 0; i < col; i++) colHeader = colHeader->next; 
            
            if (rowHeader->next == nullptr && colHeader->down == nullptr)
            {
                Node<T>* newNode = new Node<T>(data);
                rowHeader->next = newNode;
                colHeader->down = newNode;
            }
            else
            {
                Node<T>* newNode = new Node<T>(data);

                int counterRow = 0;
                int counterCol = 0;

                while (rowHeader->next && counterCol <= col)
                {
                    counterCol++;
                    rowHeader = rowHeader->next;
                }
                while (colHeader->down) colHeader = colHeader->down;
                rowHeader->next = newNode;
                colHeader->down = newNode;
            } */

        }
        else cout << "error" << endl;
        
        
    };

    T operator()(int x, int y)
    {

    };
    Matrix<T> operator*(Matrix<T> other);
    Matrix<T> operator*(T scalar);
    Matrix<T> operator+(Matrix<T> other);
    Matrix<T> operator-(Matrix<T> other);
    Matrix<T> transposed();
    Matrix<T> operator=(Matrix<T> other);

    void fakePrint()
    {
        // Debug
        cout << "list: " << endl;
        Node<T>* tmp = hRows->next;
        while (tmp)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
        // End debug
    }

    //~Matrix();
};

#endif