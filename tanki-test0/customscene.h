#pragma once
#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

//#include <QDebug>
//#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "tank.h"
#include <set>

//#include <QObject>

class CustomScene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit CustomScene(QObject *parent = nullptr);
	~CustomScene();

signals:
	/// Сигнал для передачи координат положения курсора мыши
	void signalTargetCoordinate(QPointF point);
	void signalShot(bool shot);  /// Сигнал на стрельбу

private slots:
	void slotBullet(QPointF start, QPointF end);  /// Слот для создания пули
	void slotCreateTarget();						// Слот для создания мишеней

private:
	/// Функция, в которой производится отслеживание положения мыши
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

	static void slotHitTarget(QGraphicsItem *item);  // CallBack Функция

	Tank *tank;						/// Объявляем треугольник
	static std::set<QGraphicsItem *> targets;  // Список мишеней
	QTimer timerTarget;					// Таймер для создания мишеней
};

#endif  // CUSTOMSCENE_H
