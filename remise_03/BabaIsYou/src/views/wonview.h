#ifndef WONVIEW_H
#define WONVIEW_H

#include <QWidget>

namespace Ui {
class WonView;
}

class WonView : public QWidget
{
    Q_OBJECT

private slots:
    void displayMenu();

public:
    explicit WonView(QWidget *parent = nullptr);
    ~WonView();

private:
    Ui::WonView *ui;
};

#endif // WONVIEW_H
