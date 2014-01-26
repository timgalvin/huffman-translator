// File - huffman.cpp
// Tim Galvin

#include "huffman.h"

Huffman::Huffman(char input[])
{
    char ch = input[0];
    int index = 0;
    while (ch != '\0' && index <= 5000) {
        this->input[index] = ch;
        ch = input[++index];
    }
    this->input[index] = ch;
}
