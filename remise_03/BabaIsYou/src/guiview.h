#ifndef GUIVIEW_H
#define GUIVIEW_H

#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>

namespace Ui {
class GuiView;
}

class GuiView : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuiView(QWidget *parent = nullptr);
    ~GuiView();

private:
    Ui::GuiView *ui;

    QGraphicsScene scene_;
};

#endif // GUIVIEW_H
