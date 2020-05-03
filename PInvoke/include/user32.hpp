#pragma once
#include <share.hpp>

namespace P
{
  namespace PInvoke
  {
    public ref class User32
    {
    public:
      /// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-destroyicon
      static bool DestroyIcon(System::IntPtr icon);
    };
  }
}
