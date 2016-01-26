#include<string>
#include<iostream>
#include<fstream>
#include"ir.h"
using namespace std;

string Reg_Num(string reg_name)
{
	switch (reg_name[1])
	{
	case 'a':
		switch (reg_name[2])
		{
		case 't': return "00001";
		case '0': return "00100";
		case '1': return "00101";
		case '2': return "00110";
		case '3': return "00111";
		}
	case 'f': return "11110";
	case 'g': return "11100";
	case 'k':
	{
		if (reg_name[2] == '0') return "11010";
		else return "11011";
	}
	case 'r': return "11111";
	case 's':
		switch (reg_name[2])
		{
		case '0': return "10000";
		case '1': return "10001";
		case '2': return "10010";
		case '3': return "10011";
		case '4': return "10100";
		case '5': return "10101";
		case '6': return "10110";
		case '7': return "10111";
		case 'p': return "11101";
		}
	case 't':
		switch (reg_name[2])
		{
		case '0': return "01000";
		case '1': return "01001";
		case '2': return "01010";
		case '3': return "01011";
		case '4': return "01100";
		case '5': return "01101";
		case '6': return "01110";
		case '7': return "01111";
		case '8': return "11000";
		case '9': return "11001";
		}	
	case 'v':
		if (reg_name[2] == '0') return "00010";
		else return "00011";
	case 'z': return "00000";
    default: return "00000";
	}
}