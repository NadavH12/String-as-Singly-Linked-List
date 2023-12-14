/*
Nadav Horowitz CS300 Data Structures
HW#2 - String as Singly Linked List - SLLString.cpp

This file contains the implementation details for the functions specified in SLLString.h.
The file contains functions for manipulation of the singly linked list string (SLLString), and for retrieving it's values.
The file also overloads operators '<<', '=', '+=', and '[]'.
*/
#include "SLLString.h"

     //Copy constructor taking a C++ string as parameter (deep copy constructor)
     SLLString::SLLString(const string& other){
          head = nullptr;//initializes Node* head field
          for(int i = 0; i < other.length(); i++){
               insert(other.at(i));//Fills SLLString with chars
          }
     }

     //Copy constructor for SLLString taking another SLLString as parameter
     SLLString::SLLString(const SLLString& other){
          *this = other;//Shallow copy constructor
     }

     //Inserts a Node with character newChar to end of the SLLString
     void SLLString::insert(const char& newChar){
          Node* newNode = new Node(newChar);//creation of new Node with char to be inserted
          if (head == nullptr){             
               head = newNode;//checks for empty SLLString, if empty inserts
          } 
          else {
               Node* current = head;//current pointer copies head pointer by value
               while(current->next != nullptr){
                    current = current->next;//traverse SLLString until end using current pointer
               }
               current->next = newNode;//Insert Node with specified char to end
          }
     }

     //Returns the length of the SLLString (Number of Nodes)
     int SLLString::length(){
          int nodeCount = 0;
          Node* current = head;//current pointer copies head pointer by value
          while(current != nullptr){
               nodeCount++; //traverse SLLString counting the Nodes along the way
               current = current->next;
          }
          return nodeCount;//returns number of Nodes
     }

     //Erases all occurrences of parameter char c in the SLLString
     void SLLString::erase(char c){
          while(head->data == c){//While first Node contains char to be erased
               head = head->next;//move head pointer to next Node (deletes 1st Node replaces with 2nd Node)  
          }
          Node* current = head;//Copy head pointer by value
          while(current->next != nullptr){//Now we know the first Node does not contain char to be erased
               if(current->next->data == c){//if next node contains char to be erased
                    current->next = current->next->next;//replace the next node with the one after it (remove it)
               }
               else{
                    current = current->next;//otherwise proceed to next Node and keep traversing SSLString until end
               }
          }
     }

     //Overloads assignment operator to make compatible with SLLString
     SLLString& SLLString::operator=(const SLLString& other){
          this->head = other.head;
          return *this;
     }

     //Overloads '+=' operator to implement SLLString concatenation
     SLLString& SLLString::operator+= (const SLLString& other){
          if(this->head != nullptr){//If first SLLString is not empty
               Node* S1 = this->head;//copy first SLLString head pointer by value
               while(S1->next != nullptr){//traverse SLLString until it's end
                    S1 = S1->next;
               }
               S1->next = other.head;//set the last pointer of this SLLString (null before) to point to the value pointed
          }                          //at by the others head pointer (link end Node of SLL1 to head Node of SLL2)
          else {
               *this = other;//else SLLString 1 is empty, so just return SLLString2
          }
          return *this;//return concatenated SLLString
     }

     //Overloads '[]' operator to get character at index n
     char& SLLString::operator[](const int n){
          Node* current = head;//copy head Node by value
          for(int i = 0; i < n; i++){//loops through SLLString Nodes, quantity determined by parameter
               current = current->next;
          }
          return current->data;//returns the char of the Node at the specified "index"
     }

     //Overloads '<<' operator to make compatible with cout
     ostream& operator<<(ostream& os, const SLLString other){
          string s = "";
          Node* current = other.head;
          while(current != nullptr){    //loop through SLLString to build a string with the chars in the Nodes
               s = s + current->data;
               current = current->next;
          }
          os << s; //put the built string into the os object
          return os; //return os object
     }
   
     //Finds the index of the first occurrence of substring in the current string. Takes SLLString parameter. Returns -1 if not found
     int SLLString::findSubstring(const SLLString& substring){ 
          string listString = "";
          Node* current = substring.head;
          while(current != nullptr){ //extracts string from parameter SLLString
               listString = listString + current->data;
               current = current->next;
          }       
          int result = this->findSubstring(listString); //calls string findsubstring method
          return result;
     }

     //Finds the index of the first occurrence of substring in the current string. Takes regular string parameter. Returns -1 if not found
     int SLLString::findSubstring(const string& substring){
          string listString = "";
          Node* current = this->head;//extracts string from this SLLString
          while(current != nullptr){
               listString = listString + current->data;
               current = current->next; 
          int index = -1;
          index = listString.find(substring);     //uses built-in findsubstring method
          return index;
     }