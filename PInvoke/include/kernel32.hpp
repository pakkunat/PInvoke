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
      static INT GetPrivateProfileInt(System::String^ appName, System::String^ keyName, INT default, System::String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilesection
      static System::Collections::Generic::List<System::String^>^ GetPrivateProfileSection(System::String^ appName, System::String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilesectionnames
      static System::Collections::Generic::List<System::String^>^ GetPrivateProfileSectionNames(System::String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilestring
      static System::Collections::Generic::List<System::String^>^ GetPrivateProfileString(System::String^ appName, System::String^ keyName, System::String^ default, System::String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprivateprofilestruct
      generic <typename T> static bool GetPrivateProfileStruct(System::String^ section, System::String^ key, T% object, System::String^ file);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofileinta
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofileintw
      static INT GetProfileInt(System::String^ appName, System::String^ keyName, INT default);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofilestringa
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-getprofilestringw
      static System::Collections::Generic::List<System::String^>^ GetProfileString(System::String^ appName, System::String^ keyName, System::String^ default);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilesectiona
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilesectionw
      static bool WritePrivateProfileSection(System::String^ appName, System::String^ string, System::String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestringa
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestringw
      static bool WritePrivateProfileString(System::String^ appName, System::String^ keyName, System::String^ string, System::String^ fileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestructa
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprivateprofilestructw
      generic <typename T> static bool WritePrivateProfileStruct(System::String^ section, System::String^ key, T object, System::String^ file);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilesectiona
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilesectionw
      static bool WriteProfileSection(System::String^ appName, System::String^ string);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilestringa
      /// https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-writeprofilestringw
      static bool WriteProfileString(System::String^ appName, System::String^ keyName, System::String^ string);

    private:
      static const int MaxBufLen = 1024;

      static System::Collections::Generic::List<System::String^>^ GetString(System::String^ appName, System::String^ keyName, System::String^ default, System::String^ fileName);
    };
  }
}
