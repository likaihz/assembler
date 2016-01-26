#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"ir.h"

using namespace std;
int Disassembler()
{
	ifstream fin("my2.txt");
	ofstream fout("my2.asm");
	string op, rs, rt, rd, sa, func,imm,res;
	if (!fin)
	{
		cout << "The txt file does not exist!" << endl;
		exit(0);
	}
	while (!fin.eof())
	{
		string ins;
		getline(fin, ins);
		cout << ins << endl;
		op = ins.substr(0, 6);
		rs = ins.substr(6, 5);
		rt = ins.substr(11, 5);
	//	cout << rt << endl;
		imm = ins.substr(16, 16);
		if (op == "000000")
		{
			rd = ins.substr(16, 5);
			sa = ins.substr(21, 5);
			func = ins.substr(26, 6);
			if (func == "100000" || func == "100010" || func == "100100" || func == "100101" || func == "101010")
				res = GetIns_R(func) + "\t\t" + Reg_Name(rd) + "," + Reg_Name(rs) + "," + Reg_Name(rt);
			if (func == "000000" || func == "000010" || func == "000011")
			{
			
				res = GetIns_R(func) + "\t\t" + Reg_Name(rd) + "," + Reg_Name(rt) + "," + Turn_Dec(sa);
			}
				
		}
		else if (op == "001000")
			res = "addi\t" + Reg_Name(rt) + "," + Reg_Name(rs) + "," + Turn_Dec(imm);
		else if (op == "001100")
			res = "andi\t" + Reg_Name(rt) + "," + Reg_Name(rs) + "," + Turn_Dec(imm);
		else if (op == "001101")
			res = "ori\t\t" + Reg_Name(rt) + "," + Reg_Name(rs) + "," + Turn_Dec(imm);
		else if (op == "100011")
			res = "lw\t\t" + Reg_Name(rt) + "," + Turn_Dec(imm)+"("+Reg_Name(rs)  + ")";
		else if (op == "101011")
			res = "sw\t\t" + Reg_Name(rt) + "," + Turn_Dec(imm) + "(" + Reg_Name(rs) + ")";
		else if (op == "000100")
			res = "beq\t\t" + Reg_Name(rt) + "," + Reg_Name(rs) + "," + Turn_Dec(imm);
		else if (op == "000101")
			res = "bne\t\t" + Reg_Name(rt) + "," + Reg_Name(rs) + "," + Turn_Dec(imm);
		else if (op == "000010")
		{
			imm = ins.substr(6, 26);
			res = "j\t\t" + Turn_Dec2(imm);
		}
		fout << res << endl;
	}
	fin.close();
	fout.close();
}

string GetIns_R(string op)
{
	if (op == "100000")	return "add";
	else if (op == "100010")	return "sub";
	else if (op == "100100")	return "and";
	else if (op == "100101")	return "or";
	else if (op == "101010")	return "slt";
	else if (op == "000000")	return "sll";
	else if (op == "000010")	return "srl";
	else if (op == "000011")	return "sra";
}

string Reg_Name(string arg)
{
	int i,val=0;
	for (i = 0; i <arg.length() ;++i)
		val = (arg[i] - '0') + val * 2;
	//cout << val << endl;
	return reg[val];
}

string Turn_Dec2(string arg)
{
	/*二进制串转换成十进制串*/
	int i, val = 0;
	string res;
	for (i = 0; i <arg.length() ; ++i)
		val = (arg[i] - '0')+val * 2;
	val = 1000+val*4;
	ostringstream tmp;
	tmp << val;
	res = tmp.str();
	return res;
}


string Turn_Dec(string arg)
{
	/*二进制串转换成十进制串*/
	int i, val = 0;
	string res;
	for (i = 0; i <arg.length(); ++i)
		val = (arg[i] - '0') + val * 2;
	ostringstream tmp;
	tmp << val;
	res = tmp.str();
	return res;
}