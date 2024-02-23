/**********************************************************************************************/
/************ File Name  : Node.cpp                                      **********************/ 
/************ Author     : Yasmeen Ibrahim                               **********************/           
/************ Description:                                               **********************/
/**********************************************************************************************/

#include "Node.h"

    Node::Node():name(""),value(0)
	{
		
	}
    Node::Node(const Node& NewNode):name(NewNode.name),value(NewNode.value)
	{
		
	}
    string Node::getName(void)
	{
		return name;
	}
    void Node::setName(const string& NodeName )
	{
		name = NodeName ;
	}
    uint16_t Node::getValue(void)
	{
		return value;
	}
    void Node::setValue(const uint16_t& NodeValue)
	{
		value = NodeValue ;
	}	
    uint16_t Node::AND(const Node& Node2)
	{
		return((value)&(Node2.value));
	}
    uint16_t Node::OR(const Node& Node2) 
	{
		return((value)|(Node2.value));
	}
    uint16_t Node::XOR(const Node& Node2)
	{
		return((value)^(Node2.value));
	}
    Node::~Node()
	{
		/*delete this;*/
	}
	friend std::ostream& operator<<(std::ostream& out, Node*& out_node);
