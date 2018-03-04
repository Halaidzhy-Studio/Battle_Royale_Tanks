#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class Sprite : public QObject, public QGraphicsItem
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
public:
	explicit Sprite(QPointF point, QObject *parent = 0);

	/* �������������� ��� ������������ ������� ������,
	 * ����� ���� ����� ������ ������ ������������
	 * */
	enum
	{
		Type = UserType + 1
	};

	// ����� �������������� ������� ��� ��������� ���� �������
	int type() const override;

//signals:

//public slots:

private slots:
	void nextFrame();  /// ���� ��� �������������� ������

private:
	void
	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	QRectF boundingRect() const override;

private:
	QTimer timer;		   /// ������ ��� �������� ������
	QPixmap *spriteImage;  /// QPixmap ��� ������� �� �������
	int currentFrame;	  /// ���������� �������� ����� � �������
};

#endif  // SPRITE_H
