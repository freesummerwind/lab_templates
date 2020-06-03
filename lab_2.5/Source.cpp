#include "Vector.h"
#include "Person.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Vector<int> vect1;
	for (int i = 0; i < 5; ++i) vect1.push_back(i + 1);
	cout << "Vector 1: ";
	for (int i = 0; i < 5; ++i) cout << vect1[i] << ' ';
	cout << endl;
	Vector<int> vect2(vect1);
	cout << "Vector 2: ";
	for (int i = 0; i < 5; ++i) cout << vect2[i] << ' ';
	cout << endl;
	for (int i = 0; i < 5; ++i) vect2[i] = 6 + i;
	Vector<int> vect3 = vect2;
	cout << "Vector 3: ";
	for (int i = 0; i < 5; ++i) cout << vect3[i] << ' ';
	cout << endl;
	cout << "Vector 1, position 3: " << vect1.at(3) << endl;
	cout << "Vector 2, front: " << vect2.front() << endl;
	cout << "Vector 3, back: " << vect3.back() << endl;
	cout << "Vector 1, data: " << vect1.data() << " - value " << *vect1.data() << endl;
	cout << "Is Vector 2 empty? " << vect2.empty() << endl;
	Vector<double> vect4;
	cout << "Is Vector 4 empty? " << vect4.empty() << endl;
	cout << "Vector 3's size: " << vect3.size() << endl;
	vect3.resize(3);
	cout << "New Vector 3's size: " << vect3.size() << endl;
	cout << "Vector 1's capacity: " << vect1.capacity() << endl;
	vect2.clear();
	cout << "New Vector 2: ";
	for (int i = 0; i < vect2.size(); ++i) cout << vect2[i] << ' ';
	cout << endl;
	vect3.insert(1, 0);
	vect3.erase(3);
	cout << "New Vector 3: ";
	for (int i = 0; i < vect3.size(); ++i) cout << vect3[i] << ' ';
	cout << endl;
	vect1.erase(1, 2);
	vect1.swap(vect3);
	cout << "New Vector 1: ";
	for (int i = 0; i < vect1.size(); ++i) cout << vect1[i] << ' ';
	cout << endl;
	cout << "New Vector 3: ";
	for (int i = 0; i < vect3.size(); ++i) cout << vect3[i] << ' ';
	cout << endl;
	vect3.pop_back();
	cout << "New Vector 3: ";
	for (int i = 0; i < vect3.size(); ++i) cout << vect3[i] << ' ';
	cout << endl;

	// Demonstration by person type

	Vector<Person> people;
	people.push_back({ "Max", 21, true });
	people.push_back({ "Nicolet", 17, false });
	people.push_back({ "Ted", 19, false });
	cout << "My Vector:\n";
	for (int i = 0; i < people.size(); ++i)
	{
		cout << people[i].name << ", " << people[i].age << " years old, " <<
			(people[i].employed ? "employed" : "unemployed") << endl;
	}
	people.insert(3, { "Ann", 27, true });
	cout << "New Vector:\n";
	for (int i = 0; i < people.size(); ++i)
	{
		cout << people[i].name << ", " << people[i].age << " years old, " <<
			(people[i].employed ? "employed" : "unemployed") << endl;
	}
	return 0;
}