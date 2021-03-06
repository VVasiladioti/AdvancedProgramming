
#include "pch.h"
#include <cstdlib>
#include <time.h>  
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int ROOT[4];
void generate_ROOT() {
	for (int i = 0; i < 4; i++) {
		ROOT[i] = rand() % 10;
	}
}

int UHF[4];
void generate_UHF() {
	for (int i = 0; i < 4; i++) {
		UHF[i] = rand() % 19-9;
	}
}

int LHF[4];
void generate_LHF() {

	for (int i = 0; i < 4; i++) {
		LHF[i] = rand() % 19 - 9;
	}
}

int PHF[4];
int generate_PHF() {
	for (int i = 0; i < 4; i++) {
		PHF[i] = rand() % 19 - 9;
	}
	return 0;
}

int CN[4];
void generate_CN() {
	int Temp[4];
	for (int i = 0; i < 4; i++) {
		Temp[i] = (ROOT[i] + UHF[i]) % 10;
		if (Temp[i] < 0)
			Temp[i] += 10;
		CN[i] = abs(Temp[i]);
	}
}

int LN[4];
void generate_LN() {
	int Temp[4];
	for (int i = 0; i < 4; i++) {
		Temp[i] = (CN[i] + LHF[i]) % 10;
		if (Temp[i] < 0)
			Temp[i] += 10;
		LN[i] = abs(Temp[i]);
	}
}

int HN[4];
void generate_HN() {
	int Temp[4];
	for (int i = 0; i < 4; i++) {
		Temp[i] = (LN[i] + PHF[i]) % 10;
		if (Temp[i] < 0) 
			Temp[i] += 10;
		HN[i] = abs(Temp[i]);
	}
}

void nextlock_CN() {
	for (int i = 0; i < 4; i++) {
		CN[i] = HN[i];
	}
}

bool password_validation() {
	bool password = true;
	int i = 0;
	if ((CN[0] == CN[1]) || (CN[0] == CN[2]) || (CN[0] == CN[3]) || (CN[1] == CN[2]) || (CN[1] == CN[3]) || (CN[2] == CN[3]) || ((CN[0] + CN[1]) >= (CN[2] + CN[3])) || ((CN[0] + CN[1] + CN[2] + CN[3]) % 2) == 1) {
		password = false;	
	}	
	return password;
}

int main() {
	int max;
	cout << "How many times do you want to try to unlock the safe?" << "\n";
	cin >> max;
	
	srand((unsigned)time(0));
	bool psw0, psw1, psw2, psw3, psw4;
	
	generate_UHF();
	generate_LHF();
	generate_PHF();

	stringstream file_stream;
	int a = 0;

	int i = 1;
	while( i <= max) {
		
		//lock 0
		generate_ROOT();
		generate_CN();
		generate_LN();
		generate_HN();
		psw0 = password_validation();
		//lock 1
		nextlock_CN();
		generate_LN();
		generate_HN();
		psw1 = password_validation();
		//lock 2
		nextlock_CN();
		generate_LN();
		generate_HN();
		psw2 = password_validation();
		//lock 3
		nextlock_CN();
		generate_LN();
		generate_HN();
		psw3 = password_validation();
		//lock 4
		nextlock_CN();
		generate_LN();
		generate_HN();
		psw4 = password_validation();

		if (psw0 && psw1 && psw2 && psw3 && psw4) {
		
			file_stream << "ROOT " << ROOT[0] << ROOT[1] << ROOT[2] << ROOT[3] << "\n";
			file_stream << "UHF " << showpos << UHF[0] << ',' << UHF[1] << ',' << UHF[2] << ',' << UHF[3] << noshowpos << "\n";
			file_stream << "LHF " << showpos << LHF[0] << ',' << LHF[1] << ',' << LHF[2] << ',' << LHF[3] << noshowpos << "\n";
			file_stream << "PHF " << showpos << PHF[0] << ',' << PHF[1] << ',' << PHF[2] << ',' << PHF[3] << noshowpos << "\n";
			a++;
		}
		i++;
	} 


	ofstream file("key.txt");
	if (file.is_open()) {
		file << "NS " << a << "\n";
		file << file_stream.str();
	}
	file.close();

	if (a >= 0)
		cout << "You find " << a << " solutions" << "\n";
	else
		cout << "0 solutions" << "\n";

	ifstream fileIn("key.txt");
	ofstream fileOut("multi-safe.txt");
	string data;
	int total;
	string root, uhf, lhf, phf;
	if (fileOut.is_open() && fileIn.is_open()) {
		fileIn >> data >> total;
		for (int b = 0; b < total; b++) {

			fileIn >> data >> root;
			fileIn >> data >> uhf;
			fileIn >> data >> lhf;
			fileIn >> data >> phf;

			for (int i = 0; i < 4; i++)
				ROOT[i] = root[i] - '0';

			for (int i = 0; i < 4; i++) {
				if (uhf[i * 3] == '+')
					UHF[i] = uhf[i * 3 + 1] - '0';
				else
					UHF[i] = -(uhf[i * 3 + 1] - '0');
			}

			for (int i = 0; i < 4; i++) {
				if (lhf[i * 3] == '+')
					LHF[i] = lhf[i * 3 + 1] - '0';
				else
					LHF[i] = -(lhf[i * 3 + 1] - '0');
			}

			for (int i = 0; i < 4; i++) {

				if (phf[i * 3] == '+')
					PHF[i] = phf[i * 3 + 1] - '0';
				else
					PHF[i] = -(phf[i * 3 + 1] - '0');
			}
			
			stringstream fileIn_stream;
			//lock 0
			generate_CN();
			generate_LN();
			generate_HN();
			fileIn_stream << "CN" << 0 << ' ' << CN[0] << CN[1] << CN[2] << CN[3] << ',' << " LN" << 0 << ' ' << LN[0] << LN[1] << LN[2] << LN[3] << ',' << " HN" << 0 << ' ' << HN[0] << HN[1] << HN[2] << HN[3] << "\n";
			psw0 = password_validation();

			//lock 1
			nextlock_CN();
			generate_LN();
			generate_HN();
			fileIn_stream << "CN" << 1 << ' ' << CN[0] << CN[1] << CN[2] << CN[3] << ',' << " LN" << 1 << ' ' << LN[0] << LN[1] << LN[2] << LN[3] << ',' << " HN" << 1 << ' ' << HN[0] << HN[1] << HN[2] << HN[3] << "\n";
			psw1 = password_validation();

			//lock 2
			nextlock_CN();
			generate_LN();
			generate_HN();
			fileIn_stream << "CN" << 2 << ' ' << CN[0] << CN[1] << CN[2] << CN[3] << ',' << " LN" << 2 << ' ' << LN[0] << LN[1] << LN[2] << LN[3] << ',' << " HN" << 2 << ' ' << HN[0] << HN[1] << HN[2] << HN[3] << "\n";
			psw2 = password_validation();

			//lock 3
			nextlock_CN();
			generate_LN();
			generate_HN();
			fileIn_stream << "CN" << 3 << ' ' << CN[0] << CN[1] << CN[2] << CN[3] << ',' << " LN" << 3 << ' ' << LN[0] << LN[1] << LN[2] << LN[3] << ',' << " HN" << 3 << ' ' << HN[0] << HN[1] << HN[2] << HN[3] << "\n";
			psw3 = password_validation();

			//lock 4
			nextlock_CN();
			generate_LN();
			generate_HN();
			fileIn_stream << "CN" << 4 << ' ' << CN[0] << CN[1] << CN[2] << CN[3] << ',' << " LN" << 4 << ' ' << LN[0] << LN[1] << LN[2] << LN[3] << ',' << " HN" << 4 << ' ' << HN[0] << HN[1] << HN[2] << HN[3] << "\n";
			psw4 = password_validation();

			if (psw0 && psw1 && psw2 && psw3 && psw4)
				fileOut << "NS" << b << " VALID" << "\n";
			else
				fileOut << "NS" << b << " NOT VALID" << "\n";

			fileOut << fileIn_stream.str();
		}
	}
	fileIn.close();
	fileOut.close();
	return 0;
}
