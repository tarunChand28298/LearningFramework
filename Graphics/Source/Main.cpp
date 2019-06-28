#include "Display.h"

class NewDisplay : public Display {
public:
	int xPos = 100;
	int yPos = 100;
	bool xMoving = true;

	void Draw() override {
		DrawRectangle(400, 400, 50, 50, 0xFF00FF00, DrawMode::Outline);
		DrawLine(xPos, yPos, 300, 300, 0xFFFFFFFF);
		DrawCircle(250, 250, 50, 0xFFFFFFFF, DrawMode::Outline);
		DrawTriangle(100, 100, 200, 200, 100, 200, 0xFFFFFFFF, DrawMode::Outline);
		PutPixel(-90, 60000, 0xFFFFFFFF);
	}

	void Update() override {
		if (xMoving) { xPos++; }
		else { yPos++; }

		if (xPos > 400) { xPos = 100;  xMoving = false; }
		if (yPos > 400) { yPos = 100; xMoving = true; }
	}
};

int main() {
	NewDisplay displayInstance;
	displayInstance.InitializeDisplay();
	displayInstance.RunDisplay();

	return EXIT_SUCCESS;
}
