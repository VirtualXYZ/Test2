#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 480), "Steg 2");
	sf::View view(sf::FloatRect(0, 0, 800, 400));

	sf::Texture texture;

	if (!texture.loadFromFile("Test_Chunck.jpg"))
	{
		// error...
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);


	// Update-loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.setView(view);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			view.move(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			view.move(-1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			view.move(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			view.move(0, 1);
		}

		if (view.getViewport().left <= 0)
		{
			view.setViewport(sf::FloatRect(0, view.getViewport().top, 800, 400));
		}

		window.clear();

		window.draw(sprite);

		window.display();
	}
	return 0;
}