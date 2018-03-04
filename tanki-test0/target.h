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
	/* ������� �� ��������� �����,
	 * �������� ����� ��������� � �������� ��������� �������
	 * */
	void hit(int damage);

//signals:

//public slots:

protected:
	QRectF boundingRect() const override;
	void
	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	int health;		// ������� ����� �������� ������
	int maxHealth;  // ������������ ����� �������� ������
};

#endif  // TARGET_H
