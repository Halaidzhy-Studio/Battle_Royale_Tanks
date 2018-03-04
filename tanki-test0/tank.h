#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

//#include <QCursor>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
//#include <QPolygon>
#include <QTimer>



class Tank : public QObject, public QGraphicsItem
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
public:
	explicit Tank(QObject *parent = nullptr);
	~Tank();

signals:
	/// ������ ��� �������� ���� � ����������� ����������
	void signalBullet(QPointF start, QPointF end);

public slots:
	/// ���� ��� ��������� ������ � ��������� �������
	void slotTarget(QPointF point);
	/// ���� ��� ��������� ���������� ��������
	void slotShot(bool shot);

private:
	QRectF boundingRect() const override;
	void
	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	QPainterPath shape()
		const override;  // �������, ������������ ����� ������, ���������� ��� ��������� ��������

private slots:
	void slotGameTimer();	/// ������� ����
	void slotBulletTimer();  /// ���� �������� ����

private:
	bool shot;			  /// ���������� ��������� ��������
	QTimer bulletTimer;  /// ������ ����
	QTimer gameTimer;	/// ������� ������
	QPointF target;		  /// ��������� �������
	QPixmap *tankImage;   /// QPixmap ��� �����
};

#endif  // TRIANGLE_H
