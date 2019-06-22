#include "Node.h"
#include <iostream>
#include "Serializator.h"

int main(int argc, char* argv[])
{
  StringNode node("node_0");
  DoubleNode node1(1.2);
  node.AddNode(&node1);
  node.AddNode(new DoubleNode(1.3));
  node1.AddNode(new IntNode(144));
  //std::cout << node.Serialize();
  Serializator ser("input.txt", "output.txt");
  ser.Serialize(node);
  //system("pause");
}
