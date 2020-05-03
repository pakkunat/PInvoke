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

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/ns-winnetwk-netresourcea
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/ns-winnetwk-netresourcew
      ref class NetResource
      {
      public:
        Scope Scope;
        Type Type;
        DisplayType DisplayType;
        Usage Usage;
        System::String^ LocalName;
        System::String^ RemoteName;
        System::String^ Comment;
        System::String^ Provider;
      };

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnectiona
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnectionw
      static Ret WNetAddConnection(System::String^ remoteName, System::String^ password, System::String^ localName);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection2a
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection2w
      static Ret WNetAddConnection2(NetResource^ netResource, System::String^ password, System::String^ userName, Connect flags);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection3a
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetaddconnection3w
      static Ret WNetAddConnection3(System::IntPtr wndOwner, NetResource^ netResource, System::String^ password, System::String^ userName, Connect flags);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnectiona
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnectionw
      static Ret WNetCancelConnection(System::String^ name, bool force);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnection2a
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetcancelconnection2w
      static Ret WNetCancelConnection2(System::String^ name, Connect flags, bool force);

      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetgetlasterrora
      /// https://docs.microsoft.com/en-us/windows/win32/api/winnetwk/nf-winnetwk-wnetgetlasterrorw
      //Ret GetLastError(Ret %error, String^ errorBuf, DWORD errorBufSize, );
    };
  }
}
