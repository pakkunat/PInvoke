#pragma once
#include <atlstr.h>
#include <./msclr/marshal.h>
#include <./msclr/marshal_atl.h>
#include <./msclr/marshal_cppstd.h>
#include <./msclr/marshal_windows.h>

namespace P
{
#define StrToChar(type, str) ((gcnew msclr::interop::marshal_context())->marshal_as<type>(str))
#define CharToStr(type, char) (msclr::interop::marshal_as<type>(char))
#define GetHInst(idx) ((HINSTANCE)System::Runtime::InteropServices::Marshal::GetHINSTANCE(System::Reflection::Assembly::GetEntryAssembly()->GetModules()[idx]).ToPointer())
}