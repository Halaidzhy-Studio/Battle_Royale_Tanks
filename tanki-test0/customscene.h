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
	/// ������ ��� �������� ��������� ��������� ������� ����
	void signalTargetCoordinate(QPointF point);
	void signalShot(bool shot);  /// ������ �� ��������

private slots:
	void slotBullet(QPointF start, QPointF end);  /// ���� ��� �������� ����
	void slotCreateTarget();						// ���� ��� �������� �������

private:
	/// �������, � ������� ������������ ������������ ��������� ����
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

	static void slotHitTarget(QGraphicsItem *item);  // CallBack �������

	Tank *tank;						/// ��������� �����������
	static std::set<QGraphicsItem *> targets;  // ������ �������
	QTimer timerTarget;					// ������ ��� �������� �������
};

#endif  // CUSTOMSCENE_H
