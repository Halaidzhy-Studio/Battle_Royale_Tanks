#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <QDebug>
//#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
//#include <QPainter>
//#include <QTimer>

#include <sprite.h>

class Bullet : public QObject, public QGraphicsItem
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
public:
	explicit Bullet(QPointF start, QPointF end, QGraphicsItem *hero, QObject *parent = nullptr);
	~Bullet();
	/// ��������� CallBack �������
	void setCallbackFunc(std::function<void(QGraphicsItem *item)> func);
	
//signals:

//public slots:

private:
	QRectF boundingRect() const override;
	void
	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

	/// ��������� ��������� CallBack �������
	std::function<void(QGraphicsItem *item)> callbackFunc;

private:
	QTimer timerBullet;  /// ���� ��� ��������� ������� ����
						 
	QGraphicsItem *hero;
private slots:
	void slotTimerBullet();  /// ���� ��� ��������� ����� ����
};

#endif  // BULLET_H
