#include "bullet.h"
#include <cmath>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
	while (angle < 0) angle += TwoPi;
	while (angle > TwoPi) angle -= TwoPi;
	return angle;
}

Bullet::Bullet(QPointF start, QPointF end, QGraphicsItem *hero, QObject *parent)
	: QObject(parent), QGraphicsItem()
{
	this->hero = hero;	 
	this->setRotation(0);  /// ������������� ��������� ��������
	this->setPos(start);   /// ������������� ��������� �������
						   /// ���������� ���������� ����� ����
	QLineF lineToTarget(start, end);
	/// ���� �������� � ����������� � ����
	qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
	if (lineToTarget.dy() < 0)
		angleToTarget = TwoPi - angleToTarget;
	angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

	/** ������������� ���� �� ����������
	 * */
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

	/// � ���������� ��� � ����� ��� ��������� ����� ����
	connect(&timerBullet, &QTimer::timeout, this, &Bullet::slotTimerBullet);
	timerBullet.start(7);
}

Bullet::~Bullet() = default;

QRectF Bullet::boundingRect() const { return {0, 0, 2, 4}; }

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
				   QWidget *widget)
{
	painter->setPen(Qt::black);
	painter->setBrush(Qt::black);
	painter->drawRect(0, 0, 2, 4);

	Q_UNUSED(option);
	Q_UNUSED(widget);
}

void Bullet::slotTimerBullet()
{
	setPos(mapToParent(0, -10));

	/** ���������� �������� �� ��, ���������� �� ���� �� �����-������
	 * ������� �� ����������� �����.
	 * ��� ����� ���������� ��������� ������� ����� �����,
	 * � ������� ����� ������ ��������
	 * */
	QList<QGraphicsItem *> foundItems = scene()->items(
		QPolygonF() << mapToScene(0, 0) << mapToScene(-1, -1) /*<< mapToScene(1, -1)*/);
	/** ����� ���� ��������� ��� ��������.
	 * ������ �� ��� ����� ���� ���� � ����� - � ���� ������ �� ������.
	 * � � ���������� �������� CallBack �������
	 * */
	for (QGraphicsItem *item : foundItems)
	{
		/* ��������� � �������� ��� � ���� ������,
		 * ����� ���� �� ������������ � �� ����������
		 * ����� �� ������ �� ������ ����
		 * */
		if (item == this || item == hero || item->type() == (UserType + 1))
			continue;
		// ��� ��������� �� ���� ��� �����������, �������� �����
		scene()->addItem(new Sprite(this->pos()));
		callbackFunc(item);   // �������� CallBack �������
		this->deleteLater();  // ���������� ����
	}

}

void Bullet::setCallbackFunc(std::function<void(QGraphicsItem *item)> func)
{
	callbackFunc = func;
}
