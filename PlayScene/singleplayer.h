#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Singleplayer;
}

class Singleplayer : public QWidget
{
    Q_OBJECT

public:
    explicit Singleplayer(QWidget *parent = 0);
    ~Singleplayer();

signals:
    void mainWindow();

public slots:
    void backToMainWindow();
private:
    Ui::Singleplayer *ui;
    QPushButton* backToMainWindowBTN_;

};

#endif // SINGLEPLAYER_H
