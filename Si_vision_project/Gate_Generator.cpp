/**********************************************************************************************/
/************ File Name  : Gate_Generator.cpp                            **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

#include "Gate_Generator.h"

    void GateGenerator::parseInput(void)
    {
		string readInput    ;
		string GateNameLOC  ;
		string Node1_NameLOC  ;
		string Node2_NameLOC  ;
		string Node3_NameLOC  ;
		string Node_NameLOC ;
		uint16_t Node_valueLOC ;
		Node* pNode1_LOC;
		Node* pNode2_LOC;
		Node* pNode3_LOC;
		Gate* pGateLOC;
		std::string OutNode[100];
		cin >> readInput ;

		while(readInput != "ALL")
		{
		if((readInput == "AND")||(readInput == "OR")||
		(readInput == "NAND")||(readInput == "NOR")||
		(readInput == "XOR")||(readInput == "XNOR"))
		{
			GateNameLOC = readInput;
			cin >> Node1_NameLOC ;
			cin >> Node2_NameLOC ;
			cin >> Node3_NameLOC ;
		
			if(SimObj.FindNode(Node1_NameLOC) == 0)
			{
				pNode1_LOC = createNode(Node1_NameLOC);
				SimObj.postNode(pNode1_LOC);
			}else
			{
		
				pNode1_LOC = SimObj.FindNode(Node1_NameLOC);
			}
		
			if(SimObj.FindNode(Node2_NameLOC) == 0)
			{
		
				pNode2_LOC = createNode(Node2_NameLOC);
				SimObj.postNode(pNode2_LOC);
			}else
			{
				pNode2_LOC = SimObj.FindNode(Node2_NameLOC);
			}
	
			if(SimObj.FindNode(Node3_NameLOC) == 0)
			{
		
				pNode3_LOC = createNode(Node3_NameLOC);
				SimObj.postNode(pNode3_LOC);
			}else
			{
				pNode3_LOC = SimObj.FindNode(Node3_NameLOC);
			}
			pGateLOC = createGate(GateNameLOC , pNode1_LOC ,pNode2_LOC , pNode3_LOC);
			SimObj.postGate(pGateLOC);
	
		}else if(readInput == "NOT")
		{
			GateNameLOC = readInput;
			cin >> Node1_NameLOC ;
			cin >> Node2_NameLOC ;
	
			if(SimObj.FindNode(Node1_NameLOC) == 0)
			{
				pNode1_LOC = createNode(Node1_NameLOC);
				SimObj.postNode(pNode1_LOC);
			}else
			{
				pNode1_LOC = SimObj.FindNode(Node1_NameLOC);
			}
			if(SimObj.FindNode(Node2_NameLOC) == 0)
			{
				pNode2_LOC = createNode(Node2_NameLOC);
				SimObj.postNode(pNode2_LOC);
			}else
			{
				pNode2_LOC = SimObj.FindNode(Node2_NameLOC);
			}
		
			pNode3_LOC = 0;
		
			pGateLOC = createGate(GateNameLOC , pNode1_LOC ,pNode2_LOC , pNode3_LOC);
			SimObj.postGate(pGateLOC);
		}
	
		if(readInput == "SET")
		{
			uint8_t u8CounterLOC;
			Node* ptrNode;
			cin >> Node_NameLOC ;
			cin >> Node_valueLOC;
	
			for(u8CounterLOC = 0; u8CounterLOC< 3; u8CounterLOC++ )
			{
				ptrNode = SimObj.FindNode(Node_NameLOC);
				ptrNode->setValue(Node_valueLOC);
			}
		}
	
		if(readInput == "SIM")
		{
			SimObj.startSimulate();
		}
	
		if(readInput == "OUT")
		{
			uint8_t u8CounterLOC;
			Node* pNodeLOC;
			Node** paNodeLOC;
			cin >>readInput;
	
			if(readInput == "ALL")
			{
				for(u8CounterLOC = 0; u8CounterLOC < out_nodes ; u8CounterLOC++ )
				{
					pNodeLOC = SimObj.FindNode(OutNode[u8CounterLOC]);
					cout << pNodeLOC;
				}
	
				for(u8CounterLOC = 0; u8CounterLOC < Nodes_Num ; u8CounterLOC++ )
				{
					paNodeLOC = SimObj.getapNode();
					cout << paNodeLOC[u8CounterLOC];
				}
				continue;
			}else
			{
				OutNode[out_nodes] = readInput;
				out_nodes++;
			}
		}
		cin >> readInput ;
		}
    }

    Node* GateGenerator::createNode(string NodeNameCpy)
    {
		Node* New_node = new Node;
		New_node->setName(NodeNameCpy);
		Nodes_Num++;
		return New_node ;
    }
	
    Gate* GateGenerator::createGate(string GateNameCpy , Node*& Node1Cpy , Node*& Node2Cpy , Node*& Node3Cpy)
    {
		Gate* New_Gate = new Gate;
		New_Gate->setGateName(GateNameCpy);
		New_Gate->setNode1(Node1Cpy);
		New_Gate->setNode2(Node2Cpy);
		New_Gate->setNode3(Node3Cpy);
		Gates_Num++;
		return New_Gate;
    }
    GateGenerator::~GateGenerator(){}

