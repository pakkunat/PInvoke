#pragma comment (lib, "shell32.lib")
#include <marshal.hpp>
#include <shell32.hpp>

namespace P
{
  namespace PInvoke
  {
    System::IntPtr Shell32::DuplicateIcon(System::IntPtr icon)
    {
      return (System::IntPtr)::DuplicateIcon(GetHInst(0), (HICON)icon.ToPointer());
    }

    System::IntPtr Shell32::ExtractAssociatedIcon(System::String^ iconPath, WORD% icon)
    {
      auto ic = (WORD)0;
      auto ret = ::ExtractAssociatedIcon(GetHInst(0), StrToChar(LPTSTR, iconPath), &ic);
      if (ret != nullptr)
      {
        icon = ic;
      }
      return (System::IntPtr)ret;
    }

    System::Collections::Generic::List<System::IntPtr>^ Shell32::ExtractIcon(System::String^ exeFileName)
    {
      auto num = ::ExtractIcon(GetHInst(0), StrToChar(LPCTSTR, exeFileName), -1);
      if (num > 0)
      {
        auto ret = gcnew System::Collections::Generic::List<System::IntPtr>((UINT)(UINT64)num);
        for (auto i = 0u; i < (UINT)(UINT64)num; i++)
        {
          ret->Add((System::IntPtr)::ExtractIcon(GetHInst(0), StrToChar(LPCTSTR, exeFileName), i));
        }
        return ret;
      }
      return nullptr;
    }

    System::Collections::Generic::List<System::Tuple<System::IntPtr, System::IntPtr>^>^ Shell32::ExtractIconEx(System::String^ file)
    {
      auto num = ::ExtractIconEx(StrToChar(LPCTSTR, file), -1, nullptr, nullptr, 0);
      if (num > 0)
      {
        auto ret = gcnew System::Collections::Generic::List<System::Tuple<System::IntPtr, System::IntPtr>^>(num);
        for (auto i = 0u; i < num; i++)
        {
          auto li = (HICON)nullptr;
          auto si = (HICON)nullptr;
          auto r = ::ExtractIconEx(StrToChar(LPCTSTR, file), i, &li, &si, 1);
          ret->Add(r == 2 ? gcnew System::Tuple<System::IntPtr, System::IntPtr>((System::IntPtr)li, (System::IntPtr)si) : nullptr);
        }
        return ret;
      }
      return nullptr;
    }

    HResult Shell32::SHDefExtractIcon(System::String^ iconFile, int index, GilReturn flags, System::IntPtr% iconLarge, System::IntPtr% iconSmall, UINT iconLargeSize, UINT iconSmallSize)
    {
      auto il = (HICON)nullptr;
      auto is = (HICON)nullptr;
      auto size = iconSmallSize << 16 | iconLargeSize;
      auto ret = ::SHDefExtractIcon(StrToChar(LPCTSTR, iconFile), index, (UINT)flags, &il, &is, size);
      if (ret == S_OK)
      {
        iconLarge = (System::IntPtr)il;
        iconSmall = (System::IntPtr)is;
      }
      return (HResult)ret;
    }
  }
}