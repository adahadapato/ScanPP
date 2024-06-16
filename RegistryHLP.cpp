#include "RegistryHLP.h"

BOOL RegistryHLP::CreateRegistryKey(HKEY hKeyParent, LPCWSTR subkey)
{
    DWORD dwDisposition; //It verify new key is created or open existing key
    HKEY  hKey;
    DWORD Ret;
    Ret =
        RegCreateKeyEx(
            hKeyParent,
            subkey,
            0,
            NULL,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            NULL,
            &hKey,
            &dwDisposition);
    if (Ret != ERROR_SUCCESS)
    {
        printf("Error opening or creating key.\n");
        return FALSE;
    }
    RegCloseKey(hKey);
    return TRUE;
}

BOOL RegistryHLP::ReadUserInfoFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, PWCHAR* readData)
{
    HKEY hKey;
    DWORD len = TOTAL_BYTES_READ;
    DWORD readDataLen = len;
    PWCHAR readBuffer = (PWCHAR)malloc(sizeof(PWCHAR) * len);
    if (readBuffer == NULL)
        return FALSE;
    //Check if the registry exists
    DWORD Ret = RegOpenKeyEx(
        hKeyParent,
        subkey,
        0,
        KEY_READ,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        Ret = RegQueryValueEx(
            hKey,
            valueName,
            NULL,
            NULL,
            (BYTE*)readBuffer,
            &readDataLen
        );
        while (Ret == ERROR_MORE_DATA)
        {
            // Get a buffer that is big enough.
            len += OFFSET_BYTES;
            readBuffer = (PWCHAR)realloc(readBuffer, len);
            readDataLen = len;
            Ret = RegQueryValueEx(
                hKey,
                valueName,
                NULL,
                NULL,
                (BYTE*)readBuffer,
                &readDataLen
            );
        }
        if (Ret != ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            return false;;
        }
        *readData = readBuffer;
        RegCloseKey(hKey);
        return true;
    }
    else
    {
        return false;
    }
}

BOOL RegistryHLP::WriteStringToRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, LPCWSTR strData)
{
    DWORD Ret;
    HKEY hKey;
    //Check if the registry exists
    Ret = RegOpenKeyEx(
        hKeyParent,
        subkey,
        0,
        KEY_WRITE,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        if (ERROR_SUCCESS !=
            RegSetValueEx(
                hKey,
                valueName,
                0,
                REG_SZ,
                (LPBYTE)(strData),
                ((((DWORD)lstrlen(strData) + 1)) * 2)))
        {
            RegCloseKey(hKey);
            return FALSE;
        }
        RegCloseKey(hKey);
        return TRUE;
    }
    return FALSE;
}

BOOL RegistryHLP::ReadStringFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCTSTR valueName, PWCHAR* readData)
{
    HKEY hKey;
    DWORD len = TOTAL_BYTES_READ;
    DWORD readDataLen = len;
    PWCHAR readBuffer = (PWCHAR)malloc(sizeof(PWCHAR) * len);
    if (readBuffer == NULL)
        return FALSE;
    //Check if the registry exists
    DWORD Ret = RegOpenKeyEx(
        hKeyParent,
        subkey,
        0,
        KEY_READ,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        Ret = RegQueryValueEx(
            hKey,
            valueName,
            NULL,
            NULL,
            (BYTE*)readBuffer,
            &readDataLen
        );
        while (Ret == ERROR_MORE_DATA)
        {
            // Get a buffer that is big enough.
            len += OFFSET_BYTES;
            readBuffer = (PWCHAR)realloc(readBuffer, len);
            readDataLen = len;
            Ret = RegQueryValueEx(
                hKey,
                valueName,
                NULL,
                NULL,
                (BYTE*)readBuffer,
                &readDataLen
            );
        }
        if (Ret != ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            return false;;
        }
        *readData = readBuffer;
        RegCloseKey(hKey);
        return true;
    }
    else
    {
        return false;
    }
}


//BOOL RegistryHLP::ReadRegistry(HKEY hKeyParent, LPCSTR lpsubkey, LPCSTR valueName, LPCSTR* readData)
//{
//    HKEY hKey;
//    DWORD len = TOTAL_BYTES_READ;
//    DWORD readDataLen = len;
//    PWCHAR readBuffer = (PWCHAR)malloc(sizeof(PWCHAR) * len);
//    if (readBuffer == NULL)
//        return FALSE;
//    //Check if the registry exists
//    DWORD Ret = RegOpenKeyA(
//        hKeyParent,
//        lpsubkey,
//        
//        &hKey
//    );
//    if (Ret == ERROR_SUCCESS)
//    {
//        Ret = RegQueryValueA(
//            hKey,
//            lpsubkey,
//            &readDataLen,
//            NULL
//        );
//        while (Ret == ERROR_MORE_DATA)
//        {
//            // Get a buffer that is big enough.
//            len += OFFSET_BYTES;
//            readBuffer = (PWCHAR)realloc(readBuffer, len);
//            readDataLen = len;
//            Ret = RegQueryValueEx(
//                hKey,
//                valueName,
//                NULL,
//                NULL,
//                (BYTE*)readBuffer,
//                &readDataLen
//            );
//        }
//        if (Ret != ERROR_SUCCESS)
//        {
//            RegCloseKey(hKey);
//            return false;;
//        }
//        *readData = readBuffer;
//        RegCloseKey(hKey);
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}



BOOL RegistryHLP::ReadDwordFromRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, DWORD* readData)
{
    HKEY hKey;
    DWORD Ret;
    //Check if the registry exists
    Ret = RegOpenKeyEx(
        hKeyParent,
        subkey,
        0,
        KEY_READ,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        DWORD data;
        DWORD len = sizeof(DWORD);//size of data
        Ret = RegQueryValueEx(
            hKey,
            valueName,
            NULL,
            NULL,
            (LPBYTE)(&data),
            &len
        );
        if (Ret == ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            (*readData) = data;
            return TRUE;
        }
        RegCloseKey(hKey);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

BOOL RegistryHLP::WriteDwordToRegistry(HKEY hKeyParent, LPCWSTR subkey, LPCWSTR valueName, DWORD data)
{
    DWORD Ret;
    HKEY hKey;
    //Open the key
    Ret = RegOpenKeyEx(
        hKeyParent,
        subkey,
        0,
        KEY_WRITE,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        //Set the value in key
        if (ERROR_SUCCESS !=
            RegSetValueEx(
                hKey,
                valueName,
                0,
                REG_DWORD,
                reinterpret_cast<BYTE*>(&data),
                sizeof(data)))
        {
            RegCloseKey(hKey);
            return FALSE;
        }
        //close the key
        RegCloseKey(hKey);
        return TRUE;
    }
    return FALSE;
}

// status = writeStringInRegistry(HKEY_CURRENT_USER, L"Aticleworld", L"Message", L"Happy"); //write string
//if (status != TRUE)
//return FALSE;