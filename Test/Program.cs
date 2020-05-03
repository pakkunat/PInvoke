using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using P.PInvoke;

namespace P
{
  class Program
  {
    static void Main(string[] args)
    {
      var largeIcon = IntPtr.Zero;
      var smallIcon = IntPtr.Zero;
      var ret = Shell32.SHDefExtractIconW(@"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe", 0, 0, ref largeIcon, ref smallIcon, 256, 48);
      if (ret == HResult.Ok)
      {
        Icon.FromHandle(largeIcon).ToBitmap().Save($"./large.ico");
        Icon.FromHandle(smallIcon).ToBitmap().Save($"./small.ico");
        User32.DestroyIcon(largeIcon);
        User32.DestroyIcon(smallIcon);
      }

      var icons = Shell32.ExtractIconExW(@"C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe");
      for (var i = 0; i < icons.Count(); i++)
      {
        Icon.FromHandle(icons[i].Item1).ToBitmap().Save($"./large{i}.ico");
        Icon.FromHandle(icons[i].Item2).ToBitmap().Save($"./small{i}.ico");
        User32.DestroyIcon(icons[i].Item1);
        User32.DestroyIcon(icons[i].Item2);
      }

      var names = Kernel32.GetPrivateProfileSectionNames("./test.ini");
      Console.WriteLine("SectionNames");
      foreach (var n in names)
      {
        Console.WriteLine(n);
      }
      var sw = Kernel32.GetPrivateProfileSection(names[0], "./test.ini");
      Console.WriteLine("\nSection");
      foreach (var n in sw)
      {
        Console.WriteLine(n);
      }
      var r = Kernel32.GetPrivateProfileInt("section1", "test", 6, "loi");
      Console.WriteLine($"\nInt\n{r}\n");

      // GetPrivateProfileString
      // fileNameをnullにすると、レジストリーのHKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\IniFileMapping\win.iniのキー値が読みだされる
      var strlist = Kernel32.GetPrivateProfileString(null, null, null, null);
      foreach (var s in strlist)
      {
        Console.WriteLine(s);
      }

      strlist = Kernel32.GetProfileStringW(null, null, null);
      foreach (var s in strlist)
      {
        Console.WriteLine(s);
      }

      var t = new test { value = 432, str = "8g9" };
      Console.WriteLine($"\nWritePrivateProfileStruct: {Kernel32.WritePrivateProfileStructW("tests", "testk", t, "./test.ini")}");

      var t2 = new test();
      Console.WriteLine($"\nGetPrivateProfileStruct: {Kernel32.GetPrivateProfileStruct("tests", "testk", ref t2, "./test.ini")}");
      Console.WriteLine($"value: {t2.value}, str: {t2.str}");
      Console.ReadKey();
    }

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
    private class test
    {
      public int value;
      [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 64)]
      public string str;
    }
  }
}
