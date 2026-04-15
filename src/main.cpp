#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
                   int nCmdShow) {
    MessageBox(NULL, "Hello, World!", "Hello", MB_OK);
    return 0;
}
