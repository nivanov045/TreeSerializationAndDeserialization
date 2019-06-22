#pragma once
#include <string>
#include <utility>
#include <vector>

class Node
{
public:
  virtual ~Node() = default;
  void AddNode(Node* iNode)
  {
    iNode->_numOfTabs = _numOfTabs + 1;
    iNode->_father = this;
    _children.push_back(iNode);
  }

  virtual std::string GetNodeAsString() const = 0;
  virtual std::string GetNodeTypeString() const = 0;
  std::string Serialize() const;
  Node* GetFather() const { return _father; }

protected:
  std::vector<Node*> _children;
  Node* _father = nullptr;
  size_t _numOfTabs = 0;
};

class StringNode : public Node
{
public:
  StringNode(std::string iData) : _data(std::move(iData)) {};
  ~StringNode() = default;
  std::string GetNodeAsString() const override { return _data; }
  std::string GetNodeTypeString() const override { return "s"; }
private:
  std::string _data;
};

class DoubleNode : public Node
{
public:
  DoubleNode(double iData) : _data(iData) {};
  ~DoubleNode() = default;
  std::string GetNodeAsString() const override;
  std::string GetNodeTypeString() const override { return "d"; }

private:
  double _data;
  size_t _serializePrecision = 5;
};

class IntNode : public Node
{
public:
  IntNode(int iData) : _data(iData) {};
  ~IntNode() = default;
  std::string GetNodeAsString() const override;
  std::string GetNodeTypeString() const override { return "i"; }

private:
  int _data;
};