//included library section

#include <SFML/Graphics.hpp>


//entry point for the program
int main()
{
	//game setup-------------------------------------------------------------------


	// make a variable called a gamewindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "button masher",
		sf::Style::Titlebar | sf::Style::Close);

	//create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");


	//game loop-------------------------------------------------------------------
	//runs every frame untill the game window is closed
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			//TOD:process events

			// check if the event is the close event
			if (gameEvent.type == sf::Event::Closed)
			{
				//close the game window
				gameWindow.close();
			}
		}



		// TODO: update game state

		// TODO: Draw graphics 

	}

	//exit pointfor the program
	return 0;
}