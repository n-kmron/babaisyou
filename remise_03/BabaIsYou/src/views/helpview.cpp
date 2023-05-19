#include "helpview.h"
#include "ui_helpview.h"

HelpView::HelpView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpView)
{
    ui->setupUi(this);
}

HelpView::~HelpView()
{
    delete ui;
}


/*void GuiView::displayHelp() {
    QString content=QObject::tr("<!DOCTYPE html>"
                                  "<html>"
                                  "<head>"
                                  "<meta charset=\"utf-8\">"
                                  "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
                                  "<title></title>"
                                  "</head>"
                                  "<body>"
                                  "<style>"
                                  "#basDroit{"
                                  "text-align:right;"
                                  "}"
                                  "</style>"
                                  "<div id=\"centre\">"
                                  "<p>Baba Is You est un jeu de type puzzle :</p>"
                                  "<br>"
                                  "<ul>"
                                  "<li>"
                                  "Les règles sont directement sur le plateau;"
                                  "</li>"
                                  "<li>"
                                  "Toute les objets sur la map peuvent potentielement être bougés;"
                                  "</li>"
                                  "<li>"
                                  "Toute les objets sur la map peuvent potentielement être bougés;"
                                  "</li>"
                                  "</ul>"
                                  "<br>"
                                  "<p>"
                                  "Notez que n'importe quel objet peut incarner un autre objet(exemple:Rock Is Baba)."
                                  "</p>"
                                  "<br>"
                                  "<p>"
                                  "Veillez à sauvegarder votre avancement et n'oubliez pas que vous pouvez a n'importe quel moment restart le niveau dans le quel vous êtes."
                                  "</p>"
                                  "</div>"
                                  "<div id=\"basDroit\">"
                                  "<label><strong>Bon amusement!</strong></label>"
                                  "</div>"
                                  "</body>"
                                  "</html>");
    QMessageBox::information(this,"Help",content);
}*/
