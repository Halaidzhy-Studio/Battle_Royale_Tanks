#include "customscene.h"
#include "bullet.h"
#include "target.h"

/** ������� ��� ��������� ���������� �����
* � ��������� �� ������������ �� ������������� */
static int randomBetween(int low, int high)
{
	return (qrand() % ((high + 1) - low) + low);
}


CustomScene::CustomScene(QObject *parent) : QGraphicsScene()
{
	this->setSceneRect(0, 0, 520, 520);  /// ������������� ������� ����������� �����

	// �������� �����
	this->addRect(0, 0, 520, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(0, 0, 20, 520, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(0, 500, 520, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(500, 0, 20, 520, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(170, 250, 180, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(250, 170, 20, 180, QPen(Qt::NoPen), QBrush(Qt::darkGray));

	tank = new Tank();			  /// �������������� �����������
	tank->setPos(60*2, 60*2);			  /// ������������� ��������� ������� ������������
	tank->setZValue(2);               /// ������������� ��������� ���������
	this->addItem(tank);  /// ��������� ����������� �� ����������� �����

	/// ���������� ������ �� ����������� ����� � ����� ������������
	connect(this, &CustomScene::signalTargetCoordinate, tank, &Tank::slotTarget);
	/// ��������� ������� �������� � ����������� ����� �� ������ ���������� ��������
	/// ������������
	connect(this, &CustomScene::signalShot, tank, &Tank::slotShot);

	/// ��������� ������ �� �������� ���� �� ������, ��������� ���� � ����
	connect(tank, &Tank::signalBullet, this, &CustomScene::slotBullet);

	/// �������������� ������ ��� �������� �������
	connect(&timerTarget, &QTimer::timeout, this, &CustomScene::slotCreateTarget);
	timerTarget.start(1500);

	Q_UNUSED(parent);
}

void CustomScene::slotCreateTarget()
{
	Target *target = new Target();  /// ������ ����
	this->addItem(target);			/// �������� ���� � ����� �� ��������� ��������
	target->setPos(qrand() % ((500 - 40 + 1) - 40) + 40,
	qrand() % ((500 - 40 + 1) - 40) + 40);
	target->setZValue(-1);   /// �������� ���� ���� �����
	targets.insert(target); /// ��������� ���� � ������
}

void CustomScene::slotBullet(QPointF start, QPointF end)
{
	/// ��������� �� ����� ����
	Bullet *bullet = new Bullet(start, end, tank);
	bullet->setCallbackFunc(slotHitTarget);
	this->addItem(bullet);
}

void CustomScene::slotHitTarget(QGraphicsItem *item)
{
	/** ������� ������ �� ����
	* ���������� ���� ������ ����� � ������� ��� ��������� ����
	* */
	
	/*for (QGraphicsItem *targ : targets)
	{
		if (targ == item)
		{
			/// ������� ������ �� ������ � ����� Target
			Target *t = qgraphicsitem_cast<Target *>(targ);
			t->hit(randomBetween(1, 3));  /// ������� ����
			break;
		}
	}//*/

	const auto it = targets.find(item);
	if (it != targets.end())
	{
		Target *t = qgraphicsitem_cast<Target *>(*it);
		t->hit(randomBetween(1, 3));
	}
}

std::set<QGraphicsItem *> CustomScene::targets;  /// ���������� ������

CustomScene::~CustomScene() = default;

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	emit signalTargetCoordinate(event->scenePos());
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	emit signalShot(true);  /// ����� ������� ���� ������, �� ����� ��������
	Q_UNUSED(event);
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	emit signalShot(false);  /// ����� ������� ���� ���������, �� �������� ������
	Q_UNUSED(event);
}
