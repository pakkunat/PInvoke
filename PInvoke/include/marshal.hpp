#pragma once
#include <atlstr.h>
#include <./msclr/marshal.h>
#include <./msclr/marshal_atl.h>
#include <./msclr/marshal_cppstd.h>
#include <./msclr/marshal_windows.h>

using namespace msclr::interop;
using namespace System::Runtime::InteropServices;

namespace P
{
#define StrToChar(type, str) ((gcnew marshal_context())->marshal_as<type>(str))
#define CharToStr(type, char) (marshal_as<type>(char))
}