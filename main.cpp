#include <windows.h>
#include <iostream>

const DWORD holdDurationA = 100 * 1000;
const DWORD holdDurationD = 96.5 * 1000;
const DWORD pauseBetweenKeys = 2000;
const DWORD loopPause = 5000;
const int totalRows = 6;

void holdKey(WORD key, DWORD duration) {
    keybd_event(key, 0, 0, 0);
    Sleep(duration);
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
}

void holdMouseLeft(DWORD duration) {
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(duration);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

int main() {

    Sleep(3000); // Wait for user to get into program

    int currentRow = 1;

    std::cout << "Starting the automation..." << std::endl;

    while (true) {
        std::cout << "Row - " << currentRow << " - Holding: A" << std::endl;
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        holdKey(0x41, holdDurationA); // 0x41 = 'A'
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

        Sleep(pauseBetweenKeys);

        if (currentRow == totalRows) {
            std::cout << "Simulating death and respawn at row 1..." << std::endl;
            Sleep(loopPause);

            std::cout << "Precaution: Waiting to ensure safe respawn..." << std::endl;
            Sleep(7000); // Wait for user to fall and respawn
            currentRow = 1;
            continue;
        }

        currentRow++;

        std::cout << "Row - " << currentRow << " - Holding: D" << std::endl;
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        holdKey(0x44, holdDurationD); // 0x44 = 'D'
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

        currentRow++;
    }

    return 0;
}
