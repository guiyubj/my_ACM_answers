/*
@author: Yu Gui
@description: NYU cs1124 rec02
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Molecule {
	int m_i_carbon;
	int m_i_hydro;
	vector<string> name;
};

//find molecule with same formula in v_molc, return index if found
int find_molecule(const vector<Molecule>& v_molc, const int i_carbon, const int i_hydro) {
	bool b_found = false;
	int i_index;
	for (i_index = 0; i_index < v_molc.size(); i_index++) {
		// cout << i_index << endl;
		if (v_molc[i_index].m_i_carbon == i_carbon && v_molc[i_index].m_i_hydro == i_hydro) {
			b_found = true;
			break;
		}
	}

	if (b_found) {
		return i_index;
	}
	else {
		return -1;
	}
}

//get molecule from input and then store it in v_molc
int get_molecule(ifstream& ifs, vector<Molecule>& v_molc) {
	string str_name;
	char c_temp;
	int i_carbon;
	int i_hydro;

	ifs >> str_name >> c_temp;
	ifs >> i_carbon >> c_temp >> i_hydro;
	// cout <<str_name << "  " << i_carbon << " " << i_hydro <<endl;

	int i_find_status = find_molecule(v_molc, i_carbon, i_hydro);
	//found formula in v_molc
	if (i_find_status >= 0) {
		v_molc[i_find_status].name.push_back(str_name);
		// cout << "found at: " << i_find_status <<endl;
	}
	else { //not found
		Molecule molc;
		molc.name.push_back(str_name);
		molc.m_i_carbon = i_carbon;
		molc.m_i_hydro = i_hydro;
		v_molc.push_back(molc);
		// cout << "not found" <<endl;
	}

	return 0;
}

//insertion sort Molecure objects in v_molc vector by carbon atom number
int sort_molecule(vector<Molecule>& v_molc) {
	// vector<Molecule> v_sorted_molc;
	Molecule molc_max;
	for (int j = 0; j < v_molc.size(); j++) {
		molc_max = v_molc[j];
		int k = j - 1;
		while (k >= 0 && v_molc[k].m_i_carbon > molc_max.m_i_carbon) {
			v_molc[k + 1] = v_molc[k];
			k--;
		}
		v_molc[k + 1] = molc_max;
	}

	return 0;
}

int main() {
	//open file and handle file exception
	ifstream ifs("hydrocarbons.txt");
	if (!ifs) {
		cerr << "ERROR: couldn't open...\n";
		cin.ignore();
		return 1;
	}

	//initiate input precessing and storing
	vector<Molecule> v_molc;
	while (ifs) {
		get_molecule(ifs, v_molc);
	}

	sort_molecule(v_molc);

	//print out sorted v_molc vector
	for (int j =0; j < v_molc.size(); j++) {
		cout << "C" << v_molc[j].m_i_carbon << "H" << v_molc[j].m_i_hydro << endl;
		for (int k = 0; k < v_molc[j].name.size(); k++) {
			cout << v_molc[j].name[k] << endl;
		}
		cout << endl;
	}

	cin.ignore();
}