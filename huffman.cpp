// File - huffman.cpp
// Tim Galvin

#include "huffman.h"

Huffman::Huffman(char input[], char code[])
{
    // process input text
    char ch = input[0];
    int index = 0;
    while (ch != '\0' && index <= MAX_INPUT_LEN) {
        this->input[index] = ch;
        ch = input[++index];
    }
    this->input[index] = '\0';

    // initialize character counts to zero;
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        charCount[i] = 0;
    }

    buildFrequencyTable();
    buildHuffmanTree();
    buildCodeTable();
    displayEncodedBinary();
}

void Huffman::buildFrequencyTable()
{
    char ch = input[0];
    int index = 0;
    while (ch != '\0' && index <= MAX_INPUT_LEN) {
        charCount[int (ch)]++;
        ch = input[++index];
    }
    //testing code
    /*cout << "Character frequency: --------------" << endl;
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        if (charCount[i]) {
            cout << char (i) << ": " << charCount[i] << endl;
        }
    }
    cout << "-----------------------------------" << endl;*/
}

void Huffman::buildHuffmanTree()
{
    // Create array of nodes, sort once done
    forrestSize = 0;
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        if (charCount[i]) {
            struct Node* temp = new Node();
            temp->left = NULL;
            temp->right = NULL;
            temp->frequency = charCount[i];
            temp->character = char (i);
            nodeForrest[forrestSize++] = temp;
        }
    }
    sortNodeForrest();
    //test code
    /*cout << "Display node forrest" << endl;
    for (int i = 0; i < forrestSize; i++) {
        cout << nodeForrest[i]->character << ": " << nodeForrest[i]->frequency << endl;
    }
    cout << "done displaying" << endl;*/

    while (forrestSize > 1) {
        // take lowest two scores, make children of a new parent, then
        struct Node* parent = new Node();
        parent->left = nodeForrest[forrestSize - 1];
        parent->right = nodeForrest[forrestSize - 2];
        parent->frequency = parent->left->frequency + parent->right->frequency;

        // insert new node to forrest and resort
        nodeForrest[forrestSize - 2] = parent;
        nodeForrest[forrestSize - 1] = NULL;
        forrestSize--;
        sortNodeForrest();
    }
    root = nodeForrest[0];
    nodeForrest[0] = NULL;
}

void Huffman::sortNodeForrest()
{
    if (forrestSize <= 1) return;
    int i, j, flag = 1;
    Node* temp;
    for (i = 1; (i <= forrestSize) && flag; i++) {
        flag = 0;
        for (j=0; j < (forrestSize -1); j++) {
            if (nodeForrest[j+1]->frequency > nodeForrest[j]->frequency) {
                flag = 1;
                temp = nodeForrest[j+1];
                nodeForrest[j+1] = nodeForrest[j];
                nodeForrest[j] = temp;
            }
        }
    }
}

void Huffman::buildCodeTable()
{
    // do traversal of tree
    // pass code so far to next recursive instance, with child included
    buildCodeTableHelper(root, "");

    //test code
    /*cout << "Testing code table------" << endl;
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        if (charCount[i]) {
            cout << char (i) << ": " << codeTable[i] << endl;
        }
    }
    cout << "------------------------" << endl << endl;*/
    // build encoded binary string
    char ch = input[0];
    int place = 0;
    while (ch != '\0' && place < MAX_INPUT_LEN) {
        encBinaryMessage += codeTable[int (ch)];
        ch = input[++place];
    }
}

void Huffman::buildCodeTableHelper(struct Node* sub, string code)
{
    // if at a leaf, record a code
    if (!(sub->left || sub->right)) {
        int targetIndex = int (sub->character);
        codeTable[targetIndex] = code;
    }

    // if not a leaf, continue
    if (sub->left) {
        buildCodeTableHelper(sub->left, (code + "0"));
    }
    if (sub->right) {
        buildCodeTableHelper(sub->right, (code + "1"));
    }
}

void Huffman::displayEncodedBinary()
{
    cout << encBinaryMessage;
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        if (charCount[i]) {
            cout << "@@@" << char (i) << ": " << codeTable[i];
        }
    }

}








