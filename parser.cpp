#include <iostream>
#include <clang-c/Index.h>
using namespace std;

int main()
{
  CXIndex index = clang_createIndex(0, 0);
  CXTranslationUnit unit = clang_parseTranslationUnit(index, "example.h", nullptr, 0, nullptr, 0, CXTranslationUnit_None);
  if (unit == nullptr)
  {
    cout << "Unable to parse translation unit. Quitting." << endl;
    exit(-1);
  }

  CXCursor cursor = clang_getTranslationUnitCursor(unit);
  clang_visitChildren(cursor,[](CXCursor c, CXCursor parent, CXClientData client_data)
    {
        if (clang_getCursorKindSpelling(clang_getCursorKind(c))=='CXXMethod')
        {
            cout << clang_getCursorSpelling(c) << endl;
        }
      return CXChildVisit_Recurse;
    },
    nullptr);
  clang_disposeTranslationUnit(unit);
  clang_disposeIndex(index);
}
