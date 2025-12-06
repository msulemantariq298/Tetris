#pragma once
#include "raylib.h"
using namespace std;

// Button class represents an interactive UI button with hover and click detection
class Button
{
private:
    Rectangle bounds;      // Button position and dimensions (x, y, width, height)
    Color color;           // Button color in normal state
    Color hoverColor;      // Button color when mouse is hovering
    Color textColor;       // Text color
    const char* text;      // Button label text
    int fontSize;          // Size of the button text
    bool isHovered;        // Flag tracking if mouse is over button

public:
    // Constructor - creates a button at specified position with given dimensions and text
    Button(float x, float y, float width, float height, const char* buttonText, int size);
    
    void Draw();           // Renders the button on screen
    void Update();         // Updates button state (hover detection)
    bool IsClicked();      // Returns true if button was clicked this frame
    bool IsHovered();      // Returns true if mouse is currently over button
    
    // Allows customization of button colors
    void SetColors(Color normalColor, Color hoverColorParam, Color textColorParam);
};
