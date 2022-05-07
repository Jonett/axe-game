/**
 * @file axe_game.cpp
 * @author Joni Hell (joni.hell@outlook.com)
 * @date 2022-05-07
 * 
 * C++ Fundamentals: Game Programming For Beginners
 * https://www.gamedev.tv/courses/enrolled/1216775
 * 
 * GameDev.tv source https://gitlab.com/GameDevTV/CPPCourse/axe-game
 * 
 * Axe Game
 *  new for me in this course was...
 *  -Variable braced initialization 
 *  (Good stackoverflow thread: https://stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives)
 *  
 *  -Pretty much everythin that comes to raylib
 *  -Basic collission detection
 * 
 *  Things that could be improved...
 *  -Circles collission is checked by corner coordinates based on square dimensions. By changing the collision detection to area dectection it would improve the accuracy.
 *  -Circle is now only moving on X-axis, would give more depth to the game if the circle could also move on Y-axis.
 *  -Random speed change everytime the axe changes directions could increase the difficutly level.
 *  -Restart game button after gameover.
 *  -Game points
 *  
 */


#include "raylib.h"


int main() {
    //window dimensions
    int window_width{800};
    int window_height{450};

    InitWindow(window_width, window_height, "Joni");

    //circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    //circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};


    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};


    int direction{10};

    bool collision_with_axe = 
                            (b_axe_y >= u_circle_y) && 
                            (u_axe_y <= b_circle_y) && 
                            (r_axe_x >= l_circle_x) && 
                            (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);
        if(collision_with_axe){
            DrawText("Game Over!", 400, 200, 20, RED);
        }else{
            // Game Logic begins

            // update edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //update collision_with_axe
            collision_with_axe = 
                            (b_axe_y >= u_circle_y) && 
                            (u_axe_y <= b_circle_y) && 
                            (r_axe_x >= l_circle_x) && 
                            (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE);

            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            // move axe
            axe_y += direction;
            if(axe_y > window_height || axe_y < 0){
                direction = -direction;
            }

            //circle movement right && collision dectection with window edge
            if(IsKeyDown(KEY_D) && circle_x < window_width){
                circle_x += 10;
            }

            //circle movement left && collision dectection with window edge
            if(IsKeyDown(KEY_A) && circle_x > 0){
                circle_x -= 10;
            }

            // Game logic ends
        }
        
        EndDrawing();
    }
}