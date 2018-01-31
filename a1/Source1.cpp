/*Assignment 1
  Frank Brewster
  Single electron atom, transition energy calculator using Bohr model
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>

using namespace std;

int getValidInt(minVal) {
	int in;
	cout << "Sorry that's not a valid input, please enter another: ";
	cin >> in;
	while (cin.fail() || in <= minVal) {
		cout << "Sorry that's not a valid input, please enter another: ";
		cin >> in;
	}
	return in;
}

int main() {
	//Declare variables
	const double rydE{ 13.605693 };//Rydberg energy unit
	const double eV{ 1.6021766e-19 };//Elelctron volt
	int Z;
	bool cont{ true };
	int ni;
	int nf;
	char outUnits;
	double delE;
	string unitText;
	string outText;

	//Take inputs
	cout << "This programme calculates the transition energy between 2 single electron levels" << endl;
	while (cont) {
		cout << "Enter the atomic number of the atom: ";
		cin >> Z;
		if(cin.fail() || Z<1) {
			Z{ getValidInt(1) };
		}
		cout << "Enter the initial quantum number: ";
		cin >> ni;
		if (cin.fail() || ni < 0) {
			ni{ getValidInt(0) };
		}
		cout << "Enter the final qunatum number: ";
		cin >> nf;
		if (cin.fail() || ni < nf) {
			nf{ getValidInt(ni+1) };
		}
		cout << "Would you like the output in eV [e] or Joules [J]?: ";
		cin >> outUnits;
		while (cin.fail() || (outUnits!='e' && outUnits!='J')) {
			cout << "That wasnt a valid input, please enter 'e' for eV or 'J' for Joules: ";
			cin >> outUnits;
		}

		//Calculate energy
		delE{ rydE*Z ^ 2 * (1 / (ni ^ 2) - 1 / (nf ^ 2)) };
		if (outUnits == 'J') {
			delE{ delE*eV };
			unitsText{ "J" };
		}
		else {
			unitsText{ "eV" };
		}

		//Output Answer
		outText{}
	}
	return 0;
}