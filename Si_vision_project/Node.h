/**********************************************************************************************/
/************ File Name  : Node.h                                        **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/
#ifndef  NODE_H
#define  NODE_H

class Node
{
private:
    std::string name;
    uint16_t value;
public:
    Node();
    Node(const Node& NewNode);
    string getName(void);
    void setName(const string& NodeName );
    uint16_t getValue(void);
    void setValue(const uint16_t& NodeValue);
    uint16_t AND(const Node& Node2);
    uint16_t OR(const Node& Node2);
    uint16_t XOR(const Node& Node2);
    ~Node();
	friend std::ostream& operator<<(std::ostream& out, Node*& out_node);
};

#endif