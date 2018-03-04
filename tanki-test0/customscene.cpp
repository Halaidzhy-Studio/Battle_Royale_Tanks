#include "customscene.h"
#include "bullet.h"
#include "target.h"

/** Функция для получения рандомного числа
* в диапазоне от минимального до максимального */
static int randomBetween(int low, int high)
{
	return (qrand() % ((high + 1) - low) + low);
}


CustomScene::CustomScene(QObject *parent) : QGraphicsScene()
{
	this->setSceneRect(0, 0, 520, 520);  /// Устанавливаем размеры графической сцены

	// Поставим стены
	this->addRect(0, 0, 520, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(0, 0, 20, 520, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(0, 500, 520, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(500, 0, 20, 520, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(170, 250, 180, 20, QPen(Qt::NoPen), QBrush(Qt::darkGray));
	this->addRect(250, 170, 20, 180, QPen(Qt::NoPen), QBrush(Qt::darkGray));

	tank = new Tank();			  /// Инициализируем треугольник
	tank->setPos(60*2, 60*2);			  /// Устанавливаем стартовую позицию треугольника
	tank->setZValue(2);               /// Устанавливаем приоритет отрисовки
	this->addItem(tank);  /// Добавляем треугольник на графическую сцену

	/// Подключаем сигнал от графической сцены к слоту треугольника
	connect(this, &CustomScene::signalTargetCoordinate, tank, &Tank::slotTarget);
	/// Соединяем сигнала стрельбы с графической сцены со слотом разрешения стрельбы
	/// треугольника
	connect(this, &CustomScene::signalShot, tank, &Tank::slotShot);

	/// Соединяем сигнал на создание пули со слотом, создающим пули в игре
	connect(tank, &Tank::signalBullet, this, &CustomScene::slotBullet);

	/// Инициализируем таймер для создания мишеней
	connect(&timerTarget, &QTimer::timeout, this, &CustomScene::slotCreateTarget);
	timerTarget.start(1500);

	Q_UNUSED(parent);
}

void CustomScene::slotCreateTarget()
{
	Target *target = new Target();  /// Создаём цель
	this->addItem(target);			/// Помещаем цель в сцену со случайной позицией
	target->setPos(qrand() % ((500 - 40 + 1) - 40) + 40,
	qrand() % ((500 - 40 + 1) - 40) + 40);
	target->setZValue(-1);   /// Помещаем цель ниже Героя
	targets.insert(target); /// Добавляем цель в список
}

void CustomScene::slotBullet(QPointF start, QPointF end)
{
	/// Добавляем на сцену пулю
	Bullet *bullet = new Bullet(start, end, tank);
	bullet->setCallbackFunc(slotHitTarget);
	this->addItem(bullet);
}

void CustomScene::slotHitTarget(QGraphicsItem *item)
{
	/** Получив сигнал от Пули
	* Перебираем весь список целей и наносим ему случайный урон
	* */
	
	/*for (QGraphicsItem *targ : targets)
	{
		if (targ == item)
		{
			/// Кастуем объект из списка в класс Target
			Target *t = qgraphicsitem_cast<Target *>(targ);
			t->hit(randomBetween(1, 3));  /// Наносим урон
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

std::set<QGraphicsItem *> CustomScene::targets;  /// реализация списка

CustomScene::~CustomScene() = default;

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	emit signalTargetCoordinate(event->scenePos());
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	emit signalShot(true);  /// Когда клавиша мыши нажата, то можно стрелять
	Q_UNUSED(event);
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	emit signalShot(false);  /// Когда клавишу мыши отпустили, то стрелять нельзя
	Q_UNUSED(event);
}
