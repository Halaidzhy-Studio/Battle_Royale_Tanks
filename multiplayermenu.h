#ifndef MULTIPLAYERMENU_H
#define MULTIPLAYERMENU_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class MultiplayerMenu;
}

class MultiplayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerMenu(QWidget *parent = 0);
    ~MultiplayerMenu();

signals:
    void mainWindow();
public slots:
    void backToMainWindow();
private:
    Ui::MultiplayerMenu *ui;
    QPushButton* backToMainWindowBTN_;
};

#endif // MULTIPLAYERMENU_H
