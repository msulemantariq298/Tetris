#include "button.h"
#include"colors.h"

// Constructor - initializes a button with position, size, and appearance
Button::Button(float x, float y, float width, float height, const char* buttonText, int size)
{
    bounds = {x, y, width, height};     // Set button position and dimensions
    text = buttonText;                  // Set button label text
    fontSize = size;                    // Set font size
    color = lightblue;                  // Default button color (light blue)
    hoverColor = blue;                  // Color when mouse hovers over button (darker blue)
    textColor = WHITE;                  // Text color
    isHovered = false;                  // Initially not hovered
}

// Draw - renders the button on screen with current state
void Button::Draw()
{
    // Draw main rounded button rectangle
    // Changes color based on hover state
    DrawRectangleRounded(bounds, 0.2, 10, isHovered ? hoverColor : color);
    
    // Draw rounded button border (dark outline)
    DrawRectangleRoundedLines(bounds, 0.2, 10, {0, 0, 0, 255});
    
    // Calculate text dimensions for centering
    int textWidth = MeasureText(text, fontSize);
    float textX = bounds.x + (bounds.width - textWidth) / 2;      // Center horizontally
    float textY = bounds.y + (bounds.height - fontSize) / 2;      // Center vertically
    
    // Draw button text at center
    DrawText(text, (int)textX, (int)textY, fontSize, textColor);
}

// Update - called each frame to check hover state
void Button::Update()
{
    // Check if mouse cursor is over the button
    isHovered = CheckCollisionPointRec(GetMousePosition(), bounds);
}

// IsClicked - returns true if button was clicked this frame
bool Button::IsClicked()
{
    return isHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

// IsHovered - returns current hover state
bool Button::IsHovered()
{
    return isHovered;
}

// SetColors - allows customizing button colors after creation
void Button::SetColors(Color normalColor, Color hoverColorParam, Color textColorParam)
{
    color = normalColor;              // Normal button color
    hoverColor = hoverColorParam;     // Hover state color
    textColor = textColorParam;       // Text color
}
