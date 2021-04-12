//
//  DoublyLinkedList.hpp
//  Netflix_1
//
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <stdexcept>
#include "Movie.hpp"


template <typename Type>
class DoublyLinkedList {
	friend class Movie;
public:

	DoublyLinkedList() {
		header = nullptr;
	}

	unsigned int size() {
		return n;
	}

	bool isEmpty() {
		if (n == 0) {
			return 1;
		}
		return 0;
	}

	void insert(Type& e) {
		if (isEmpty() == true) {
			header = new Node;
			header->data = e;
			trailer = header;
			header->next = nullptr;
			header->prev = nullptr;
			n++;
		}
		else {
			Node* Edit = header;
			bool isEdit = false;

			for (unsigned int i = 0; i < size(); i++) {
				if ((*this)[i] == e) {
					(*this)[i] = e;
					isEdit = true;
					break;
				}
			}

			if (isEdit == false) {
				Edit = header;
				Node* follow = header;
				Node* pTemp;
				pTemp = new Node;

				while (Edit->next != nullptr) { //node Edit points to end
					Edit = Edit->next;
				}

				Edit->next = pTemp; //attaches ptemp to the end
				pTemp->next = nullptr;
				pTemp->data = e;
				trailer = pTemp;
				while (follow->next != pTemp) {
					follow = follow->next;
				}
				pTemp->prev = follow;
				n++;
			}
		}
	}

	unsigned int find(Type& e) {
		Node* pTemp = header;
		unsigned int index = 0;
		bool isFound = false;

		for (unsigned int i = 0; i < size(); i++){
			index = i;
			if (pTemp->data == e){
				isFound = true;
				return  index;
			}
			pTemp = pTemp->next;
		}
		if (isFound == false) {
			throw std::exception("Find Error");
		}
	}

	void erase(unsigned int index) {
		Node* pTemp = header;
		if (isEmpty() == true || index >= n) {
			return;
		}
		else if (index == 0) {
			header = header->next;
			delete pTemp;
			n--;
		}
		else if (index == size() - 1) {
			pTemp = trailer;
			trailer = trailer->prev;
			delete pTemp;
			n--;
		}
		else {
			pTemp = header;
			for (int i = 0; i < index; i++){ //node pTemp points to index location
				pTemp = pTemp->next;
			}

			Node* after = pTemp->next;//after
			Node* before = pTemp->prev;//before

			after->prev = before;
			before->next = after;


			delete pTemp;

			n--;
		}
	}

	void show() {

	}

	void sort() {
		Movie holder;
		Node* pTemp = header;
		unsigned int k = 0;
		unsigned char i = 0;

		while (i < n-1) {
			i++;
			k = i;
			while ((*this)[k] < (*this)[k - 1]&& k > 0) {
				holder = (*this)[k - 1];
				(*this)[k - 1] = (*this)[k];
				(*this)[k] = holder;
				k--;
			}
		}
	}

	Type& getHead() {
		return header->data;
	}

	Type& getTail() {
		return trailer->data;
	}

	Type& operator[] (const unsigned int index) {
		if (index >= n)
			throw std::out_of_range("out of range error"); 
		else {
			Node* pTemp = header;
			for (size_t i = 0; i < index; i++) {
					pTemp = pTemp->next;
			}
			return pTemp->data;
		}		
	}
    
private:
    struct Node {
        Type data;
        Node* prev;
        Node* next;
    };
    
    unsigned int n;
    Node* header;
    Node* trailer;
    
};



#endif /* DoublyLinkedList_hpp */
