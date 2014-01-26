// File - huffman.h
// A tool to encode and decode strings using Huffman algorithm
// Tim Galvin

#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>

using namespace std;

class Huffman
{
    public:
        Huffman(char[] = " " );
        char input[5000];
    private:

        int charCount[256];
};


#endif // huffman.h
