using System;
using System.Collections.Generic;
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
