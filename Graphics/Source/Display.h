#pragma once
#include "Input.h"
#include <Windows.h>
#include <utility>
#include <chrono>

enum DrawMode {
	Fill,
	Outline
};

class Display
{
public:
	Display();
	~Display();

	void InitializeDisplay();
	void RunDisplay();
	void DestroyDisplay();
	static LRESULT CALLBACK MainWindowProcedure(HWND windowHandle, UINT message, WPARAM wparam, LPARAM lparam);

	int width = 700;
	int height = 700;
	bool running = false;
	float deltaTime = 0;

	HWND mainWindowHandle = nullptr;
	int* pixelBuffer = nullptr;
	Mouse mouse;
	Keyboard keyboard;

	BITMAPINFO pixelbufferInfo = {};
	WNDCLASS windowClassInfo = {};
	std::chrono::steady_clock::time_point previousFrameTime;

	void PutPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char p);
	void PutPixel(int x, int y, int colour);

	void DrawLine(int x1, int y1, int x2, int y2, int colour);					//Directly picked up from OLC pixel game engine.
	void DrawCircle(int x, int y, int radius, int colour, DrawMode mode);				//Directly picked up from OLC pixel game engine.
	void DrawRectangle(int x, int y, int width, int height, int colour, DrawMode mode);
	void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int colour, DrawMode mode);	//Directly picked up from OLC pixel game engine.

	void ClearPixelbuffer();
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void End();
	void PresentPixelbufferToWindow();

	void UpdateMaster();
	void DrawMaster();

	
};
