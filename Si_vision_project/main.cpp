/**********************************************************************************************/
/************ File Name  : main.cpp                                      **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

extern uint16_t Gates_Num = 0;
extern uint16_t Nodes_Num = 0;
extern uint16_t out_nodes = 0;

std::ostream& operator<<(std::ostream& out, Node*& out_node)
{
out<< (out_node->name)<<": "<<(out_node->value)<<endl;
return out;
}

int main()
{
    GateGenerator Circuit;
    Circuit.parseInput();
    return 0;
}
