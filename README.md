# cse442-engine

Semester long project for cse442

Class GOAT_Engine:
GOAT_Engine(int w, int h, const char* title, unsigned int fps = 60)
- The GOAT_Engine constructor take in a width and a height for the window, 
- A string for the title of the window
- Unsigned int for the FPS, which defaults to 60 if none is inputted

toggleDebug()
- Is used to toggle the debug display on and off
- Is disabled by default

setFPS(unsigned int fps)
fps - the new fps cap
- Is used to set the maximum FPS (Valid values are numbers > 0)

draw()
- Is used to update the sprites on the screen

addSprite(Sprite* sprite)
- Takes Sprite pointer and adds sprite to screen

pollEvents()
- Pulls updates for keyboard and mouse inputs

shouldClose()
Calls glfwWindowShouldClose(window) to see if it is true or not
- Is false until window is closed

terminate()
- Calls glfwTerminate() to terminate the program

getInput()
- Is used to get access information on the keyboard and mouse input

Class Input:
InputSource(GLFWwindow *window = nullptr)
- Sets the window for input

update()
- Is used to keep input info updated

getKey(int i)
- Is used to see if a key is currently pressed down

getKeyDown(int i)
- Is used to see if a key was just pressed down

getKeyUp(int i)
- Is used to see if a key is currently up

getMouse(int i)
- Is used to see if a mouse button is pressed down currently

getMouseDown(int i)
- Is used to see if a mouse button was pressed down

getMouseUp(int i)
- Is used to see if a mouse button is currently up

Class Entity:
Entity(float xPos, float yPos, float w, float h)
- xPos and yPos is the location of the entity on the window
- w and h are the height and width of the entity 

Struct Sprite:
Sprite(float x, float y, float w, float h)
- x and y are for the positions of the Sprite
- w and h are for the width and height of the sprite


Making a an empty engine
---------------------------------------------------------------
//create the engine
GOAT_Engine engine = new GOAT_Engine(800, 800, "Hello World");
//make a game loop
while (!engine->shouldClose()) {

		engine.draw();
	}
