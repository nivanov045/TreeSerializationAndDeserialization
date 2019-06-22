#include "Node.h"
#include <iostream>
#include "Serializator.h"

int main(int argc, char* argv[])
{
  IntNode* rootNode = new IntNode(8);
  StringNode* bar = new StringNode("bar");
  StringNode* bar2 = new StringNode("bar2");
  rootNode->AddNode(bar);
  rootNode->AddNode(bar2);
  DoubleNode* twoD = new DoubleNode(2.019);
  bar->AddNode(twoD);
  bar->AddNode(new IntNode(2019));
  bar->AddNode(new StringNode("2019"));
  twoD->AddNode(new IntNode(9));
  bar2->AddNode(new StringNode("foo"));
  DoubleNode* sixD = new DoubleNode(6.28318);
  bar2->AddNode(sixD);
  sixD->AddNode(new StringNode("hello"));
  
  try {
    Serializator ser;
    ser.SetOutputFile("input.txt");
    ser.Serialize(*rootNode);
    ser.SetInputFile("input.txt");
    Node *nodeResult = ser.Deserialize();
    ser.SetOutputFile("output.txt");
    ser.Serialize(*nodeResult);
  } catch (...) {
    system("pause");
    return 1;
  }
  return 0;
}
