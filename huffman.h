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
        Huffman(char[] = " ", char[] = " ");

    private:
        // functions
        void buildFrequencyTable();
        void buildHuffmanTree();
        void sortNodeForrest();
        void buildCodeTable();

        // data
        struct Node{
            char character;
            int frequency;
            struct Node* left;
            struct Node* right;
        };
        static const int CHAR_SET_SIZE = 256;
        static const int MAX_INPUT_LEN = 5000;
        struct Node* root;
        char input[MAX_INPUT_LEN + 1];
        int charCount[CHAR_SET_SIZE];
        Node* nodeForrest[CHAR_SET_SIZE];
        int forrestSize;
        int codeTable[CHAR_SET_SIZE];
};


#endif // huffman.h
