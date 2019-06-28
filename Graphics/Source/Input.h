#pragma once
#include <Windows.h>

struct Mouse
{
	HWND relativeToWindow;
	int screenHeight;
	POINT mousePos;

	void UpdateMouse() {
		GetCursorPos(&mousePos);
		ScreenToClient(relativeToWindow, &mousePos);
		mousePos.y = (-mousePos.y) + screenHeight;
	}

	bool GetMouseButtonState(int buttonCode) {
		return GetKeyState(buttonCode) & 0x80;
	}
};

struct Keyboard {
	void UpdateKeyboard() {

	}

	bool GetKeyboardKeyState(int keyCode) {
		return GetAsyncKeyState(keyCode);
	}
};
