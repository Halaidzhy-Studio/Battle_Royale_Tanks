#pragma once
#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Target : public QObject, public QGraphicsItem
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
public:
	explicit Target(QObject *parent = 0);
	~Target();
	/* Функция по нанесению урона,
	 * величина урона передаётся в качестве аргумента функции
	 * */
	void hit(int damage);

//signals:

//public slots:

protected:
	QRectF boundingRect() const override;
	void
	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	int health;		// Текущий запас здоровья мишени
	int maxHealth;  // Максимальный запас здоровья мишени
};

#endif  // TARGET_H
