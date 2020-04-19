#pragma once
#include <share.hpp>

namespace P
{
  namespace PInvoke
  {
    public ref class Kernel32
    {
    public:
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofileint
      static INT GetPrivateProfileInt(String^ appName, String^ keyName, INT default, String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilesection
      static List<String^>^ GetPrivateProfileSection(String^ appName, String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilesectionnames
      static List<String^>^ GetPrivateProfileSectionNames(String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilestring
      static List<String^>^ GetPrivateProfileString(String^ appName, String^ keyName, String^ default, String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilestruct
      generic <typename T> static bool GetPrivateProfileStruct(String^ section, String^ key, T% object, String^ file);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofileintw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofileinta
      static INT GetProfileInt(String^ appName, String^ keyName, INT default);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofilestringw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofilestringa
      static List<String^>^ GetProfileString(String^ appName, String^ keyName, String^ default);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilesectionw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilesectiona
      static bool WritePrivateProfileSection(String^ appName, String^ string, String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestringw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestringa
      static bool WritePrivateProfileString(String^ appName, String^ keyName, String^ string, String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestructw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestructa
      generic <typename T> static bool WritePrivateProfileStruct(String^ section, String^ key, T object, String^ file);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilesectionw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilesectiona
      static bool WriteProfileSection(String^ appName, String^ string);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilestringw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilestringa
      static bool WriteProfileString(String^ appName, String^ keyName, String^ string);

    private:
      static const int MaxBufLen = 1024;

      static List<String^>^ GetString(String^ appName, String^ keyName, String^ default, String^ fileName);
    };
  }
}
