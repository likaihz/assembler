#include<string>
#include<iostream>
#include<sstream>
#include"ir.h"
#include"label.h"

using namespace std;
string J_type(int head, string ins, string l[], int label_locate[])
{
	int i, i_loc;
	string addr="",label="";
	//for (i = ins.rfind(" "); i <= ins.length(); i++)
	i_loc = ins.rfind(' ') + 1;
	if (ins[i_loc] >= '0'&&ins[i_loc] <= '9')
		for (i = ins.rfind(" ") + 1; i < ins.length(); i++)
			addr += ins[i];
	else								/*参数不是相对地址，而是一个label*/
	{
		for (i = ins.rfind(" ") + 1; i < ins.length(); i++)
			label += ins[i];
		for (i = 0; i <= LABEL_AT_MOST; i++)
			if (label == l[i])	break;
		int immi = label_locate[i];			/***********************************************************************/
		ostringstream x;					/**********************************************************************/
		x << immi << endl;					/*********************************************************************/
		addr = x.str();
	}
	return "000010"+Turn_26_Bin(addr);
}