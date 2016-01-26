/*************************************************************
int Get_Label():
	分析指令文件，分别将label的内容和所在的位置存入两个表中

*************************************************************/

#include<string>
#include<iostream>
#include<fstream>


using namespace std;
int Get_Label(string label[], int label_locate[], int max_label) 
{
	string my_str = "", tmp = "";
	int cnt_line=0, lbl_num=0;
	int i;
	ifstream fin("my1.asm");
	if (!fin)
	{
		cout << "File does not exist!" << endl;
		exit(0);
	}
	while (!fin.eof())
	{
		getline(fin, my_str);
		if (my_str != "")
			cnt_line++;
		string::iterator it;
		for (it = my_str.begin(); it != my_str.end();)
		{
			if (*it == ' '||*it=='\t')
			{
				my_str.erase(it);
			}
			else
				++it;
		}							/*get rid of the blank space in the statement*/
		if (0 <= my_str.find(":") && my_str.find(":") <= my_str.length())
		{
			tmp = my_str.substr(0, my_str.find(":"));
			label[lbl_num] = tmp;
			label_locate[lbl_num++] = cnt_line - 1;
			tmp = "";
			if (lbl_num >= max_label)
			{
				cout << "Too Many Labels!" << endl;
				exit(0);
			}
		}
	}
	fin.close();
/*	cout << label[0] << endl;
	cout << label_locate[0] << endl;*/
	return lbl_num;
}