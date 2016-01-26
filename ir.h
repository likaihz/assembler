#ifndef _IR_H IR_QUANTITY
#define _IR_H 
//#include<string>

#define IR_QUANTITY 16
using namespace std;
string Reg_Num(string reg_name);
string Reg_Name(string reg_num);
int Get_Type(string ins);
string InsToCode(string ins);
string Turn_5_Bin(string);
string Turn_26_Bin(string);
string R_type(int,string);
string R_type2(int head, string ins);
string I_type1(int,string);
string I_type2(int, string, string l[], int x[]);
string J_type(int head, string ins, string l[], int label_locate[]);
string ZeroExtend16(string);
string SignExtend16(string);
string GetIns_R(string);
string Reg_Name(string arg);
string Turn_Dec(string arg);
string Turn_Dec2(string );
extern string ir_set[IR_QUANTITY];
extern string reg[32];
#endif
