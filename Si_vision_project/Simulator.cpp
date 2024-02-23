/**********************************************************************************************/
/************ File Name  : Simulator.cpp                                 **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

#include "Simulator.h"

    Simulator::Simulator()
    {
    apGate[0] = (new Gate);
    apNode[0] = (new Node);
    }

    Node** Simulator::getapNode(void)
	{
		return apNode;
	}
	
    void Simulator::postGate(Gate* pnewGate)
    {
		apGate[Gate_arrIndex] = pnewGate;
		Gate_arrIndex++;
    }
	
    void Simulator::postNode(Node* pnewNode)
    {
		apNode[Node_arrIndex] = pnewNode;
		Node_arrIndex++;
    }
	
    Node* Simulator::FindNode(const string& node_nameCpy)
    {
    //search for node in the array
		uint16_t i;
		Node* paNodeLOC = 0;
		for(i = 0; i< Nodes_Num ; i++ )
		{
		if((apNode[i]->getName()) == node_nameCpy )
		{
		paNodeLOC = apNode[i];
		break;
		}else
		{
		paNodeLOC = 0;
		}
		}
		return paNodeLOC;
    }
	
    void Simulator::startSimulate(void)
    {
		uint8_t u8CounterLOC;
		for(u8CounterLOC = 0; u8CounterLOC < Gates_Num ;u8CounterLOC++)
		{
		apGate[u8CounterLOC]->simulateGate();
		}
    }
	
    Simulator::~Simulator()
    {
        uint8_t u8CounterLOC;

        for(u8CounterLOC = 0 ; u8CounterLOC < Nodes_Num ;u8CounterLOC++)
        {
            apNode[u8CounterLOC]->~Node();
            delete  apNode[u8CounterLOC];
        }

        for(u8CounterLOC = 0 ;u8CounterLOC < Gates_Num ; u8CounterLOC++)
        {
            apGate[u8CounterLOC]->~Gate();
            delete apGate[u8CounterLOC];
        }
    }
