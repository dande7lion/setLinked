#include "setLinked.cpp"

int main(){

	linkedSet set;

	cout << "Example: "<< endl << endl;

	cout << "Set(1) after inserting elements:\n";
	set.insertValue(9);
	set.insertValue(180);
	set.insertValue(340);
	set.insertValue(15);
	set.insertValue(39);

	set.print();

	cout << endl << "After deleting 180: \n";

	set.deleteValue(180);
	set.print();

	cout << endl << "Set(2) after inserting elements:\n";

	linkedSet set2;
	set2.insertValue(15);
	set2.insertValue(347);
	set2.insertValue(857);
	set2.insertValue(9);

	set2.print();

	linkedSet result;
	result = set.unionOfSets(set2);
	cout << endl << "Union: " << endl;
	result.print();

	cout << endl  << "Identity: " ;
	if(set.identity(set2))
		cout << "true" << endl;
	else cout << "false" << endl;

	result = set2.difference(set);
	cout << endl << "Difference: (2 - 1): " << endl;
	result.print();

	result = set.difference(set2);
	cout << endl << "Difference: (1 - 2): " << endl;
	result.print();

	result = set.intersection(set2);
	cout << endl << "Intersection: " << endl;
	result.print();


	return 0;
}
