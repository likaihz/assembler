#include<string>
#include<iostream>
#include<sstream>
#include<bitset>
using namespace std;

string Turn_5_Bin(string imm)
{

	string res;
	int value;
	stringstream stream;
	stream << imm;
	stream >> value;
	bitset<5>tmp;
	tmp = value;
	res = tmp.to_string();
	return res;

}

string Turn_26_Bin(string imm)
{
	string res;
	int value;
	stringstream stream;
	stream << imm;
	stream >> value;
	bitset<26>tmp;
	tmp = value;
	res = tmp.to_string();
	return res;

}

string SignExtend16(string imm)
{
	string res;
	int value;
	stringstream stream;
	stream << imm;
	stream >> value;
//	if (value >= 32768 || value < -32768)
		//return NULL;
	bitset<16>tmp;
	tmp = value;
	res = tmp.to_string();
	return res;
}

string ZeroExtend16(string imm)
{
	string res;
	int value;
	stringstream stream;
	stream << imm;
	stream >> value;
	if (value < 0 && value >= -32768)
		value += 65536;
	bitset<16>tmp;
	tmp = value;
	res = tmp.to_string();
	return res;
}
