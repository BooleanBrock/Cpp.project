
#ifndef DEGREE_HEADER
#define DEGREE_HEADER
#include <string>

enum class DegreeProgram {UNDECIDED, NETWORK, SECURITY, SOFTWARE}; //enum for degree type
//sets output string  for each element in the enumeration
static const std::string degreeTypeStrings[] = { "UNDECIDED", "NETWORK" , "SECURITY" , "SOFTWARE" }; 
#endif