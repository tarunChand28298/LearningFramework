#pragma once
#include "Input.h"
#include <Windows.h>
#include <utility>
#include <chrono>
#include <string>
#include <iostream>
#include <fstream>

enum DrawMode {
	Fill,
	Outline
};

struct Bitmap {
	int width;
	int height;
	int* surface;

	Bitmap(std::wstring filename) {
		std::ifstream file(filename, std::ios::binary);

		BITMAPFILEHEADER fileHeader = {};
		BITMAPINFOHEADER infoHeader = {};

		file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
		file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
		
		width = infoHeader.biWidth;
		height = infoHeader.biHeight;
		surface = new int[width * height];

		file.seekg(fileHeader.bfOffBits);
		for (int i = 0; i < width*height; i++) {
			unsigned char r, g, b, p;
			file.read(reinterpret_cast<char*>(&b), sizeof(char));
			file.read(reinterpret_cast<char*>(&g), sizeof(char));
			file.read(reinterpret_cast<char*>(&r), sizeof(char));
			file.read(reinterpret_cast<char*>(&p), sizeof(char));

			int finalColour = 0;
			finalColour = p;
			finalColour <<= 8;
			finalColour |= r;
			finalColour <<= 8;
			finalColour |= g;
			finalColour <<= 8;
			finalColour |= b;

			surface[i] = finalColour;
		}
	}
	~Bitmap() {
		delete[] surface;
	}
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
	static constexpr int defaultClearColour = 0x00000000;

	void PutPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char p);
	void PutPixel(int x, int y, int colour);

	void DrawLine(int x1, int y1, int x2, int y2, int colour);					//Directly picked up from OLC pixel game engine.
	void DrawCircle(int x, int y, int radius, int colour, DrawMode mode);				//Directly picked up from OLC pixel game engine.
	void DrawRectangle(int x, int y, int width, int height, int colour, DrawMode mode);
	void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int colour, DrawMode mode);	//Directly picked up from OLC pixel game engine.
	void DrawBitmap(int x, int y, const Bitmap& bitmap);						//32 bit bitmap images. (8 bits per channel with padding.)

	void ClearPixelbuffer();
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void End();
	void PresentPixelbufferToWindow();

	void UpdateMaster();
	void DrawMaster();

	
};
