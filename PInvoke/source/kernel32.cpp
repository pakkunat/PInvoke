#pragma comment (lib, "kernel32.lib")
#include <marshal.hpp>
#include <kernel32.hpp>

using namespace System::Runtime::InteropServices;

namespace P
{
  namespace PInvoke
  {
    INT Kernel32::GetPrivateProfileInt(System::String^ appName, System::String^ keyName, INT default, System::String^ fileName)
    {
      return ::GetPrivateProfileInt(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), default, StrToChar(LPCTSTR, fileName));
    }

    System::Collections::Generic::List<System::String^>^ Kernel32::GetPrivateProfileSection(System::String^ appName, System::String^ fileName)
    {
      return GetString(appName, nullptr, nullptr, fileName);
    }

    System::Collections::Generic::List<System::String^>^ Kernel32::GetPrivateProfileSectionNames(System::String^ fileName)
    {
      return GetString(nullptr, nullptr, nullptr, fileName);
    }

    System::Collections::Generic::List<System::String^>^ Kernel32::GetPrivateProfileString(System::String^ appName, System::String^ keyName, System::String^ default, System::String^ fileName)
    {
      return GetString(appName, keyName, default, fileName);
    }

    generic <typename T> bool Kernel32::GetPrivateProfileStruct(System::String^ section, System::String^ key, T% object, System::String^ file)
    {
      auto p = Marshal::AllocHGlobal(Marshal::SizeOf<T>());
      auto ret = ::GetPrivateProfileStruct(StrToChar(LPCTSTR, section), StrToChar(LPCTSTR, key), p.ToPointer(), Marshal::SizeOf<T>(), StrToChar(LPCTSTR, file));
      object = Marshal::PtrToStructure<T>(p);
      Marshal::FreeHGlobal(p);
      return ret;
    }

    INT Kernel32::GetProfileInt(System::String^ appName, System::String^ keyName, INT default)
    {
      return ::GetProfileInt(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), default);
    }

    System::Collections::Generic::List<System::String^>^ Kernel32::GetProfileString(System::String^ appName, System::String^ keyName, System::String^ default)
    {
      return GetString(appName, keyName, default, nullptr);
    }

    bool Kernel32::WritePrivateProfileSection(System::String^ appName, System::String^ string, System::String^ fileName)
    {
      return ::WritePrivateProfileSection(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, string), StrToChar(LPCTSTR, fileName));
    }

    bool Kernel32::WritePrivateProfileString(System::String^ appName, System::String^ keyName, System::String^ string, System::String^ fileName)
    {
      return ::WritePrivateProfileString(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), StrToChar(LPCTSTR, string), StrToChar(LPCTSTR, fileName));
    }

    generic <typename T> bool Kernel32::WritePrivateProfileStruct(System::String^ section, System::String^ key, T object, System::String^ file)
    {
      auto p = Marshal::AllocHGlobal(Marshal::SizeOf<T>());
      Marshal::StructureToPtr<T>(object, p, false);
      auto ret = ::WritePrivateProfileStruct(StrToChar(LPCTSTR, section), StrToChar(LPCTSTR, key), p.ToPointer(), Marshal::SizeOf<T>(), StrToChar(LPCTSTR, file));
      Marshal::FreeHGlobal(p);
      return ret;
    }

    bool Kernel32::WriteProfileSection(System::String^ appName, System::String^ string)
    {
      return ::WriteProfileSection(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, string));
    }

    bool Kernel32::WriteProfileString(System::String^ appName, System::String^ keyName, System::String^ string)
    {
      return ::WriteProfileString(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), StrToChar(LPCTSTR, string));
    }

    System::Collections::Generic::List<System::String^>^ Kernel32::GetString(System::String^ appName, System::String^ keyName, System::String^ default, System::String^ fileName)
    {
      auto ret = gcnew System::Collections::Generic::List<System::String^>();
      auto loop = true;
      auto i = 0;
      auto b = (LPTSTR)nullptr;
      auto r = 0ul;
      do
      {
        i++;
        b = new TCHAR[MaxBufLen * i];
        r = ::GetPrivateProfileString(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), StrToChar(LPCTSTR, default), b, MaxBufLen * i, StrToChar(LPCTSTR, fileName));
        if (keyName == nullptr && r != MaxBufLen * i - 2)
        {
          loop = false;
        }
        else if (keyName != nullptr && r != MaxBufLen * i - 1)
        {
          loop = false;
        }
        else
        {
          delete[] b;
        }
      } while (loop);
      if (r > 0)
      {
        auto l = r;
        auto p = b;
        do
        {
          auto s = (System::String^)"\0";
          if (p[0] != '\0')
          {
            s = CharToStr(System::String^, p);
            ret->Add(s);
          }
          l -= s->Length;
          p += s->Length;
        } while (l > 0);
      }
      delete[] b;
      return ret;
    }
  }
}