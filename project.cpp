#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// Function Prototypes
void displayMyName();
void drawUsingDDA();
void drawMovingBoat();
void drawEmoji();
void BangladeshiFlag();

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Set path to your BGI directory

    int choice;

    while (true) {
        cleardevice();  // Clear the screen before showing the menu
        cout << "1. Display My Name (JARIF) using Line Function" << endl;
        cout << "2. Draw Line using DDA Algorithm" << endl;
        cout << "3. Draw Moving Boat with Color" << endl;
        cout << "4. Draw Green Emoji" << endl;
        cout << "5. Draw Small Bangladeshi Flag" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cleardevice();  // Clear the screen before drawing the selected item

        switch(choice) {
            case 1:
                displayMyName();
                break;
            case 2:
                drawUsingDDA();
                break;
            case 3:
                drawMovingBoat();
                break;
            case 4:
                drawEmoji();
                break;
            case 5:
                BangladeshiFlag();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                closegraph();
                return 0;
            default:
                cout << "Invalid choice! Please select again." << endl;
        }

        cout << "Press any key to return to menu..." << endl;
        getch();  // Wait for a key press before returning to the menu
    }

    closegraph();
    return 0;
}

// Function Definitions

void displayMyName() {
    setcolor(WHITE);

    // Letter 'J'
    line(100, 100, 150, 100);
    line(125, 100, 125, 150);
    line(100, 150, 125, 150);

    // Letter 'A'
    line(170, 150, 195, 100);
    line(220, 150, 195, 100);
    line(180, 125, 210, 125);

    // Letter 'R'
    line(240, 150, 240, 100);
    line(240, 100, 270, 100);
    line(270, 100, 270, 125);
    line(240, 125, 270, 125);
    line(240, 125, 270, 150);

    // Letter 'I'
    line(300, 100, 300, 150);

    // Letter 'F'
    line(330, 100, 330, 150);
    line(330, 100, 360, 100);
    line(330, 125, 350, 125);
}

void drawUsingDDA() {
    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    float X = x1;
    float Y = y1;

    setcolor(RED);

    for (int i = 0; i <= steps; i++) {
        putpixel(X, Y, RED);
        X += Xinc;
        Y += Yinc;
        delay(10);  // Animation delay
    }
}

void drawMovingBoat() {
    int x = 0;
    while (x < getmaxx()) {
        cleardevice();

        // Draw water
        setcolor(BLUE);
        rectangle(0, getmaxy() - 100, getmaxx(), getmaxy());
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(1, getmaxy() - 99, BLUE);

        // Draw the boat body
        setcolor(BROWN);
        rectangle(100 + x, getmaxy() - 150, 300 + x, getmaxy() - 100);
        setfillstyle(SOLID_FILL, BROWN);
        floodfill(101 + x, getmaxy() - 149, BROWN);

        // Draw the boat sail
        setcolor(WHITE);
        line(200 + x, getmaxy() - 150, 200 + x, getmaxy() - 250);
        line(200 + x, getmaxy() - 250, 150 + x, getmaxy() - 150);
        line(200 + x, getmaxy() - 250, 250 + x, getmaxy() - 150);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(200 + x, getmaxy() - 200, WHITE);

        delay(50);
        x += 10;
        if (x > getmaxx()) x = -200; // Reset position if boat goes off-screen
    }
}

void drawEmoji() {
    setcolor(GREEN);
    circle(300, 200, 100);      // Face
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(300, 200, GREEN);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(260, 170, 15);       // Left eye
    floodfill(260, 170, BLACK);
    circle(340, 170, 15);       // Right eye
    floodfill(340, 170, BLACK);
    arc(300, 240, 180, 360, 40);  // Smile
}

void BangladeshiFlag() {
    int flagWidth = 200;
    int flagHeight = 150;
    int circleRadius = 40;

    // Draw the green flag
    setcolor(GREEN);
    rectangle(50, 50, 50 + flagWidth, 50 + flagHeight);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(51, 51, GREEN);

    // Draw the red circle
    setcolor(RED);
    circle(50 + flagWidth / 2, 50 + flagHeight / 2, circleRadius);
    setfillstyle(SOLID_FILL, RED);
    floodfill(50 + flagWidth / 2, 50 + flagHeight / 2, RED);
}
