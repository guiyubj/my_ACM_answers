/*2540 the hardest problem ever
@file: main.cpp
@discription: caesar cypher decrypter
@compiler: g++ -std=c++11
@author: Yu Gui	NYU
*/

#include <iostream>
#include <string>

using namespace std;

const int const_i_rotation = 5;

//decrypt a single char and return the decrypted char
char decrypt_char(char c_encrypted){
	if(int(c_encrypted) > 64 && int(c_encrypted) < 91){
		char c_decrypted = char((int)c_encrypted - const_i_rotation);

		if(int(c_decrypted) < 64){
			c_decrypted = char(int(c_decrypted) + 26);
		}
		if(int(c_decrypted) > 91){
			c_decrypted = char(int(c_decrypted) - 26);
		}
		//cout << c_decrypted;

		return c_decrypted;
	}
	else{

		return c_encrypted;
	}
}

//decrypt a string by modifying the string directly
void decrypt_str(string& str_encrypted){
	for(int i=0; i<str_encrypted.size(); i++){
		str_encrypted[i] = decrypt_char(str_encrypted[i]);
	}
	//cout << str_encrypted << endl;

	return;
}


int main(){

	//start processing input
	string str_temp_line;

	//get input content
	while(getline(cin, str_temp_line)){

		if(str_temp_line == "START"){

			getline(cin, str_temp_line);

			decrypt_str(str_temp_line);

			cout << str_temp_line << endl;
		}

		if(str_temp_line == "ENDOFINPUT"){
			return 0;
		}
	}

	return 0;
}