#include <iostream>

using namespace std;

struct Node {
	int value;
	Node * next;
};

typedef Node * position;

class linkedSet {
protected:
	position l;	

public:
	linkedSet();
	bool insertValue(int value);
	bool deleteValue(int value);
	bool containsValue(int value);
	linkedSet intersection(linkedSet linkedSetB);
	linkedSet unionOfSets(linkedSet linkedSetB);
	linkedSet difference(linkedSet linkedSetB);
	bool identity(linkedSet linkedSetB);
	void print();
};

linkedSet::linkedSet(){
	l = new Node;
	l -> next = NULL;
}

bool linkedSet::insertValue(int value){
	position where;
	where = l;

	while(where -> next != NULL) {
		if((where -> next -> value) > value){
			break;
		} 
		where = where -> next;
	}

	if(where -> next != NULL){
		if((where -> next -> value) == value){
			return false;
		}
	}

	position tmp;
	tmp = where -> next;
	where -> next = new Node;
	where -> next -> value = value;
	where -> next -> next = tmp;

	return true;
}

bool linkedSet::deleteValue(int value){
	position where = l;

	while(where -> next != NULL) {
		if((where -> next -> value) > value){
			return false;
		} 

		else if((where -> next -> value) == value){
			position tmp;
			tmp = where -> next;
			where -> next = where -> next -> next;
			delete tmp;
			return true;
		}

		where = where -> next;
	}

	return false;
}

bool linkedSet::containsValue(int value){
	position where = l;

	while(where -> next != NULL) {
		if((where -> next -> value) > value){
			return false;
		} 

		else if((where -> next -> value) == value){
			return true;
		}

		where = where -> next;
	}

	return false;
}

void addElement(position &tmp, int value){
	position pom = tmp -> next;
	tmp -> next = new Node;
	tmp -> next -> value = value;
	tmp -> next -> next = pom;
	tmp = tmp -> next;

}

linkedSet linkedSet::intersection(linkedSet B){
	position p = l;
	position q = B.l;
	linkedSet result;
	position tmp;
	tmp = result.l;

	while((p -> next != NULL) && (q -> next != NULL)){
		if(p -> next -> value >= q -> next -> value){
			if(p -> next -> value == q -> next -> value){
				addElement(tmp, p -> next -> value);
				p = p -> next;
				q = q -> next;
				continue;
			}
			else {
				addElement(tmp, q -> next -> value);
				q = q -> next;
				continue;
			}
		}

		else{
			addElement(tmp, p -> next -> value);
			p = p -> next;
			continue;
		}
	}

	while(p -> next != NULL){
		addElement(tmp, p -> next -> value);
		p = p -> next;
	}

	while(q -> next != NULL){
		addElement(tmp, q -> next -> value);
		q = q -> next;
	}

	return result;

}

bool linkedSet::identity(linkedSet B){
	position p = l;
	position q = B.l;

	while ((p -> next != NULL) && (q -> next != NULL)){
		if(p -> next -> value == q -> next -> value){
			p = p -> next;
			q = q -> next;
		}

		else{
			return false;
		}
	}

	if((p -> next == NULL) && (q -> next == NULL)){
		return true;
	}

	else{
		return false;
	}
}
	

linkedSet linkedSet::unionOfSets(linkedSet B){
	position p = l;
	position q = B.l;
	linkedSet result;
	position tmp = result.l;

	while(p -> next != NULL){
		while((q -> next != NULL) && (p -> next -> value >= q -> next -> value)){
				if(p -> next -> value == q -> next -> value){
					addElement(tmp, p -> next -> value);
				}
		q = q -> next;
		}
	p = p -> next;
	}

	return result;
}

void linkedSet::print(){
	position tmp;
	tmp = l;

	while((tmp -> next) != NULL){
		cout << tmp -> next -> value << " ";
		tmp = tmp -> next;
	}
	cout << endl;
}

linkedSet linkedSet::difference(linkedSet B){
	position p = l;
	position q = B.l;
	linkedSet result;
	position tmp = result.l;

	while((p -> next != NULL) && (q -> next != NULL)){
		if(p -> next -> value > q -> next ->  value){
			q = q -> next;
		}
		else if(p -> next -> value != q -> next -> value){
			addElement(tmp, p -> next -> value);
			p = p -> next;
		} 

		else if(p -> next -> value == q -> next -> value){
			p = p -> next;
			q = q -> next;
		}

		else if(p -> next -> value < q -> next -> value){
			addElement(tmp, p -> next -> value);
			p = p-> next;
		}
	}


	while(p -> next != NULL){
		addElement(tmp, p -> next -> value);
		p = p -> next;
	}

	return result;
}

