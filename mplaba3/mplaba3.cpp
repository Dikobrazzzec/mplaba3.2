#include <stdio.h>
#include <iostream>

using namespace std;

class Node {
	int value;
	Node* nexptr;
	friend class List;
};

class List  {
public:
	Node* head = nullptr;  //заголовок - начало списка
	int ListLength = 0;
	Node* tail = nullptr; //конец списка

	List() { head = nullptr; }
	
	//~List();

	Node* Add(Node* ptr, int INvalue) {
		Node* elem = new Node();
		elem->value = INvalue;
		if (ptr == nullptr) {
			if (head == nullptr) {    //нет элементов списка
				head = elem;
				tail = elem;
				ListLength++;
				return elem;
			} else {				  //есть элементы, но не передан после какого элемента будет стоять новый
				elem->nexptr = head;
				head = elem;
				tail->nexptr = elem;
				ListLength++;
				return elem;
			} 
		} else {					// есть эл-ты и передан после какого будет
			elem->nexptr = ptr->nexptr;
			if (ptr->nexptr == head) tail = elem; 
			ptr->nexptr = elem;
			ListLength++;
			return elem;
		}
	}

	bool isEmpty() {
		if (head == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Delet (Node* ptr) {						
		if (isEmpty() == true) {
			if (ptr->nexptr == head) head = ptr->nexptr->nexptr;
			if (ptr->nexptr == tail) tail = ptr;
			ptr->nexptr = ptr->nexptr->nexptr;
			ListLength--;
			return true;
		}
		else {
			return false;
		}
	}

	Node* Find(int FindValue) {
		Node* workptr = head;
		for (int i = 0; i < ListLength; i++) {
			if (workptr->value == FindValue) {
				break;
				cout << "Win!" << endl;
			}
			else {
				workptr = workptr->nexptr;
			}
		}
		return workptr;
	}

	void Print(Node* ptr) {
		cout << ptr->value << endl;
	}
};

int main()
{
	List A;
	A.Add(0,1);
	A.Add(0, 2);
	A.Add(0, 3);
	A.Add(0, 4);
	A.Print(A.Find(2));
	A.Delet(A.Find(2));
   
}
