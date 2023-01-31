#include <windows.h>
#include <string.h>

int main(void) {
    wchar_t current_directory[MAX_PATH];
    wchar_t filename[] = L"\\days\\00.jpg";

    // Get current working directory
    GetCurrentDirectoryW(MAX_PATH, current_directory);

    // Change filename to current day
    filename[6] = __DATE__[4];
    filename[7] = __DATE__[5];

    // Concatenate current_directory and filename
    wcscat(current_directory, filename);

    // Changes windows wallpaper
    SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)current_directory, SPIF_UPDATEINIFILE);

    return 0;
}
