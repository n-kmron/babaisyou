#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QWidget>

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
    explicit MenuView(QWidget *parent = nullptr);
    ~MenuView();

private:
    Ui::MenuView *ui;
};

#endif // MENUVIEW_H
