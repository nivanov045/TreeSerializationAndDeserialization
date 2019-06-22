#include <fstream>
#include <sstream>
#include "Serializator.h"

void Serializator::Serialize(const Node& iNode) const
{
  if (_outputFileName.empty())
    throw std::runtime_error("No file for output!");
  std::ofstream output(_outputFileName);
  output << iNode.Serialize();
}

Node* Serializator::Deserialize() const
{
  std::ifstream input(_inputFileName);
  if (!input)
    throw std::runtime_error("No file for input!");
  Node* rootNode = nullptr;
  std::string line;
  if(!getline(input, line))
    throw std::runtime_error("Empty file for deserialization!");
  readNode(line, rootNode);
  Node* currentNode = rootNode;
  bool stepInto = false;
  while (getline(input, line)) {
    std::stringstream ss(line);
    while (ss.peek() == ' ')
      ss.ignore(1);
    switch (ss.peek()) {
    case '{': //new children node
      {
      stepInto = true;
      break;
      }
    case '}': //back to father node
      {
      currentNode = currentNode->GetFather();
      break;
      }
    default:  //node creation
      {
      Node* newNode = nullptr;
      readNode(line, newNode);
      if (stepInto) {
        currentNode->AddNode(newNode);
        stepInto = false;
      } else {
        currentNode->GetFather()->AddNode(newNode);
      }
      currentNode = newNode;
      }
    }
  }
  return rootNode;
}

void Serializator::readNode(std::istream& iStream, Node*& oNode)
//TODO: Add several tests with bad types (string for idType d)
{
  char typeId;
  iStream >> typeId;
  switch (typeId) {
  case 's':
    {
    std::string data;
    iStream >> data;
    oNode = new StringNode(data);
    break;
    }
  case 'd':
    {
    double data;
    iStream >> data;
    oNode = new DoubleNode(data);
    break;
    }
  case 'i':
    {
    int data;
    iStream >> data;
    oNode = new IntNode(data);
    break;
    }
  default:
    {
    throw std::invalid_argument("Unknown typeId in input!");
    };
  }
}

void Serializator::readNode(const std::string& iLine, Node*& oNode)
{
  std::stringstream ss(iLine);
  readNode(ss, oNode);
}
