#pragma once  // Ui::widgetClass
#ifndef WIDGET_H
#define WIDGET_H

/*#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QWidget>*/

#include <customscene.h>

#include <tank.h>
#include "ui_widget.h"
#include <memory>

namespace Ui
{
	class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = nullptr);
	~Widget();

private:
	Ui::widgetClass *ui;						
	std::unique_ptr<CustomScene> scene;			/// ќбъ€вл€ем графическую сцену
};

#endif  // WIDGET_H
