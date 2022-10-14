#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

uint16_t Gates_Num = 0;
uint16_t Nodes_Num = 0;
uint16_t out_nodes= 0;
class Node
{
private:
    std::string name;
    uint16_t value;

public:
    Node():name(""),value(0){}
    Node(const Node& NewNode):name(NewNode.name),value(NewNode.value){}
    string getName(void)
    {
    return name;
    }
    void setName(const string& NodeName )
    {
    name = NodeName ;
    }
    uint16_t getValue(void)
    {
    return value;
    }
    void setValue(const uint16_t& NodeValue )
    {
    value = NodeValue ;
    }
    uint16_t AND(const Node& Node2)
    {
    return((value)&(Node2.value));
    }
    uint16_t OR(const Node& Node2)
    {
    return((value)|(Node2.value));
    }
    uint16_t XOR(const Node& Node2)
    {
    return((value)^(Node2.value));
    }
 ~Node()
   {

   //delete this;
   }
friend std::ostream& operator<<(std::ostream& out, Node*& out_node);

};

  std::ostream& operator<<(std::ostream& out, Node*& out_node)
  {
  out<< (out_node->name)<<": "<<(out_node->value)<<endl;
  return out;
  }
class Gate
{
private:
    std::string GateName;
    Node* node1;
    Node* node2;
    Node* node3;

public:
    Gate(): node1(nullptr),node2(nullptr),node3(nullptr){}
    Gate(Gate& NewGate ): node1(NewGate.node1),node2(NewGate.node2),node3(NewGate.node3){}

    void setNode1(Node* Node1Cpy)
    {
        node1 = Node1Cpy;
    }
    void setNode2(Node* Node2Cpy)
    {
        node2 = Node2Cpy;
    }
    void setNode3(Node* Node3Cpy)
    {
        node3 = Node3Cpy;
    }
    Node* getNode1(void)
    {
        return node1;
    }
    Node* getNode2(void)
    {
        return node2;
    }
    Node* getNode3(void)
    {
        return node3;
    }
    void setGateName(const std::string& GateNameCpy)
    {
    GateName = GateNameCpy;
    }
    std::string& getGateName(void)
    {
    return GateName;
    }
private:
//AND / OR / NAND / NOR / XOR / XNOR / NOT
    uint16_t AND(void)
    {
    node3->setValue(node1->AND(*node2));
    return node3->getValue();
    }
    uint16_t OR(void)
    {
    node3->setValue(node1->OR(*node2));
    return node3->getValue();
    }
    uint16_t NAND(void)
    {
    if((node1->AND(*node2)) == 0)
    {
        node3->setValue(1);
    }else
    {
        node3->setValue(0);
    }

    return node3->getValue();
    }
    uint16_t NOR(void)
    {
    if((node1->OR(*node2)) == 0)
    {
         node3->setValue(1);
    }else
    {
         node3->setValue(0);
    }
    return node3->getValue();
    }
    uint16_t XOR(void)
    {
    node3->setValue(node1->XOR(*node2));
    return node3->getValue();
    }
    uint16_t XNOR(void)
    {
    if((node1->XOR(*node2)) == 0)
    {
    node3->setValue(1);
    }else
    {
    node3->setValue(0);
    }

    return node3->getValue();
    }
    uint16_t NOT(void)
    {
    if( (node1->getValue()) == 0 )
    {
        node2->setValue(1);
    }else
    {
        node2->setValue(0);
    }

    return node2->getValue();
    }

public:
    uint8_t simulateGate(void)
    {
    uint16_t outputValueLOC;
    if(GateName == "AND")
    {
        outputValueLOC =  AND();
    }else if(GateName == "OR")
    {
        outputValueLOC =  OR();
    }else if(GateName == "NAND")
    {
        outputValueLOC = NAND();
    }else if(GateName == "NOR")
    {
        outputValueLOC = NOR();
    }else if(GateName == "XOR")
    {
        outputValueLOC = XOR();
    }else if(GateName == "XNOR")
    {
        outputValueLOC = XNOR();
    }else
    {
        outputValueLOC = NOT();
    }
    return outputValueLOC;
    }

    ~Gate(){}

};

class Simulator
{
private:
    Gate* apGate[100];
    Node* apNode[100];
    uint8_t Gate_arrIndex = 0;
    uint8_t Node_arrIndex = 0;

public:
    Simulator()
    {
    apGate[0] = (new Gate);
    apNode[0] = (new Node);
    }

    Node** getapNode(void)
    {
    return apNode;
    }
    void postGate(Gate* pnewGate)
    {
    apGate[Gate_arrIndex] = pnewGate;
    Gate_arrIndex++;
    }
    void postNode(Node* pnewNode)
    {
    apNode[Node_arrIndex] = pnewNode;
    Node_arrIndex++;
    }
    Node* FindNode(const string& node_nameCpy)
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
    void startSimulate(void)
    {
    uint8_t u8CounterLOC;
    for(u8CounterLOC = 0; u8CounterLOC < Gates_Num ;u8CounterLOC++)
    {
    apGate[u8CounterLOC]->simulateGate();
    }
    }
    ~Simulator()
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
};

class GateGenerator
{
private:
Simulator SimObj;

public:

    void parseInput(void)
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

    Node* createNode(string NodeNameCpy)
    {
    Node* New_node = new Node;
    New_node->setName(NodeNameCpy);
    Nodes_Num++;
    return New_node ;
    }
    Gate* createGate(string GateNameCpy , Node*& Node1Cpy , Node*& Node2Cpy , Node*& Node3Cpy)
    {
    Gate* New_Gate = new Gate;
    New_Gate->setGateName(GateNameCpy);
    New_Gate->setNode1(Node1Cpy);
    New_Gate->setNode2(Node2Cpy);

    New_Gate->setNode3(Node3Cpy);
    Gates_Num++;
    return New_Gate;
    }
    ~GateGenerator(){}

};



int main()
{
    GateGenerator Circuit;
    Circuit.parseInput();
    return 0;
}
