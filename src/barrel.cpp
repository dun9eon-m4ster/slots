#include "barrel.h"
#include "paintevent.h"
#include "painter.h"
#include "buttonclickevent.h"
#include "iostream"

void drawElements(Painter* painter, const Rect &rect, Uint32 offset)
{
	int margin_top		= 10;
	int margin_bottom	= 10;
	int margin_left		= 10;
	int margin_right	= 10;
	int spacing = 5;

	int element_height = (rect.height() - margin_top - margin_bottom - spacing * 2 ) / 3;


	painter->setRenderColor(Color::Red);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + margin_top + offset,
							rect.width() - margin_left - margin_right,
							element_height));

	painter->setRenderColor(Color::Green);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + element_height + spacing + margin_top + offset,
							rect.width() - margin_left - margin_right,
							element_height));

	painter->setRenderColor(Color::Blue);
	painter->drawRect(Rect(	rect.x() + margin_left,
							rect.y() + element_height*2 + spacing*2 + margin_top + offset,
							rect.width() - margin_left - margin_right,
							element_height));
}



Barrel::Barrel(const Rect& _new_rect, const uint32_t &_new_spinning_speed, const uint32_t &_new_duration)
	:	GraphicsObject(_new_rect),
		_state(Waiting),
		spinning_speed(_new_spinning_speed),
		duration(_new_duration)
{
}

bool Barrel::isSpinning() const
{
	return animation.isRunning();
}

void Barrel::start()
{
	if (isSpinning())
		return;

	animation.setValueRange(0, rect().height());
	animation.setTick(16);
	animation.setSpeed(spinning_speed);
	animation.start(duration);
}

void Barrel::handleEvent(Event* event)
{
	if (dynamic_cast<ButtonClickEvent*>(event))
	{
		start();
	}

	GraphicsObject::handleEvent(event);
}

void Barrel::paintEvent(PaintEvent* event)
{
	auto painter = event->painter();
	auto sdl_renderer = painter->sdlRenderer();

	auto tmp_texture = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rect().width(), rect().height());
	SDL_Rect texture_rect{0, 0, rect().width(), rect().height()};

	SDL_SetRenderTarget(sdl_renderer, tmp_texture);
	SDL_SetRenderDrawColor(sdl_renderer, 0xaf, 0xaf, 0xaf, 0xff);
	SDL_RenderFillRect(sdl_renderer, &texture_rect);



	int margin_top = 10;
	int margin_bottom = 10;
	int margin_left = 10;
	int margin_right = 10;
	int spacing = 5;

	int element_height = (rect().height() - margin_top - margin_bottom - spacing * 2) / 3;


	SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 0);
	auto rect1 = Rect(0 + margin_left,
		0 + margin_top,
		rect().width() - margin_left - margin_right,
		element_height).sdlRect();
	SDL_RenderFillRect(sdl_renderer, &rect1);

	SDL_SetRenderDrawColor(sdl_renderer, 0, 255, 0, 0);
	auto rect2 = Rect(0 + margin_left,
		0 + element_height + spacing + margin_top,
		rect().width() - margin_left - margin_right,
		element_height).sdlRect();
	SDL_RenderFillRect(sdl_renderer, &rect2);

	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 255, 0);
	auto rect3 = Rect(0 + margin_left,
		0 + element_height * 2 + spacing * 2 + margin_top,
		rect().width() - margin_left - margin_right,
		element_height).sdlRect();
	SDL_RenderFillRect(sdl_renderer, &rect3);


	uint32_t offset = animation.currentValue();

	SDL_SetRenderTarget(sdl_renderer, NULL);

	if (offset == 0)
	{
		auto sdl_rect = rect().sdlRect();
		SDL_RenderCopy(sdl_renderer, tmp_texture, NULL, &sdl_rect);
	}
	else
	{
		SDL_Rect src_rect1{ 0, 0, rect().width(), rect().height() - offset};
		SDL_Rect src_rect2{ 0, src_rect1.h, rect().width(), offset};
	
		SDL_Rect dist_rect1{ rect().x(), rect().y() + offset, rect().width(), rect().height()-offset};
		SDL_Rect dist_rect2{ rect().x(), rect().y(), rect().width(), offset};

		SDL_RenderCopy(sdl_renderer, tmp_texture, &src_rect1, &dist_rect1);
		SDL_RenderCopy(sdl_renderer, tmp_texture, &src_rect2, &dist_rect2);
	}
	

	SDL_DestroyTexture(tmp_texture);
}
