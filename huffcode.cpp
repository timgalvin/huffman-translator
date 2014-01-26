// File - huffcode.cpp
// Tim Galvin

#include <iostream>
#include "huffman.h"
using namespace std;

int main(int argc, char* argv[])
{
    if (argc > 1) {
        Huffman* huff = new Huffman(argv[1]);
        cout << "arg was: " << huff->input << endl;
    } else {
        cout << "no argument" << endl;
    }
}
