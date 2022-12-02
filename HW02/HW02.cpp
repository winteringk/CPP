#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip {

public:

    Station* header;
    Station* trailer;
    
    int Size;
    
    Trip()
    {
         header->prev = NULL;
		 header->next = trailer;
		 
		 trailer->prev = header;
		 trailer->next = NULL;
		 
		 Size = 0;
    }
    
    void printList()
    {
        cout << "[ ";
        Station* ptr = header->next;
        while (ptr != trailer) {
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }


    void insert_front(string newItem)
    {	Station*node = new Station; // new Node
    	node->name = newItem;
    	node->prev = NULL;
    	node->next = NULL;
    	
         if (Size == 0) { // empty
         	node->next =  trailer;
         	node->prev = header;
         	
         	trailer->prev = node;
         	header->next = node;
         	
         	header = node;
		 }
		 
		 else if (Size > 0) { // insert between head and box
		 	node->next = header->next;
		 	node->prev = header;
		 	
		 	header->next->prev = node;
		 	header->next = node;
		 	
		 	header = node;
		 }
    }
    void insert_back(string newItem)
    {
         
    }

    void remove_front()
    {
         
    }
    void remove_back()
    {
        
    }

    Station* visit(int nStep, string stepText)
    {
        
    }
};
