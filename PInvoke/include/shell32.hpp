#pragma once
#include <share.hpp>
#include <shlobj.h>

namespace P
{
  namespace PInvoke
  {
    public ref class Shell32
    {
    public:
      enum class GilReturn
      {
        SimulateDoc = GIL_SIMULATEDOC,
        PerInstance = GIL_PERINSTANCE,
        PerClass = GIL_PERCLASS,
        NotFileName = GIL_NOTFILENAME,
        DontCache = GIL_DONTCACHE,
        Shield = GIL_SHIELD,
        ForceNoShield = GIL_FORCENOSHIELD
      };

      /// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-duplicateicon
      static System::IntPtr DuplicateIcon(System::IntPtr icon);

      /// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-extractassociatedicona
      /// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-extractassociatediconw
      static System::IntPtr ExtractAssociatedIcon(System::String^ iconPath, WORD% icon);

      /// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-extracticona
      /// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-extracticonw
      static System::Collections::Generic::List<System::IntPtr>^ ExtractIcon(System::String^ exeFileName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-extracticonexa
      /// https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-extracticonexw
      static System::Collections::Generic::List<System::Tuple<System::IntPtr, System::IntPtr>^>^ ExtractIconEx(System::String^ file);

      /// https://docs.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shdefextracticona
      /// https://docs.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shdefextracticonw
      static HResult SHDefExtractIcon(System::String^ iconFile, int index, GilReturn flags, System::IntPtr% iconLarge, System::IntPtr% iconSmall, UINT iconLargeSize, UINT iconSmallSize);
    };
  }
}
