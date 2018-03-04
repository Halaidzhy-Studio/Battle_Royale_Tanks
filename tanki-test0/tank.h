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
	/// Сигнал для создания пули с параметрами траектории
	void signalBullet(QPointF start, QPointF end);

public slots:
	/// Слот для получения данных о положении курсора
	void slotTarget(QPointF point);
	/// слот для обработки разрешения стрельбы
	void slotShot(bool shot);

private:
	QRectF boundingRect() const override;
	void
	paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
	QPainterPath shape()
		const override;  // Функция, возвращающая форму фигуры, необходимо для обработки коллизий

private slots:
	void slotGameTimer();	/// Игровой слот
	void slotBulletTimer();  /// Слот проверки пули

private:
	bool shot;			  /// Переменная состояния стрельбы
	QTimer bulletTimer;  /// Таймер пули
	QTimer gameTimer;	/// Игровой таймер
	QPointF target;		  /// Положение курсора
	QPixmap *tankImage;   /// QPixmap для танка
};

#endif  // TRIANGLE_H
