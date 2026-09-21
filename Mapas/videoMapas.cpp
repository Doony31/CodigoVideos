#include "pch.h"
#include "iostream"

using namespace std;

int main() {

    int numero = 10;
    int* ptr = &numero;
    int** dptr = &ptr;

    cout << *dptr << endl;


    system("pause>0");
    return 0;
}
