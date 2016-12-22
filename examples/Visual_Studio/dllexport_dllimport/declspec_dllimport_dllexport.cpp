/**
 * Example on Microsoft's extension __declspec(dllexport) and __declspec(dllimport).
 *
 * __declspec(dllexport) must go in the DLL, and __declspec(dllimport) in the EXE.
 *
 * When you *build* the DLL => you must have __declspec(dllexport)
 * When you *use* the DLL => you must have __declspec(dllimport)
 *
 * References:
 *
 *   https://msdn.microsoft.com/en-us/library/a90k134d.aspx (Visual Studio 2015)
 *   https://msdn.microsoft.com/en-us/library/3y1sfaz2.aspx (Visual Studio 2015)
 *   https://msdn.microsoft.com/en-us/library/81h27t8c.aspx (Visual Studio 2015)
 *   https://msdn.microsoft.com/en-us/library/8fskxacy.aspx (Visual Studio 2015)
 *   https://msdn.microsoft.com/en-us/library/aa271769.aspx (Visual Studio 6)
 *   http://blogs.msdn.com/b/oldnewthing/archive/2006/07/26/679044.aspx
 *   http://blogs.msdn.com/oldnewthing/archive/2004/01/08/48616.aspx#48757
 *   http://stackoverflow.com/questions/15311577/when-to-use-declspecdllexport-in-c
 *   http://stackoverflow.com/questions/10222566/what-is-dllspecdllimport-and-dllspecdllexport-means
 *   http://stackoverflow.com/questions/14980649/macro-for-dllexport-dllimport-switch
 *   https://forum.qt.io/topic/5289/solved-qmake-build-a-dll-and-its-lib-for-msvc/8
 *   http://www.codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL
 */
