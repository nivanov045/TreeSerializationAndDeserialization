#include "Node.h"
#include <sstream>
#include <iomanip>

std::string Node::Serialize() const
{
  std::stringstream result;
  for (size_t i = 0; i < numOfTabs; ++i)
    result << "  ";
  result << GetNodeTypeString() << ' ' << GetNodeAsString();
  if (!_children.empty()) {
    result << ':' << std::endl;
    for (size_t i = 0; i < numOfTabs; ++i)
      result << "  ";
    result << '{' << std::endl;
    for (const auto& c : _children)
      result << c->Serialize();
    for (size_t i = 0; i < numOfTabs; ++i)
      result << "  ";
    result << "}";
  } 
  result << ',' << std::endl;
  return result.str();
}

std::string DoubleNode::GetNodeAsString() const
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(_serializePrecision) <<_data;
  return ss.str();
}

std::string IntNode::GetNodeAsString() const {
  std::stringstream ss;
  ss << _data;
  return ss.str();
}
