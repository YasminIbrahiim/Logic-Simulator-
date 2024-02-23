/**********************************************************************************************/
/************ File Name  : Simulator.h                                   **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/
#ifndef  SIMULATOR_H
#define  SIMULATOR_H

class Simulator
{
private:
    Gate* apGate[100];
    Node* apNode[100];
    uint8_t Gate_arrIndex = 0;
    uint8_t Node_arrIndex = 0;

public:
    Simulator();
    Node** getapNode(void);
    void postGate(Gate* pnewGate);
    void postNode(Node* pnewNode);
    Node* FindNode(const string& node_nameCpy);
    void startSimulate(void);
    ~Simulator();
};
#endif