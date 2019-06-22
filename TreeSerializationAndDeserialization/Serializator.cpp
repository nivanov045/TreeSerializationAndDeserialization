#include "Serializator.h"
#include <fstream>

void Serializator::Serialize(const Node& iNode)
{
  if (_outputFileName.empty())
    throw std::runtime_error("No file for output!");
  std::ofstream output(_outputFileName);
  output << iNode.Serialize();
}
