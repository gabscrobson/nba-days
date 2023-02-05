#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Hide console
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    // Create current_directory and filename
    wchar_t current_directory[MAX_PATH];
    wchar_t filename[] = L"\\days\\00.jpg";

    // Get current working directory
    GetCurrentDirectoryW(MAX_PATH, current_directory);

    // Get current day
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Assign current day to filename
    filename[6] = (int)(tm.tm_mday/10) + 48;
    filename[7] = (int)(tm.tm_mday%10) + 48;

    // Concatenate current_directory and filename
    wcscat(current_directory, filename);

    // Changes windows wallpaper
    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)current_directory, SPIF_UPDATEINIFILE);

    return 0;
}
