#include <string>
#include <iostream>
#include <fstream>
#include "ir.h"
//#include "label.h"
#include "assembler.h"


using namespace std;
string ir_set[IR_QUANTITY] = {
        "add", "sub", "and", "or", "slt", "sll", "srl", "sra",
        "addi", "andi", "ori", "lw", "sw", "beq", "bne", "j"
};
string reg[32] = {
        "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3",
        "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7",
        "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7",
        "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"
};
int main(void)
{
    /*string lable[LABLE_AT_MOST];*/
    Assembler();
    Disassembler();
    return 0;
}

void format(string ins)
{
    int i;
    static int line=0;
    ofstream fout;
    fout.open("my1.txt", ios::app);
    fout << 1000 + (line++) * 4<<':';
    for (i = 0; i < 4; i++)
        fout << ins.substr(i * 8, 8) << " ";
    fout << "          ";
    fout << ins.substr(0, 6) << " " << ins.substr(6, 5) << " " << ins.substr(11, 5) << " " << ins.substr(16, 5) << " " << ins.substr(21, 5) << " " << ins.substr(26, 6);
    fout << endl;
    fout.close();

}