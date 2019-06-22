#include <iostream>
#include "Tester.h"
#include "Serializator.h"

static void PrintUsage()
{
  std::cout << "Use" << std::endl <<
    "  -i to set input file," << std::endl <<
    "  -o to set output file," << std::endl <<
    "  -h to show this help." << std::endl <<
    "For example, TreeSerializationAndDeserialization.exe -i input.txt -o output.txt" << std::endl;
}

int main(int argc, char* argv[])
{
  if (argc < 2) {
    PrintUsage();
    return 1;
  }
  Serializator ser;
  for (int argNum = 1; argNum < argc; ) {
    if (!strcmp(argv[argNum], "-i") && argNum + 1 != argc) {
      ser.SetInputFile(argv[argNum + 1]);
      argNum += 2;
    }
    else if (!strcmp(argv[argNum], "-o") && argNum + 1 != argc) {
      ser.SetOutputFile(argv[argNum + 1]);
      argNum += 2;
    }
    else {
      PrintUsage();
      return 1;
    }
  }

  try {
    const auto node = ser.Deserialize();
    std::cout << node->Serialize();
    ser.Serialize(*node);
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  /*Tester tester;
  tester.RunTests();*/
  return 0;
}
