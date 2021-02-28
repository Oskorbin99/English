#include <iostream>
#include <ctime>
#include <windows.h>
#include <stdio.h>
struct  sLang{
    sLang() : fLang(ENG)
    {
        const wchar_t* tit = L"my";
        SetConsoleTitle(tit);
        Sleep(40);
        hWnd = FindWindow(NULL, tit);
        procid = GetWindowThreadProcessId(hWnd, NULL);
    }
    enum E    {
        ENG = 0x409,
        RUS = 0x419
    };
    E      fLang;
    HWND    hWnd;
    DWORD procid;
    void set(E e)    {
        fLang = e;
        keep_lang();
    }
    void keep_lang()   {   // 0x419 -рус.; 0x409 -англ.
        PostMessage(hWnd, WM_INPUTLANGCHANGEREQUEST,
            INPUTLANGCHANGE_SYSCHARSET, fLang);
    }
    union un    {
        HKL  h;
        WORD w[2];
    } a;
    const char* what()    {
        const char* rus = "Русская клавиатура.";
        const char* eng = "Английская клавиатура.";

        procid = GetWindowThreadProcessId(hWnd, NULL);
        a.h = GetKeyboardLayout(procid); /// 0 - НЕВЕРНЫЙ ПАРАМЕТР!
        std::cout << "GetKeyboardLayout(procid): " << a.h << "\n";

        if (a.w[0] == RUS)
            return rus;
        else
            return eng;
    }
    bool isrus()    {
        a.h = GetKeyboardLayout(procid); /// 0 - НЕВЕРНЫЙ ПАРАМЕТР!
        std::cout << "isrus(): " << a.w[0] << "\n";
        if (a.w[0] == RUS)
            return true;
        return false;
    }
} Lang;
#pragma once