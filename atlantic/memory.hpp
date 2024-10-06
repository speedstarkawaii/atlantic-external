#include "headers.hpp"

HANDLE roblox; // we are going to put the new opened process in here so wpm and rpm can access it 

class driver { // noob your getting detected fake class imagine crashing each second haha get on my level
public:
    inline void open(DWORD id) {
        roblox = OpenProcess(PROCESS_ALL_ACCESS, FALSE, id); // least detected method
    }

    inline void close() {
        roblox = nullptr; // should do nothing/crash roblox if trying to access
    }

    inline void write(DWORD64 address, int* buffer, SIZE_T size = 0) { // totally need the last argument yes
        if (size == 0)
            size = sizeof(int);

        WriteProcessMemory(roblox, (LPVOID)address, (LPCVOID)buffer, size, NULL);
    }

    inline void read(DWORD64 address, int* buffer, SIZE_T size = 0) { // set nothing to 0
        if (size == 0)
            size = sizeof(int);

        ReadProcessMemory(roblox, (LPCVOID)address, buffer, size, NULL);
    }

    inline bool protection(DWORD64 address, SIZE_T size, DWORD new_protection) {
        DWORD old_protection;
        return VirtualProtectEx(roblox, (LPVOID)address, size, new_protection, &old_protection); // dont need to really change protections
    }

    inline void free(DWORD64 address) {
        VirtualFreeEx(roblox, (LPVOID)address, 0, MEM_RELEASE); // however we wont need this its not like we are doing some major read/writing memory
    }


    inline bool hacked() { // yes we HACKED roblox 100%
        return (roblox != NULL);
    }

    inline int pid() { // returns the roblox process id
        HANDLE snapped = CreateToolhelp32Snapshot(0x00000002, 0); // for some reason couldnt use macro need to use the direct flag code :/

        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(snapped, &pe)) {
            do {
                if (wcscmp(pe.szExeFile, L"RobloxPlayerBeta.exe") == 0) {
                    CloseHandle(snapped);
                    return pe.th32ProcessID;
                }
            } while (Process32Next(snapped, &pe));
        }

        CloseHandle(snapped);
        return 0;
    }


    bool libloaded(DWORD process_id, const wchar_t* dll_name) { // i should make a public process id so each function can access it right? 
        // this returns if a library is loaded into roblox can be used for 'is injected' things or wahtever
        HANDLE snapped = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, process_id);

        MODULEENTRY32 me;
        me.dwSize = sizeof(MODULEENTRY32);

        if (Module32First(snapped, &me)) {
            do {
                if (_wcsicmp(me.szModule, dll_name) == 0) { // if 2nd arg matches then the library is loaded into roblox yikes
                    CloseHandle(snapped);
                    return true; // loaded return true
                }
            } while (Module32Next(snapped, &me));
        }

        CloseHandle(snapped);
        return false; // no library loaded or no troblox
    }

};
