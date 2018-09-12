//included library section

#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
//entry point for the program
int main()
{
	//game setup-------------------------------------------------------------------

	//is the game playing or not? bool
	bool playing = false;

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
	gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);

	//create music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();

	//create clicking sound effect
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);


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

	//timer text
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gameWindow.getSize().x - timerText.getLocalBounds().width - 30, 30);

	//add timer
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;



	//game loop-------------------------------------------------------------------
	//runs every frame untill the game window is closed
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			//TOD:process events
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					if (playing == true)
					{
						//add 1 to the score when the player clicks on the button
						score = score + 1;
						//play the click sound when the player clicks the button
						clickSound.play();
					}
					else
					{
						playing = true;
						score = 0;
						timeRemaining = timeLimit;
					}
					
				}
			}
			// check if the event is the close event
			if (gameEvent.type == sf::Event::Closed)
			{
				//close the game window
				gameWindow.close();
			}
		}

		//update the clock each frame
		sf::Time frameTime = gameClock.restart();
		if (playing == true)
		{
			timeRemaining = timeRemaining - frameTime;
			if (timeRemaining.asSeconds() <= 0)
			{
				playing = false;
			}
		}
		
		timerText.setString("Time Remaining: " + std::to_string((int)timeRemaining.asSeconds()));

		// TODO: update game state
		scoreText.setString("Score " + std::to_string(score));

		
		//Clear the window to a single color
		gameWindow.clear(sf::Color::Black);

		//draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);
		//Display window content on screen
		gameWindow.display();
	}	
	//exit pointfor the program
	return 0;
}