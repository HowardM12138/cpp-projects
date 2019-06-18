#include <iostream>
#include <windows.h>
int main() {

    std::cout << "You are gay.\n";
    Sleep(2000);
    std::cout << "Your computer will be HACKED.\n\n";
    Sleep(2000);

    for (int i = 0; i < 7; i++) {
        std::cout << "C:\\Windows\\System32\\" << i+1 <<".exe\n";
        std::cout << "WARNING: SUSPICIOUS PROGRAM IS EXECUTING\n";
        std::cout << "EXECUTING";
        for (int j = 0; j < 3; j++) {
            std::cout << ".";
            Sleep(500);
        }
        std::cout << "\nEXECUTION COMPLETE.\n";
        Sleep(500);
        switch (i) {
            case 0:
                std::cout << "Invaliding System Filrewall: Success";
                break;
            case 1:
                std::cout << "Granting Access - System Microphone: Success";
                break;
            case 2:
                std::cout << "Granting Access - System Camera: Success";
                break;
            case 3:
                std::cout << "Screen Monitoring: Success";
                break;
            case 4:
                std::cout << "Installing Network Control Tools: Complete";
                break;
            case 5 :
            {
                std::cout << "Granting Windows System Administration: In Progress\n";
                Sleep(1400);
                std::cout << "System Administration: Change Administrator\n";
                Sleep(1500);
                std::cout << "System Administration: Assign to 167.269.1.1\n";
                Sleep(1500);
                std::cout << "Warning: No user logged in. Please Sign in\n";
                Sleep(1500);
                std::cout << "Sign in as HackingYourComputer\n";
                Sleep(1500);
                std::cout << "Warning: Some files may lose administration access";
                break;
            }
            case 6:
                std::cout << "System Administration: Valid. User: HackingYourComputer";
                break;
        }
        std::cout << "\n\n";
        Sleep(1500);
    }
    Sleep(5000);
    std::cout << "\nJust kidding. I don't have that ability yet.\n";
    Sleep(3500);
    std::cout << "Or do I?\n";
    Sleep(2000);
    std::cout << ":)\n";

    Sleep(90*1000);

    return 0;
}
