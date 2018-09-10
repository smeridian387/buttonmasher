//included library section

#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
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

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);
	//create music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();

	//create font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//create title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color::Red);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);

	//create author text
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Allen Montgomery");
	authorText.setCharacterSize(40);
	authorText.setFillColor(sf::Color::White);
	authorText.setStyle(sf::Text::Bold | sf::Text::Italic);
	authorText.setPosition(gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 150);

	//score
	int score = 0;

	//score text
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score "+ std::to_string(score));
	scoreText.setCharacterSize(16);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(30, 30);
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
		score = score + 1;
		scoreText.setString("Score " + std::to_string(score));

		
		//Clear the window to a single color
		gameWindow.clear(sf::Color::Black);

		//draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		//Display window content on screen
		gameWindow.display();
	}	
	//exit pointfor the program
	return 0;
}