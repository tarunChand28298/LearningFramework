#include "Display.h"

class NewDisplay : public Display {
public:
	int xPos = 100;
	int yPos = 100;
	int triColour = 0xFFFFFF;

	void Draw() override {
		DrawRectangle(400, 400, 50, 50, 0xFF00FF00, DrawMode::Outline);
		DrawLine(xPos, yPos, 300, 300, 0xFFFFFFFF);
		DrawCircle(250, 250, 50, 0xFF0000FF, DrawMode::Outline);
		DrawTriangle(100, 100, 200, 200, 100, 200, triColour, DrawMode::Fill);
		PutPixel(90, 60, 0xFFFFFFFF);
	}

	void Update() override {
		xPos = mouse.mousePos.x;
		yPos = mouse.mousePos.y;

		if (keyboard.GetKeyboardKeyState(VK_SHIFT)) {
			triColour = 0xFF00FF00;
		}
		else if (mouse.GetMouseButtonState(VK_LBUTTON)) {
			triColour = 0xFFFF0000;
		}
		else {
			triColour = 0xFFFFFFFF;
		}
	}
};

int main() {
	NewDisplay displayInstance;
	displayInstance.InitializeDisplay();
	displayInstance.RunDisplay();

	return EXIT_SUCCESS;
}
