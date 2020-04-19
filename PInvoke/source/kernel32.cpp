#pragma comment (lib, "kernel32.lib")
#include <marshal.hpp>
#include <kernel32.hpp>

namespace P
{
  namespace PInvoke
  {
    INT Kernel32::GetPrivateProfileInt(String^ appName, String^ keyName, INT default, String^ fileName)
    {
      return ::GetPrivateProfileInt(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), default, StrToChar(LPCTSTR, fileName));
    }

    List<String^>^ Kernel32::GetPrivateProfileSection(String^ appName, String^ fileName)
    {
      return GetString(appName, nullptr, nullptr, fileName);
    }

    List<String^>^ Kernel32::GetPrivateProfileSectionNames(String^ fileName)
    {
      return GetString(nullptr, nullptr, nullptr, fileName);
    }

    List<String^>^ Kernel32::GetPrivateProfileString(String^ appName, String^ keyName, String^ default, String^ fileName)
    {
      return GetString(appName, keyName, default, fileName);
    }

    generic <typename T> bool Kernel32::GetPrivateProfileStruct(String^ section, String^ key, T% object, String^ file)
    {
      auto p = Marshal::AllocHGlobal(Marshal::SizeOf<T>());
      auto ret = ::GetPrivateProfileStruct(StrToChar(LPCTSTR, section), StrToChar(LPCTSTR, key), p.ToPointer(), Marshal::SizeOf<T>(), StrToChar(LPCTSTR, file));
      object = Marshal::PtrToStructure<T>(p);
      Marshal::FreeHGlobal(p);
      return ret;
    }

    INT Kernel32::GetProfileInt(String^ appName, String^ keyName, INT default)
    {
      return ::GetProfileInt(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), default);
    }

    List<String^>^ Kernel32::GetProfileString(String^ appName, String^ keyName, String^ default)
    {
      return GetString(appName, keyName, default, nullptr);
    }

    bool Kernel32::WritePrivateProfileSection(String^ appName, String^ string, String^ fileName)
    {
      return ::WritePrivateProfileSection(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, string), StrToChar(LPCTSTR, fileName));
    }

    bool Kernel32::WritePrivateProfileString(String^ appName, String^ keyName, String^ string, String^ fileName)
    {
      return ::WritePrivateProfileString(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), StrToChar(LPCTSTR, string), StrToChar(LPCTSTR, fileName));
    }

    generic <typename T> bool Kernel32::WritePrivateProfileStruct(String^ section, String^ key, T object, String^ file)
    {
      auto p = Marshal::AllocHGlobal(Marshal::SizeOf<T>());
      Marshal::StructureToPtr<T>(object, p, false);
      auto ret = ::WritePrivateProfileStruct(StrToChar(LPCTSTR, section), StrToChar(LPCTSTR, key), p.ToPointer(), Marshal::SizeOf<T>(), StrToChar(LPCTSTR, file));
      Marshal::FreeHGlobal(p);
      return ret;
    }

    bool Kernel32::WriteProfileSection(String^ appName, String^ string)
    {
      return ::WriteProfileSection(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, string));
    }

    bool Kernel32::WriteProfileString(String^ appName, String^ keyName, String^ string)
    {
      return ::WriteProfileString(StrToChar(LPCTSTR, appName), StrToChar(LPCTSTR, keyName), StrToChar(LPCTSTR, string));
    }

    List<String^>^ Kernel32::GetString(String^ appName, String^ keyName, String^ default, String^ fileName)
    {
      auto ret = gcnew List<String^>();
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
          auto s = (String^)"\0";
          if (p[0] != '\0')
          {
            s = CharToStr(String^, p);
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