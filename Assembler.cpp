/**********************************
可以有空行
可以有空格或者制表符，
	但是制表符不能连续两个及以上。。
LABEL不可以单独成行
***********************************/

#include<string>
#include<iostream>
#include<fstream>
#include"label.h"
using namespace std;

#include"ir.h"
#include"assembler.h"
int Assembler()
{
	string label[LABEL_AT_MOST];
	int i;
	int label_locate[LABEL_AT_MOST], LabelNum;
	int line;
	
	LabelNum = Get_Label(label, label_locate, LABEL_AT_MOST);
	ifstream fin;
	fin.open("my1.asm");
	ofstream fout;
	fout.open("my1.txt");
	fout.close();
	if (!fin)
	{
		cout << "The asm file does not exist!" << endl;
		exit(0);
	}
	while (!fin.eof())
	{
		int head,type;
		string tmp,ir,res = "";
		getline(fin, tmp);
		if (tmp == "")  continue; 
		/*去除空格*/
		for (i = 0; i < tmp.length(); i++)
			if (tmp[i] == ' '|| tmp[i] == '\t')
				tmp.erase(i, 1);
		/*去除空格结束*/
		if (tmp.find(':') >= 0 && tmp.find(':') <= tmp.length())
			head = tmp.find(":")+1;
		else head = 0;
		if (tmp[head] == 'j')
		{
			ir = "j";
			tmp.insert(1, 1, ' ');
		}
												//扩展指令集时需注意！！
		else
		{
			ir = tmp.substr(head, tmp.find("$") - head);
			tmp.insert(tmp.find('$') , 1, ' ');
		}
			
		/*cout << ir << endl;*/
		type = Get_Type(ir);
		switch (type)
		{
		case 0:	res = R_type(head, tmp); break;
		case 1: res = R_type2(head, tmp); break;
		case 2:	res = I_type1(head,tmp); break;
		case 3: res = I_type2(head, tmp,label,label_locate); break;
		case 4:	res = J_type(head, tmp, label, label_locate); break;
		default:
			break;
		}
		cout << res << endl;
		format(res);
	}
	fin.close();
}
