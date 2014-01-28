// File - huffman.h
// A tool to encode and decode strings using Huffman algorithm
// Tim Galvin

#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <iostream>
#include <string>

using namespace std;

class Huffman
{
    public:
        Huffman(char[] = " ", char[] = " ");

    private:
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
        string codeTable[CHAR_SET_SIZE];
        string encBinaryMessage;

        // functions
        void buildFrequencyTable();
        void buildHuffmanTree();
        void sortNodeForrest();
        void buildCodeTable();
        void buildCodeTableHelper(Node*, string);
        void displayEncodedBinary();
};


#endif // huffman.h
