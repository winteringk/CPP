#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card*head;
    int CardSize;

    CardList(){
        head = NULL;
        CardSize = 0;
    }

	void pop_back(){
		if (head != NULL) {
	
		 if(head->next == NULL) {
		 		Card*LastNode = head;
        		LastNode = NULL;
        		
        		delete LastNode;
        		head = NULL;
      		}
      		
      	else {
		  
			Card*temp = head;
        		while (temp -> next -> next != NULL) { // find lastNode
            		temp = temp -> next;
        		}
        		Card*LastNode = temp -> next;
        		
        
        		temp -> next = NULL;
        		delete LastNode; 
			}
        CardSize --;
    		}
	}


    void insert_back(string newItem){
        Card*NewNode = new Card;
        NewNode -> name = newItem;
        NewNode -> next = NULL;
		
        if (CardSize == 0){
            head = NewNode;
        }
        else {
        	Card*LastNode = head;
            while (LastNode -> next != NULL) {
            LastNode = LastNode -> next;
            }
            LastNode -> next = NewNode;
        }
        CardSize ++;
    }

    void shuffle(int pos){ 
        //1<=pos<=size-1
        if (1 <= pos && pos <= CardSize-1 && CardSize > 1) {
            //cards
            Card*first = head;
            Card*node1 = head;
            Card*node2 = node1 -> next;
            Card*last;

            for (int i = 1; i < pos; i++) {
                    node1 = node2; 
                    node2 = node2 -> next;
            }

            last = node2;

            while (last -> next != NULL) {
                last = last -> next; // last move to 3
            }

            head = node2;
            last -> next = first; // 3 move to 1
            node1 -> next = NULL; // last = NULL
            
        }

    }
    
    void printCardList(){
        /*
         DO NOT DELETE OR EDIT
         */
        cout << "[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
};
