/**********************************************************************************************/
/************ File Name  : Gate_Generator.h                              **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

#ifndef   GATE_GENERATOR_H
#define   GATE_GENERATOR_H

class GateGenerator
{
private:
	Simulator SimObj;

public:
    void parseInput(void);
    Node* createNode(string NodeNameCpy);
    Gate* createGate(string GateNameCpy , Node*& Node1Cpy , Node*& Node2Cpy , Node*& Node3Cpy);
    ~GateGenerator();
};

#endif