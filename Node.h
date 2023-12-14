/*
Nadav Horowitz CS300 Data Structures
HW#2 - String as Singly Linked List - Node.h

This file contains the function prototypes and the implementation details for the Node class.
Each Node object contains a char and a pointer to the next Node, and is used to implement the SSLString class.
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;
class Node {
     public:
          //Each Node object holds a char and a reference to another Node
          char data;
          Node* next;

          //Constructor for Node with char and next Node
          Node(char letter, Node* nextNode){
               data = letter;
               next = nextNode;
          }

          //Constructor for Node with char and null pointer
          Node(char letter){
               data = letter;
               next = nullptr;
          }

          //Default Constructor
          Node(){
          }
};
#endif