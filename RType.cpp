/*---------------------------------------------


have been tested!


-----------------------------------------------*/

#include<string>
#include<iostream>
#include"ir.h"

using namespace std;
string R_type(int head,string ins)
{
	int ir_No,i,cnt = -1;
	string ir;
	string tmp, reg[3] = {"","",""};
	ir = ins.substr(head, ins.find(' ') - head);
	for (ir_No = 0; ir_No < IR_QUANTITY; ir_No++)
		if (ir == ir_set[ir_No])	break;
	for (i = ins.find(' '); i <= ins.length(); i++)
	{
		if (ins[i] == '$')
		{
			cnt++;
			while (ins[i] != ',' && i <= ins.length())
				reg[cnt] += ins[i++];
		}
	}
	switch (ir_No)
	{
	case 0: return "000000" + Reg_Num(reg[1]) + Reg_Num(reg[2]) + Reg_Num(reg[0]) + "00000" + "100000";		//add
	case 1: return "000000" + Reg_Num(reg[1]) + Reg_Num(reg[2]) + Reg_Num(reg[0]) + "00000" + "100010";		//sub
	case 2: return "000000" + Reg_Num(reg[1]) + Reg_Num(reg[2]) + Reg_Num(reg[0]) + "00000" + "100100";		//and
	case 3: return "000000" + Reg_Num(reg[1]) + Reg_Num(reg[2]) + Reg_Num(reg[0]) + "00000" + "100101";		//or
	case 4: return "000000" + Reg_Num(reg[1]) + Reg_Num(reg[2]) + Reg_Num(reg[0]) + "00000" + "101010";		//slt
/*	case 5: return "00000000000" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + Turn_5_Bin(reg[2]) + "000000";		//sll
	case 6: return "00000000000" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + Turn_5_Bin(reg[2]) + "000010";		//srl
	case 7: return "00000000000" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + Turn_5_Bin(reg[2]) + "000011";		//sra*/
	}
	

}

string R_type2(int head, string ins)
{
	int ir_No, i, cnt = -1;
	string ir;
	string tmp, reg[2] = { "", ""},imm="";
	ir = ins.substr(head, ins.find(' ') - head);
	for (ir_No = 0; ir_No < IR_QUANTITY; ir_No++)
		if (ir == ir_set[ir_No])	break;
	//cout << ir_No << endl;
	for (i = ins.find(' '); i <= ins.length(); i++)
	{
		if (ins[i] == '$')
		{
			cnt++;
			while (ins[i] != ',' && i <= ins.length())
				reg[cnt] += ins[i++];
		}
	}
	for (i = ins.rfind(','); i <= ins.length(); i++)
	{
		//cout << ins[i]<<ins[i-2] << endl;

		if (ins[i] >= '0'&&ins[i] <= '9' && (ins[i - 2] != '$'))
		{
			//cout << ins[i] << endl;
			for (; i <= ins.length(); i++)
				imm += ins[i];
			break;
		}
	}
	//cout << Turn_5_Bin(imm) << endl;
	//cout << "here" << endl;
	switch (ir_No)
	{
	case 5: return "00000000000" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + Turn_5_Bin(imm) + "000000";		//sll
	case 6: return "00000000000" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + Turn_5_Bin(imm) + "000010";		//srl
	case 7: return "00000000000" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + Turn_5_Bin(imm) + "000011";		//sra
	}
}