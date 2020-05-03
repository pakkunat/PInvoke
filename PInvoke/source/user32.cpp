#pragma comment (lib, "user32.lib")
#include <marshal.hpp>
#include <user32.hpp>

namespace P
{
  namespace PInvoke
  {
    bool User32::DestroyIcon(System::IntPtr icon)
    {
      return ::DestroyIcon((HICON)icon.ToPointer());
    }
  }
}