#ifndef ENGINEQT_H
#define ENGINEQT_H

#include <engine.h>
#include <QApplication>
#include <utils/loggerinterface.h>
#include <objects/playinstance.h>
#include <GameMenu/gamemenu.h>

class EngineQT : public Engine, public QApplication
{
public:
    EngineQT() = delete;
    EngineQT(const EngineQT&) = delete;
    EngineQT& operator=(const EngineQT&) = delete;
    EngineQT(int& argc, char **argv);

    ~EngineQT() = default;
    void setGameData(const std::shared_ptr<GameData> & gameData) override;
    void setLogger(const std::shared_ptr<Logger> & logger) override;
    int startGame() override;

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<PlayInstance> game_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<GameMenu> gameMenu_;

};

#endif // ENGINEQT_H
