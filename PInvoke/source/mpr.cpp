#pragma comment (lib, "mpr.lib")
#include <marshal.hpp>
#include <mpr.hpp>

namespace P
{
  namespace PInvoke
  {
    Ret Mpr::WNetAddConnection(String^ remoteName, String^ password, String^ localName)
    {
      return (Ret)::WNetAddConnection(StrToChar(LPCTSTR, remoteName), StrToChar(LPCTSTR, password), StrToChar(LPCTSTR, localName));
    }

    Ret Mpr::WNetAddConnection2(NetResource^ netResource, String^ password, String^ userName, Connect flags)
    {
      ::NETRESOURCE nr;
      nr.dwScope = (DWORD)netResource->Scope;
      nr.dwType = (DWORD)netResource->Type;
      nr.dwDisplayType = (DWORD)netResource->DisplayType;
      nr.dwUsage = (DWORD)netResource->Usage;
      nr.lpLocalName = StrToChar(LPTSTR, netResource->LocalName);
      nr.lpRemoteName = StrToChar(LPTSTR, netResource->RemoteName);
      nr.lpComment = StrToChar(LPTSTR, netResource->Comment);
      nr.lpProvider = StrToChar(LPTSTR, netResource->Provider);
      return (Ret)::WNetAddConnection2(&nr, StrToChar(LPCTSTR, password), StrToChar(LPCTSTR, userName), (DWORD)flags);
    }

    Ret Mpr::WNetAddConnection3(IntPtr wndOwner, NetResource^ netResource, String^ password, String^ userName, Connect flags)
    {
      ::NETRESOURCE nr;
      nr.dwScope = (DWORD)netResource->Scope;
      nr.dwType = (DWORD)netResource->Type;
      nr.dwDisplayType = (DWORD)netResource->DisplayType;
      nr.dwUsage = (DWORD)netResource->Usage;
      nr.lpLocalName = StrToChar(LPTSTR, netResource->LocalName);
      nr.lpRemoteName = StrToChar(LPTSTR, netResource->RemoteName);
      nr.lpComment = StrToChar(LPTSTR, netResource->Comment);
      nr.lpProvider = StrToChar(LPTSTR, netResource->Provider);
      return (Ret)::WNetAddConnection3((HWND)wndOwner.ToPointer(), &nr, StrToChar(LPCTSTR, password), StrToChar(LPCTSTR, userName), (DWORD)flags);
    }

    Ret Mpr::WNetCancelConnection(String^ name, bool force)
    {
      return (Ret)::WNetCancelConnection(StrToChar(LPCTSTR, name), force);
    }

    Ret Mpr::WNetCancelConnection2(String^ name, Connect flags, bool force)
    {
      return (Ret)::WNetCancelConnection2(StrToChar(LPCTSTR, name), (DWORD)flags, force);
    }
  }
}
