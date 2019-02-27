#include "Player.h"
#include "Input.h"

Player::Player(Vector2 position, Model model) : Entity(position, model)
{

}

void Player::Update()
{
	if(Input::KeyPressed(GLFW_KEY_W))
	{
		position.y++;
	}
}