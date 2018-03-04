#include "sprite.h"

Sprite::Sprite(QPointF point, QObject *parent) : QObject(parent), QGraphicsItem()
{
	this->setPos(point);  // ������������� ������� ������
	currentFrame = 0;	 /// ���������� X ������ ������ ����
	spriteImage = new QPixmap(R"(./Resources/sprites/sprite_sheet.png)");

	
						   /// ���������� ������ �� ������� � ����� �������� ������
	connect(&timer, &QTimer::timeout, this, &Sprite::nextFrame);
	timer.start(25);  /// �������� ������ � �������� 25 ����������
}

QRectF Sprite::boundingRect() const { return {-10, -10, 20, 20}; }

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
				   QWidget *widget)
{
	// ������������ ���� �� ������ ������
	painter->drawPixmap(-10, -10, *spriteImage, currentFrame, 0, 20, 20);
	Q_UNUSED(option);
	Q_UNUSED(widget);
}

void Sprite::nextFrame()
{
	currentFrame += 20;  // ���������� ���������� X ��� ������ ���������� �����
	if (currentFrame >= 300)
	{
		this->deleteLater();  // ���� ����� �����������, �� ������� ������ ������
	}
	else
	{
		this->update(-10, -10, 20,
					 20);  // � ��������� ������ ��������� ����������� ������
	}
}

int Sprite::type() const
{
	// ���������� ��� �������
	return Type;
}
