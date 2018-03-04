#include "target.h"

/* ‘ункци€ дл€ получени€ рандомного числа
 * в диапазоне от минимального до максимального
 * */
static int randomBetween(int low, int high)
{
	return (qrand() % ((high + 1) - low) + low);
}

Target::Target(QObject *parent) : QObject(parent), QGraphicsItem()
{
	health = randomBetween(1, 15);  // «адаЄм случайное значение здоровь€
	maxHealth = health;				// ”станавливаем максимальное здоровье равным текущему
}

Target::~Target() = default;

QRectF Target::boundingRect() const
{
	return {-20, -20, 40, 40};  // ќграничиваем область, в которой лежит цель
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
				   QWidget *widget)
{
	/* ќтрисовываем зеленый квадрат
	 * */
	painter->setPen(Qt::black);
	painter->setBrush(Qt::green);
	painter->drawRect(-20, -10, 40, 30);

	/* ќтрисовываем полоску жизни
	 * соизмеримо текущему здоровью
	 * относительно максимального здоровь€
	 * */
	painter->setPen(Qt::NoPen);
	painter->setBrush(Qt::red);
	painter->drawRect(-20, -20, 40 * health / maxHealth, 3);

	Q_UNUSED(option);
	Q_UNUSED(widget);
}

void Target::hit(int damage)
{
	health -= damage;  // ”меньшаем здоровье мишени
	this->update(QRectF(-20, -20, 40,
						40));  // ѕерерисовываем мишень
							   // ≈сли здоровье закончилось, то инициируем смерть мишени
	if (health <= 0)
		this->deleteLater();
}
