#pragma once
#include <string>
#include <utility>
#include "Node.h"

class Serializator
{
public:
  Serializator() = default;
  Serializator(std::string iInputFileName) : _inputFileName(std::move(iInputFileName)) {}
  Serializator(std::string iInputFileName, std::string iOutputFileName) 
  : _inputFileName(std::move(iInputFileName))
  , _outputFileName(std::move(iOutputFileName)) {}
  ~Serializator() = default;

  void SetInputFile(std::string iInputFileName) { _inputFileName = iInputFileName; }
  void SetOutputFile(std::string iOutputFileName) { _outputFileName = iOutputFileName; }

  void Serialize(const Node& iNode) const;
  Node* Deserialize() const;
  private:
  std::string _inputFileName;
  std::string _outputFileName;
  static void readNode(std::istream& iStream, Node*& oNode);
  static void readNode(const std::string& iStream, Node*& oNode);

};

