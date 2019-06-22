#include "Tester.h"
#include "Node.h"
#include "Serializator.h"
#include <iostream>

void Tester::RunTests()
{
  EmptyDeserializationFileTest();
  SerializationAndDeserializationTest();
  SerializationTest();
  DeserializationTest();
  WrongTypeIdTest();
  NoFileForDeserializationTest();
}

void Tester::EmptyDeserializationFileTest()
{
  std::cout << std::endl;
  std::cout << "EmptyDeserializationFileTest - ";
  try {
    Serializator ser;
    ser.SetInputFile("TestInputEmpty.txt");
    auto res = ser.Deserialize();
  }
  catch (std::exception& e) {
    if (!strcmp(e.what(), "Empty file for deserialization!"))
      std::cout << "Ok";
    else
      std::cout << "Wrong";
    return;
  }
  std::cout << "Wrong";
}

void Tester::SerializationAndDeserializationTest()
{
  std::cout << std::endl;
  std::cout << "SerializationAndDeserializationTest - ";
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
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout << "Wrong";
    return;
  }
  std::cout << "Ok";
}

void Tester::SerializationTest()
{
  std::cout << std::endl;
  std::cout << "SerializationTest - ";
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
    ser.SetOutputFile("output.txt");
    ser.Serialize(*rootNode);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout << "Wrong";
    return;
  }
  std::cout << "Ok";
}

void Tester::DeserializationTest()
{
  std::cout << std::endl;
  std::cout << "DeserializationTest - ";
  try {
    Serializator ser;
    ser.SetInputFile("TestInputExample.txt");
    Node *nodeResult = ser.Deserialize();
    ser.SetOutputFile("output.txt");
    ser.Serialize(*nodeResult);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout << "Wrong";
    return;
  }
  std::cout << "Ok";
}

void Tester::WrongTypeIdTest()
{
  std::cout << std::endl;
  std::cout << "WrongTypeIdTest - ";
  try {
    Serializator ser;
    ser.SetInputFile("TestInputIncorrect.txt");
    Node *nodeResult = ser.Deserialize();
  }
  catch (std::exception& e) {
    if (!strcmp(e.what(), "Unknown typeId in input!"))
      std::cout << "Ok";
    else
      std::cout << "Wrong";
    return;
  }
  std::cout << "Wrong";
}

void Tester::NoFileForDeserializationTest()
{
  std::cout << std::endl;
  std::cout << "NoFileForDeserializationTest - ";
  try {
    Serializator ser;
    ser.SetInputFile("NoSuchFile.txt");
    Node *nodeResult = ser.Deserialize();
  }
  catch (std::exception& e) {
    if (!strcmp(e.what(), "No file for input!"))
      std::cout << "Ok";
    else
      std::cout << "Wrong";
    return;
  }
  std::cout << "Wrong";

}
