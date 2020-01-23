#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	//make a variable for the string using std::string
	std::string outputString = "pos: ";
	//convert the mouseX and mouseY from ints to string
	outputString += std::to_string(input->getMouseX());
	outputString += " , ";
	outputString += std::to_string(input->getMouseY());
	//output the new string
	text.setString(outputString);
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::Black);

	distance.x = input->getMouseX();
	distance.y = input->getMouseY();
	(input->isMouseLDown()) {
		if () {

		}
	}


	/*int circlePos = input->getMouseX();
	circlePos += input->getMouseY();
	circle.getPosition(circlePos);
	*/


}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	//If W is pressed 
	if (input->isKeyDown(sf::Keyboard::W)) {
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "You pressed W\n";
	}

	// Try this for the mouse dragging
	/*if (lastMousePress) {
		if (input->isMouseLDown()) {
			isDragging = true;
		}
		else {
			isDragging = false;
		}

	}
	lastMousePress = input->isMouseLDown();
	*/

	//If J,K,L are pressed
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L)) {
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "You pressed J, K and L simultaneously\n";
	}

	//If Excape is pressed
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}


}

// Update game objects
void Level::update()
{
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	//make a variable for the string using std::string
	std::string outputString = "pos: ";
	//convert the mouseX and mouseY from ints to string
	outputString += std::to_string(input->getMouseX());
	outputString += " , ";
	outputString += std::to_string(input->getMouseY());
	//output the new string
	text.setString(outputString);
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::Black);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}