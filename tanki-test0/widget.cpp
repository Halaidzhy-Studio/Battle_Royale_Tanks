#include "widget.h"
#include "ui_widget.h"

#include <bullet.h>
#include <target.h>


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::widgetClass)
{
	/// Устанавливаем параметры окна приложения
	this->resize(600, 600);
	this->setFixedSize(600, 600);

	ui->setupUi(this);
	scene = std::make_unique<CustomScene>();  /// Инициализируем кастомизированную сцену
	ui->graphicsView->setScene(scene.get());  /// Устанавливаем графическую сцену в graphicsView
	ui->graphicsView->setRenderHint(
		QPainter::Antialiasing);  /// Устанавливаем сглаживание
	ui->graphicsView->setVerticalScrollBarPolicy(
		Qt::ScrollBarAlwaysOff);  /// Отключаем скроллбар по вертикали
	ui->graphicsView->setHorizontalScrollBarPolicy(
		Qt::ScrollBarAlwaysOff);  /// Отключаем скроллбар по горизонтали

	/// Разрешаем отслеживание положение курсора мыши
	/// без необходимости нажатия на кнопки мыши
	/// Применяем это свойство именно для QGraphicsView,
	/// в котором установлена графическая сцена
	ui->graphicsView->setMouseTracking(true);

	/// Создаем кастомизированный курсор из ресурсного файла
	const QCursor cursor = QCursor(QPixmap(R"(.\Resources\cursor\cursorTarget.png)"));
	ui->graphicsView->setCursor(cursor);  /// Устанавливаем курсор в QGraphicsView

}

Widget::~Widget() { delete ui; }



