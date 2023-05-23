#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QWidget>
#include "guiview.h"
#include "../guicontroller.h"

namespace Ui {
class MenuView;
}

class MenuView : public QWidget
{
    Q_OBJECT

private slots:
    void startNewGame();
    void loadASave();


public:
    explicit MenuView(QWidget *parent = nullptr, GuiView *view = nullptr, GuiController *controller = nullptr);
    ~MenuView();

private:
    Ui::MenuView *ui;
    GuiView* view_;
    GuiController* controller_;
};

#endif // MENUVIEW_H
