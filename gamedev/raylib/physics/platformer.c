#include <raylib.h>
#define PHYSAC_IMPLEMENTATION
#include "physac.h"
#define VELOCITY 0.5f

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char *title = "Shinji's Epic Platformer Test";

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, title);

    InitPhysics();

    // CreatePhysicsBodyRectangle(Vector2 pos, 
    // float width, float height, float density)
    PhysicsBody floor = CreatePhysicsBodyRectangle(
            (Vector2){ screenWidth/2.0f, (float)screenHeight },
            (float) screenWidth, 100, 10);
    PhysicsBody platformLeft = CreatePhysicsBodyRectangle(
            (Vector2){ screenWidth*0.25f, screenHeight*0.6f },
            screenWidth*0.25f, 10, 10);
    PhysicsBody platformRight = CreatePhysicsBodyRectangle(
            (Vector2){ screenWidth*0.75f, screenHeight*0.6f }, 
            screenWidth*0.25f, 10, 10);
    PhysicsBody wallLeft = CreatePhysicsBodyRectangle(
            (Vector2){ -5, screenHeight/2.0f }, 
            10, (float)screenHeight, 10);
    PhysicsBody wallRight = CreatePhysicsBodyRectangle(
            (Vector2){ (float)screenWidth + 5, screenHeight/2.0f }, 
            10, (float)screenHeight, 10);

    // Disable dynamics to floor and walls physics bodies
    floor->enabled = false;
    platformLeft->enabled = false;
    platformRight->enabled = false;
    wallLeft->enabled = false;
    wallRight->enabled = false;

    // Create movement physics body
    PhysicsBody body = CreatePhysicsBodyRectangle(
            (Vector2){ screenWidth/2.0f, screenHeight/2.0f }, 
            50, 50, 1);
    body->freezeOrient = true;      // Constrain body rotation to avoid little collision torque amounts

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdatePhysics();              // Update physics system

        if (IsKeyPressed(KEY_R))      // Reset physics input
        {
            // Reset movement physics body position, velocity and rotation
            body->position = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
            body->velocity = (Vector2){ 0, 0 };
            SetPhysicsBodyRotation(body, 0);
        }

        // Horizontal movement input
        if (IsKeyDown(KEY_RIGHT)) body->velocity.x = VELOCITY;
        else if (IsKeyDown(KEY_LEFT)) body->velocity.x = -VELOCITY;

        // Vertical movement input checking if player physics body is grounded
        if (IsKeyDown(KEY_UP) && body->isGrounded) body->velocity.y = -VELOCITY*4;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawFPS(screenWidth - 90, screenHeight - 30);

            // Draw created physics bodies
            int bodiesCount = GetPhysicsBodiesCount();
            for (int i = 0; i < bodiesCount; i++)
            {
                PhysicsBody body = GetPhysicsBody(i);

                int vertexCount = GetPhysicsShapeVerticesCount(i);
                for (int j = 0; j < vertexCount; j++)
                {
                    // Get physics bodies shape vertices to draw lines
                    // Note: GetPhysicsShapeVertex() already calculates rotation transformations
                    Vector2 vertexA = GetPhysicsShapeVertex(body, j);

                    int jj = (((j + 1) < vertexCount) ? (j + 1) : 0);   // Get next vertex or first to close the shape
                    Vector2 vertexB = GetPhysicsShapeVertex(body, jj);

                    DrawLineV(vertexA, vertexB, BLUE);     // Draw a line between two vertex positions
                }
            }

            DrawText("Use 'ARROWS' to move player", 10, 10, 10, WHITE);
            DrawText("Press 'R' to reset example", 10, 30, 10, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    ClosePhysics();       // Unitialize physics

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

