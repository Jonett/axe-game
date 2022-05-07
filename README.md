# axe-game

C++ Fundamentals: Game Programming For Beginners
 * https://www.gamedev.tv/courses/enrolled/1216775
 * GameDev.tv source https://gitlab.com/GameDevTV/CPPCourse/axe-game


Axe Game
new for me in this course was...
 *  Variable braced initialization 
    (Good stackoverflow thread: https://stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives) 
 *  Pretty much everythin that comes to raylib
 *  Basic collission detection
 
Things that could be improved...
 *  Circles collission is checked by corner coordinates based on square dimensions. By changing the collision detection to area dectection it would improve the accuracy.
 *  Circle is now only moving on X-axis, would give more depth to the game if the circle could also move on Y-axis.
 *  Random speed change everytime the axe changes directions could increase the difficutly level.
 *  Restart game button after gameover.
 *  Game points

For this code to compile on windows without changes, raylib needs to be installed to C:\raylib
Get raylib from https://www.raylib.com/
