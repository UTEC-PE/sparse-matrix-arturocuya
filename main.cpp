#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int>* matrix = new Matrix<int>(4, 4);

    matrix->set(0,1,4);
    matrix->set(0,0,3);
    matrix->set(0,3,6);
    matrix->set(0,1,9);

    return 0;
}