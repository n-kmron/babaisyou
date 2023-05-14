#ifndef GUIACCUEIL_H
#define GUIACCUEIL_H

#include <QWidget>

namespace Ui {
class GuiAccueil;
}

class GuiAccueil : public QWidget
{
    Q_OBJECT

private slots:
    void startNewGame();
    void loadASave();

public:
    explicit GuiAccueil(QWidget *parent = nullptr);
    ~GuiAccueil();

private:
    Ui::GuiAccueil *ui;
};

#endif // GUIACCUEIL_H
