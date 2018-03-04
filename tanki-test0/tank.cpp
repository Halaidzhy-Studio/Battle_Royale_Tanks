#include "tank.h"
#include <cmath>

#include <Windows.h>

static const double Pi = 3.1415926535897932384;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
	while (angle < 0) angle += TwoPi;
	while (angle > TwoPi) angle -= TwoPi;
	return angle;
}

Tank::Tank(QObject *parent) : QObject(parent), QGraphicsItem()
{
	setRotation(0);  /// Устанавливаем исходный разворот треугольника

	target = QPointF(0, 0);  /// Устанавливаем изначальное положение курсора
	shot = false;

	/// Подключаем сигнал от таймера и слоту обработки игрового таймера
	connect(&gameTimer, &QTimer::timeout, this, &Tank::slotGameTimer);
	gameTimer.start(5);  /// Стартуем таймер

	connect(&bulletTimer, &QTimer::timeout, this, &Tank::slotBulletTimer);
	bulletTimer.start(1000 / 6);  /// Стреляем 6 раз в секунду

	tankImage = new QPixmap(R"(.\Resources\sprites\tan4.png)");
}

Tank::~Tank() = default;

// Возвращаем  размеры
QRectF Tank::boundingRect() const
{
	//return {-12, -15, 24, 30};
	return { -45, -50, 90, 100 };
}

// Возвращаем форму 
QPainterPath Tank::shape() const
{
	QPainterPath path;
	/*path.addEllipse(boundingRect());*/
	QPolygon polygon;
	polygon << QPoint(-30, -50) << QPoint(30, -50) << QPoint(30, 50) << QPoint(-30, 50);
	path.addPolygon(polygon);
	return path;
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
					 QWidget *widget)
{
	/// Отрисовка танка
	 
	/*QPolygon polygon;
	polygon << QPoint(0, -15) << QPoint(12, 15) << QPoint(-12, 15);
	painter->setBrush(Qt::red);
	painter->drawPolygon(polygon);*/

	painter->drawPixmap(-30, -50, *tankImage, 40, 0, 60, 100);
	painter->rotate(/*currentFrame*/0); /// угол поворота пушки
	painter->drawPixmap(-20, -80, *tankImage, 0, 0, 40, 100);

	Q_UNUSED(option);
	Q_UNUSED(widget);
}

// слот получение сигнала от мышки
void Tank::slotTarget(QPointF point)
{
	target = point;
}

void Tank::slotGameTimer()
{
	/** Перемещаем треугольник в зависимости от нажатых кнопок
	 * */
	if (GetAsyncKeyState('A'))
	{
		this->setX(this->x() - 1);
		/* Проверяем на столкновение,
		 * если столкновение произошло,
		 * то возвращаем героя обратно в исходную точку
		 * */
		if (!scene()->collidingItems(this).isEmpty())
		{
			this->setX(this->x() + 1);
		}
	}
	if (GetAsyncKeyState('D'))
	{
		this->setX(this->x() + 1);
	
		if (!scene()->collidingItems(this).isEmpty())
		{
			this->setX(this->x() - 1);
		}
	}
	if (GetAsyncKeyState('W'))
	{
		this->setY(this->y() - 1);
		if (!scene()->collidingItems(this).isEmpty())
		{
			this->setY(this->y() + 1);
		}
	}
	if (GetAsyncKeyState('S'))
	{
		this->setY(this->y() + 1);
		if (!scene()->collidingItems(this).isEmpty())
		{
			this->setY(this->y() - 1);
		}
	}


	QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
	/// Угол поворота в направлении к цели
	qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
	if (lineToTarget.dy() < 0)
		angleToTarget = TwoPi - angleToTarget;
	angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

	if (angleToTarget >= 0 && angleToTarget < Pi)
	{
		/// Rotate left
		setRotation(rotation() - angleToTarget * 180 / Pi);
	}
	else if (angleToTarget <= TwoPi && angleToTarget > Pi)
	{
		/// Rotate right
		setRotation(rotation() + (angleToTarget - TwoPi) * (-180) / Pi);
	}
}

void Tank::slotBulletTimer()
{
	/// Если стрельба разрешена, то вызываем сигнал на создание пули
	if (shot)
		emit signalBullet(mapToScene(0, -25), target);
}

void Tank::slotShot(bool shot)
{
	this->shot = shot;  /// Получаем разрешение или запрет на стрельбу
}
