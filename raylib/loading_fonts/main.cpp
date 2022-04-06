#include <raylib.h>
// #include <cstdio>
#include <iostream>

class Game
{
    public:
        Font gameFont;

        Game()
        {
            std::cout << "Constructing Game object" << std::endl;

            const int screenWidth = 800;
            const int screenHeight = 450;
            SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
            InitWindow(screenWidth, screenHeight, "MyWindow");
            SetTargetFPS(60);

            gameFont = LoadFont("Iosevka Oblique Nerd Font Complete Mono.ttf");
        }

        ~Game()
        {
            UnloadFont(gameFont);
        }
};

void init();
void close();

int main (int argc, char *argv[])
{
    // Unlike .NET, this implicitly calls the constructor and gets pushed to the stack
    Game game;

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            if (IsKeyDown(KEY_SPACE))
                DrawRectangle(400, 225, 100, 100, BLUE);

            DrawTextEx(game.gameFont, 
                       "This is some epic text", 
                       (Vector2){ 2, 2 },
                       20, 
                       1, 
                       LIGHTGRAY);
        }
        EndDrawing();
    }

    return 0;
    // The destructor for game implicitly gets called at the end of the scope
}


