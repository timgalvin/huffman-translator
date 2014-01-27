// File - huffcode.cpp
// Tim Galvin

#include <iostream>
#include "huffman.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 2) {
        Huffman* huff = new Huffman(argv[1]);
        cout << "arg was accepted" << endl;
    }
    else if (argc == 3) {

    }
    else {
        cout << "no argument" << endl;
    }
}
