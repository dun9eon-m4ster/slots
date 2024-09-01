#include "fpswidget.h"
#include "paintevent.h"
#include "painter.h"
#include "fpsevent.h"
#include "string"
#include "texture.h"
#include "texturemanager.h"

FpsWidget::FpsWidget(const Rect& _new_rect)
	: GraphicsObject(_new_rect)
{
}

void FpsWidget::handleEvent(Event* event)
{
	if (auto fps_event = dynamic_cast<FpsEvent*>(event))
	{
		updateFpsEvent(fps_event);
	}

	GraphicsObject::handleEvent(event);
}

void FpsWidget::paintEvent(PaintEvent* event)
{
	event->painter()->setRenderColor(0x00FF69B4);
	event->painter()->drawRect(rect());

	for (auto it = paint_data_array.begin(); it != paint_data_array.end(); it++)
	{
		event->painter()->drawTexture(it->second, it->first);
	}
}

void FpsWidget::updateFpsEvent(FpsEvent* event)
{
	if (rect().width() <= 0)
		return;

	auto string = std::to_string(event->count());
	if (string.empty())
		return;

	paint_data_array.clear();

	int digit_count = string.size();
	int digit_width = rect().width() / digit_count;
	
	for (int i = 0; i < digit_count; i++)
	{
		std::string texture_file_name(string.at(i) + std::string(".bmp"));
		Rect _new_rect(	rect().x() + digit_width * i,
						rect().y(), 
						digit_width, 
						rect().height());
		
		paint_data_array.push_back(
			std::pair<Rect, 
			std::shared_ptr<Texture>>(_new_rect, TextureManager::instance()->texture(texture_file_name)));
	}
}
