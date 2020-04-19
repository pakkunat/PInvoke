#pragma once
#include <share.hpp>

namespace P
{
  namespace PInvoke
  {
    public ref class Mpr
    {
    public:
      enum class Scope
      {
        Connected = RESOURCE_CONNECTED,
        GlobalNet = RESOURCE_GLOBALNET,
        Context = RESOURCE_CONTEXT
      };

      enum class Type
      {
        Disk = RESOURCETYPE_DISK,
        Print = RESOURCETYPE_PRINT,
        Any = RESOURCETYPE_ANY
      };

      enum class DisplayType
      {
        Network = RESOURCEDISPLAYTYPE_NETWORK,
        Domain = RESOURCEDISPLAYTYPE_DOMAIN,
        Server = RESOURCEDISPLAYTYPE_SERVER,
        Share = RESOURCEDISPLAYTYPE_SHARE,
        Directory = RESOURCEDISPLAYTYPE_DIRECTORY,
        Generic = RESOURCEDISPLAYTYPE_GENERIC
      };

      enum class Usage
      {
        Connectable = RESOURCEUSAGE_CONNECTABLE,
        Container = RESOURCEUSAGE_CONTAINER
      };

      enum class Connect
      {
        UpdateProfile = CONNECT_UPDATE_PROFILE,
        UpdateRecent = CONNECT_UPDATE_RECENT,
        Temporary = CONNECT_TEMPORARY,
        Interactive = CONNECT_INTERACTIVE,
        Prompt = CONNECT_PROMPT,
        Redirect = CONNECT_REDIRECT,
        CurrentMedia = CONNECT_CURRENT_MEDIA,
        CommandLine = CONNECT_COMMANDLINE,
        CmdSaveCred = CONNECT_CMD_SAVECRED,
        CredReset = CONNECT_CRED_RESET
      };

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/ns-winnetwk-netresourcew
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/ns-winnetwk-netresourcea
      ref class NetResource
      {
      public:
        Scope Scope;
        Type Type;
        DisplayType DisplayType;
        Usage Usage;
        String^ LocalName;
        String^ RemoteName;
        String^ Comment;
        String^ Provider;
      };

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnectionw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnectiona
      static Ret WNetAddConnection(String^ remoteName, String^ password, String^ localName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection2w
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection2a
      static Ret WNetAddConnection2(NetResource^ netResource, String^ password, String^ userName, Connect flags);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection3w
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection3a
      static Ret WNetAddConnection3(IntPtr wndOwner, NetResource^ netResource, String^ password, String^ userName, Connect flags);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnectionw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnectiona
      static Ret WNetCancelConnection(String^ name, bool force);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnection2w
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnection2a
      static Ret WNetCancelConnection2(String^ name, Connect flags, bool force);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetgetlasterrorw
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetgetlasterrora
      //Ret GetLastError(Ret %error, String^ errorBuf, DWORD errorBufSize, );
    };
  }
}
