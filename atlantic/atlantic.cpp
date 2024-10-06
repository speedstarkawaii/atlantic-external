#include "headers.hpp"
#include "memory.hpp"

driver byfron;

bool main()
{
    // console mods such as making it topmost etc
    auto start = std::chrono::high_resolution_clock::now(); // used for checking how long it takes to run


    ::SetConsoleTitleA("atlantic-external");

    ::cout << R"(

     ___   .___________. __          ___      .__   __. .___________. __    ______ 
    /   \  |           ||  |        /   \     |  \ |  | |           ||  |  /      |
   /  ^  \ `---|  |----`|  |       /  ^  \    |   \|  | `---|  |----`|  | |  ,----'
  /  /_\  \    |  |     |  |      /  /_\  \   |  . `  |     |  |     |  | |  |     
 /  _____  \   |  |     |  `----./  _____  \  |  |\   |     |  |     |  | |  `----.
/__/     \__\  |__|     |_______/__/     \__\ |__| \__|     |__|     |__|  \______|
                                                                                   
    )";

    ::cout << "" << ::endl;

    ::SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); // top most console

    ::cout << "credits*> speedsterkawaii" << ::endl;
     
    if (!::FindWindowA(NULL, "Roblox")) { // we CAN do if robloxplayerbeta exists however that method is really overrated its better to use alternatives and not really be like anybody else however there are a good amount of ways to see if roblox is actually running like checking if the process is open or by window 
        ::cout << "roblox was not found!" << ::endl;

        system("PAUSE");
        return false;
    }

    ::cout << "roblox*> checking if original process." << ::endl;
    // neat function incoming
    if (byfron.libloaded(byfron.pid(),L"RobloxPlayerBeta.dll")) // checks if robloxs lib is loaded into roblox / not required just a 'deep' check to see if its original roblox
    {
        byfron.open(byfron.pid());
        ::cout << "memory*> opened process" << ::endl;

        auto end = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = end - start;

        ::cout << "info*> took " << elapsed.count() << " seconds" << std::endl;

    }
    else { // this is not original roblox; just close the process :c
        ::cout << "roblox*> unknown process!" << ::endl;
        MessageBoxA(0, "perhaps you opened wrong roblox?", "not roblox", MB_ICONERROR);
        exit(2);
    }
}