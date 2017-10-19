#pragma once

#include <string>
#include <set>
#include <list>
#include <vector>
namespace AnyCAD{ namespace API{
   typedef std::string String;
   typedef String ParameterId;
   typedef int   ElementId;
   #define  InvalidElementId 0
   typedef std::set<ElementId> ElementIdSet;
   typedef std::vector<String> StringList;
   typedef std::vector<char> CharBuffer;
   typedef std::vector<float> FloatList;
   typedef std::vector<int>  IntList;
   typedef std::vector<unsigned int>  UIntList;
}}
