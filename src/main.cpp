#include <windows.h>

LRESULT main_window_callback(HWND window, UINT message, WPARAM w_param,
                             LPARAM l_param) {
    LRESULT result = 0;

    switch (message) {
    case WM_SIZE: {
        OutputDebugStringA("WM_SIZE\n");
    } break;
    case WM_DESTROY: {
        OutputDebugStringA("WM_DESTROY\n");
    } break;
    case WM_CLOSE: {
        OutputDebugStringA("WM_CLOSE\n");
    } break;
    case WM_ACTIVATEAPP: {
        OutputDebugStringA("WM_ACTIVATEAPP\n");
    } break;
    default: {
        result = DefWindowProc(window, message, w_param, l_param);
    } break;
    }

    return result;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev_instance,
                   PSTR command_line, int nCmdShow) {

    WNDCLASS window{};

    window.style = CS_OWNDC | CS_VREDRAW | CS_VREDRAW;
    window.lpfnWndProc = main_window_callback;
    window.hInstance = instance;
    window.lpszClassName = "BeesWindowClass";

    if (RegisterClassA(&window)) {
        HWND window_handle = CreateWindowExA(
            0, window.lpszClassName, "Bees", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0,
            instance, 0);
        if (window_handle) {
            MSG message;
            for (;;) {
                BOOL message_result = GetMessage(&message, 0, 0, 0);
                if (message_result > 0) {
                    TranslateMessage(&message);
                    DispatchMessage(&message);
                } else {
                    break;
                }
            }

        } else {
            // todo: logging
        }
    } else {
        // todo: logging
    }
    MessageBox(NULL, "Hello, World!", "Hello", MB_OK);
    return 0;
}
