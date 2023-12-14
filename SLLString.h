/*
Nadav Horowitz CS300 Data Structures
HW#2 - String as Singly Linked List - SLLString.h

This file contains function prototypes for the singly linked string (SLLString) class.
The file includes the field Node* head, and prototypes for constructors, destructors, operator overloading, and manipulation & retrieval methods.
The implementation details for the functions outlined in this file are in SLLString.cpp
*/
#ifndef SLLSTRING_H
#define SLLSTRING_H
#include "Node.h"
class SLLString {
     public:
          //Node pointer field for beginning of SLLString
          Node* head;

          //Default constructor
          SLLString() = default;

          //Default destructor
          ~SLLString() = default;

          //Constructor with C++ string parameter
          SLLString(const string& other);

          //Constructor with SLLString parameter    (copy constructor)    
          SLLString(const SLLString& other);

          //Insert Node method
          void insert(const char& newChar);

          //Return length method
          int length();

          //Erase Node(s) method
          void erase(char c);

          //Operator overloading methods
          SLLString& operator=(const SLLString& other);
          SLLString& operator+= (const SLLString& other);
          char& operator[](const int n);
          friend ostream& operator<<(ostream& os,const SLLString other);

          //Find substring methods
          int findSubstring(const SLLString& substring);
          int findSubstring(const string& substring);
};
#endif