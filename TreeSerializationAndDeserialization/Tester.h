#pragma once
class Tester
{
public:
  Tester() = default;
  ~Tester() = default;

  void RunTests();

private:
  void EmptyDeserializationFileTest();
  void SerializationAndDeserializationTest();
  void SerializationTest();
  void DeserializationTest();
  void WrongTypeIdTest();
  void NoFileForDeserializationTest();
};

