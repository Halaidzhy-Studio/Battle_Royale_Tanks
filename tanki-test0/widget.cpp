#include "widget.h"
#include "ui_widget.h"

#include <bullet.h>
#include <target.h>


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::widgetClass)
{
	/// ������������� ��������� ���� ����������
	this->resize(600, 600);
	this->setFixedSize(600, 600);

	ui->setupUi(this);
	scene = std::make_unique<CustomScene>();  /// �������������� ����������������� �����
	ui->graphicsView->setScene(scene.get());  /// ������������� ����������� ����� � graphicsView
	ui->graphicsView->setRenderHint(
		QPainter::Antialiasing);  /// ������������� �����������
	ui->graphicsView->setVerticalScrollBarPolicy(
		Qt::ScrollBarAlwaysOff);  /// ��������� ��������� �� ���������
	ui->graphicsView->setHorizontalScrollBarPolicy(
		Qt::ScrollBarAlwaysOff);  /// ��������� ��������� �� �����������

	/// ��������� ������������ ��������� ������� ����
	/// ��� ������������� ������� �� ������ ����
	/// ��������� ��� �������� ������ ��� QGraphicsView,
	/// � ������� ����������� ����������� �����
	ui->graphicsView->setMouseTracking(true);

	/// ������� ����������������� ������ �� ���������� �����
	const QCursor cursor = QCursor(QPixmap(R"(.\Resources\cursor\cursorTarget.png)"));
	ui->graphicsView->setCursor(cursor);  /// ������������� ������ � QGraphicsView

}

Widget::~Widget() { delete ui; }



