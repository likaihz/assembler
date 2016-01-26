#include<string>
#include<iostream>
#include<sstream>
#include"ir.h"
#include"label.h"

using namespace std;
string I_type1(int head,string ins)
{
	string reg[2] = { "", "" }, imm = "";
	string ir;
	int ir_No, i, cnt = -1;
	ir = ins.substr(head, ins.find(" ") - head);
	for (ir_No = 0; ir_No < IR_QUANTITY; ir_No++)
		if (ir == ir_set[ir_No])	break;
	for (i = ins.find(" "); i <= ins.length(); i++)
		if (ins[i] == '$')
		{
			cnt++;
			while (ins[i] != ',' && i <= ins.length())
				reg[cnt] += ins[i++];
		}
	for (i = ins.find(" "); i <= ins.length(); i++)
		if (ins[i] >= '0'&&ins[i] <= '9'&&(ins[i-2] != '$'))
		{
			for (; i <= ins.length(); i++)
				imm += ins[i];
			break;
		}
	/*cout << imm <<"imm"<< endl;*/
	switch (ir_No)
	{
	case 8: return "001000" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + SignExtend16(imm);
	case 9: return "001100" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + ZeroExtend16(imm);
	case 10:return "001101" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + ZeroExtend16(imm);
	case 11:return "100011" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + SignExtend16(imm);
	case 12:return "101011" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + SignExtend16(imm);
	case 13:return "000100" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + SignExtend16(imm);
	case 14:return "000101" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + SignExtend16(imm);
	}
}


string I_type2(int head, string ins,string l[], int label_locate[])
{
	int ir_No, i, cnt = -1,i_loc,lb_loc;
	string ir;
	string reg[2] = { "", "" }, imm = "", label = "";
	ir = ins.substr(head, ins.find(" ") - head);
	for (ir_No = 0; ir_No < IR_QUANTITY; ir_No++)
		if (ir == ir_set[ir_No])	break;
	for (i = ins.find(" "); i <= ins.length(); i++)
		if (ins[i] == '$')
		{
		cnt++;
		while (ins[i] != ',' && i <= ins.length())
			reg[cnt] += ins[i++];
		}
	i_loc = ins.rfind(',') + 1;
	if (ins[i_loc]>='0'&&ins[i_loc]<='9')
		for (i = ins.rfind(",")+1; i < ins.length(); i++)
			imm += ins[i];
	else								/*参数不是相对地址，而是一个label*/
	{
		for (i = ins.rfind(",")+1; i < ins.length(); i++)
			label += ins[i];
		for (i = 0; i <= LABEL_AT_MOST; i++)
			if (label == l[i])	break;
		int immi = label_locate[i];			/***********************************************************************/
		ostringstream x;					/**********************************************************************/
		x << immi << endl;					/*********************************************************************/
		imm = x.str();
	}

	switch (ir_No)
	{
	case 13:return "000100" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + SignExtend16(imm);
	case 14:return "000101" + Reg_Num(reg[1]) + Reg_Num(reg[0]) + SignExtend16(imm);
	}
}