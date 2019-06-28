#pragma once
#include <Windows.h>
#include <utility>

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

	int width = 1000;
	int height = 600;
	bool running = false;

	HWND mainWindowHandle = nullptr;
	int* pixelBuffer = nullptr;

	BITMAPINFO pixelbufferInfo = {};
	WNDCLASS windowClassInfo = {};

	void PutPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char p);
	void PutPixel(int x, int y, int colour);

	void DrawLine(int x1, int y1, int x2, int y2, int colour);										//Directly picked up from OLC pixel game engine.
	void DrawCircle(int x, int y, int radius, int colour, DrawMode mode);							//Directly picked up from OLC pixel game engine.
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