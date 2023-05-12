#ifndef GUIVIEW_H
#define GUIVIEW_H

#include "model/observer.h"
#include "view.h"
#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>
#include <QString>

namespace Ui {
    class GuiView;
}

class GuiView : public QMainWindow, public View, public Observer
{
    Q_OBJECT

private:
    Ui::GuiView *ui;

    QGraphicsScene scene_;

    std::vector<std::vector<Element>> getPositionsMap(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements);

    void displayImage(const QString& path, int height, int width);

protected:

    bool eventFilter(QObject *obj, QEvent *event) override;

public:
    explicit GuiView(QWidget *parent = nullptr);
    ~GuiView();

    void displayTitle() override;

    void displayBoard(const std::pair<unsigned int, unsigned int> & sizes, const std::vector<GameObject> & elements) override;

    void displayWon() override;

    void displayNextLevel(unsigned int actualLevel) override;

    void displayKilled() override;

    void displayError(std::string message) override;

    /**
     * @brief asks user if he wants to overwrite a save
     */
    bool overwriteSave();

    unsigned int displayUserSaves() override;

    std::string askWhichLevel() override;

    std::string askDir() override;

    bool askRestart() override;

    void askSave() override;

    void update(std::pair<unsigned int, unsigned int> sizes, std::vector<GameObject> elements) override;
};

#endif // GUIVIEW_H
