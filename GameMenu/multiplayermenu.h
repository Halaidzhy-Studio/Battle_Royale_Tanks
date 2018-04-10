#ifndef MULTIPLAYERMENU_H
#define MULTIPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>

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
    QLabel* multiplayerMenuTitle_;
    QListWidget* roomsList_;

    void createRoomsListElement(QListWidget*);
};

#endif // MULTIPLAYERMENU_H
