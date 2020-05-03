#pragma once
#include <windows.h>

namespace P
{
  namespace PInvoke
  {
    public enum class Ret
    {
      NoErr = NO_ERROR,
      ErrAccessDenied = ERROR_ACCESS_DENIED,
      ErrAlreadyAssigned = ERROR_ALREADY_ASSIGNED,
      ErrBadDevType = ERROR_BAD_DEV_TYPE,
      ErrBadDevice = ERROR_BAD_DEVICE,
      ErrBadNetName = ERROR_BAD_NET_NAME,
      ErrBadProfile = ERROR_BAD_PROFILE,
      ErrBadProvider = ERROR_BAD_PROVIDER,
      ErrBadUserName = ERROR_BAD_USERNAME,
      ErrBusy = ERROR_BUSY,
      ErrCancelled = ERROR_CANCELLED,
      ErrCannotOpenProfile = ERROR_CANNOT_OPEN_PROFILE,
      ErrDeviceAlreadyRemembered = ERROR_DEVICE_ALREADY_REMEMBERED,
      ErrDeivceInUse = ERROR_DEVICE_IN_USE,
      ErrExtendedErr = ERROR_EXTENDED_ERROR,
      ErrInvalidAddress = ERROR_INVALID_ADDRESS,
      ErrInvalidParameter = ERROR_INVALID_PARAMETER,
      ErrInvalidPassword = ERROR_INVALID_PASSWORD,
      ErrLogonFailure = ERROR_LOGON_FAILURE,
      ErrNoNetOrBadPath = ERROR_NO_NET_OR_BAD_PATH,
      ErrNoNetwork = ERROR_NO_NETWORK,
      ErrNotConnected = ERROR_NOT_CONNECTED,
      ErrOpenFiles = ERROR_OPEN_FILES
    };

    public enum class HResult
    {
      Ok = S_OK,
      False = S_FALSE,
      Fail = E_FAIL
    };
  }
}