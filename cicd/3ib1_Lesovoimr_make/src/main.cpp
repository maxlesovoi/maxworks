#include <iostream>
#include "pow.h"
using namespace std;

int main(int argc, char* argv[]){
    float a = atof(argv[1]);
    int b = atoi(argv[2]);

    cout << "Function pow: " << pow(a,b) << endl;
}