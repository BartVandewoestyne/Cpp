/*
 * Key ideas:
 *
 *   - Windows supports three sets of character and string data types:
 *       1. a set of generic type definitions
 *            TCHAR
 *            typedef TCHAR *LPTSTR, *LPTCH;
 *       2. one set of specific type definitions for use with Windows code pages
 *            CHAR
 *            typedef CHAR *LPSTR, *LPCH;
 *       3. one set of specific type definitions for use with Unicode
 *            WCHAR
 *            typedef WCHAR *LPWSTR, *LPWCH;
 *     The letter "T" in a type definition, for example, TCHAR or LPTSTR,
 *     designates a generic type that can be compiled for either Windows code
 *     pages or Unicode. The letter "W" in a type definition, for example,
 *     WCHAR or LPWSTR, designates a Unicode type.
 *
 *   - The Windows SDK provides function prototypes in three versions:
 *       1. generic (e.g. SetWindowText)
 *          -> uses the data type LPCTSTR for the text parameter
 *       2. Windows code page (e.g. SetWindowTextA) with "A" for "ANSI".
 *          -> uses the data type LPCSTR for the text parameter
 *       3. Unicode version (e.g. SetWindowTextW) with "W" for Unicode.
 *          -> uses the data type LPCWSTR for the text parameter
 *
 *   - For all functions with text arguments, applications should normally use
 *     the generic function prototypes.
 *
 *   - Your application should always use a generic function prototype with the
 *     generic string and character types.
 *
 *   - Typically, not using UNICODE define is to support legacy applications.
 *     Nowadays, use the generic forms and define UNICODE.
 *
 * References:
 *
 *   [microsoft] Windows Data Types for Strings
 *     https://docs.microsoft.com/en-us/windows/win32/intl/windows-data-types-for-strings
 *
 *   [microsoft] Unicode and Character Sets
 *     https://docs.microsoft.com/en-us/windows/win32/intl/unicode-and-character-sets
 *
 *   [microsoft] Conventions for Function Prototypes
 *     https://docs.microsoft.com/en-us/windows/win32/intl/conventions-for-function-prototypes
 *
 *   [chen20040212] TEXT vs. _TEXT vs. _T, and UNICODE vs. _UNICODE
 *     https://devblogs.microsoft.com/oldnewthing/?p=40643
 */
