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
	setRotation(0);  /// ������������� �������� �������� ������������

	target = QPointF(0, 0);  /// ������������� ����������� ��������� �������
	shot = false;

	/// ���������� ������ �� ������� � ����� ��������� �������� �������
	connect(&gameTimer, &QTimer::timeout, this, &Tank::slotGameTimer);
	gameTimer.start(5);  /// �������� ������

	connect(&bulletTimer, &QTimer::timeout, this, &Tank::slotBulletTimer);
	bulletTimer.start(1000 / 6);  /// �������� 6 ��� � �������

	tankImage = new QPixmap(R"(.\Resources\sprites\tan4.png)");
}

Tank::~Tank() = default;

// ����������  �������
QRectF Tank::boundingRect() const
{
	//return {-12, -15, 24, 30};
	return { -45, -50, 90, 100 };
}

// ���������� ����� 
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
	/// ��������� �����
	 
	/*QPolygon polygon;
	polygon << QPoint(0, -15) << QPoint(12, 15) << QPoint(-12, 15);
	painter->setBrush(Qt::red);
	painter->drawPolygon(polygon);*/

	painter->drawPixmap(-30, -50, *tankImage, 40, 0, 60, 100);
	painter->rotate(/*currentFrame*/0); /// ���� �������� �����
	painter->drawPixmap(-20, -80, *tankImage, 0, 0, 40, 100);

	Q_UNUSED(option);
	Q_UNUSED(widget);
}

// ���� ��������� ������� �� �����
void Tank::slotTarget(QPointF point)
{
	target = point;
}

void Tank::slotGameTimer()
{
	/** ���������� ����������� � ����������� �� ������� ������
	 * */
	if (GetAsyncKeyState('A'))
	{
		this->setX(this->x() - 1);
		/* ��������� �� ������������,
		 * ���� ������������ ���������,
		 * �� ���������� ����� ������� � �������� �����
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
	/// ���� �������� � ����������� � ����
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
	/// ���� �������� ���������, �� �������� ������ �� �������� ����
	if (shot)
		emit signalBullet(mapToScene(0, -25), target);
}

void Tank::slotShot(bool shot)
{
	this->shot = shot;  /// �������� ���������� ��� ������ �� ��������
}
