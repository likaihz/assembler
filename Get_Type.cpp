/**********************************************
int Get_Type()
功能：根据指令决定机器码的类型；
	参数值为指令的内容；
	返回值为整数，表示不同的格式：
	1：R-type；
	2：I-type1；
	3：I-type2；
	4：J-type；
	-1：错误，在指令集中未找到该条指令。
**********************************************/

/*---------------------------------------------


have been tested!


-----------------------------------------------*/
#include<string>
#include<iostream>
#include"ir.h"

using namespace std;
int Get_Type(string ins)
{
	int i;
	string::iterator it;
	for (it = ins.begin(); it != ins.end();)
	{
		if (*it == ' ')
		{
			ins.erase(it);
		}
		else
			++it;
	}
	for (i = 0; i < IR_QUANTITY; i++)
		if (ins == ir_set[i])	break;
	if (i == IR_QUANTITY)
		return -1;						/*错误码*/
	switch (i)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		return 0;
	case 5:
	case 6:
	case 7:
		return 1;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		return 2;
	case 13:
	case 14:
		return 3;
	case 15:
		return 4;
	}
    
    return 0;
}
