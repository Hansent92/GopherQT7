#ifndef IMPORTWEB_H
#define IMPORTWEB_H

#include <QDialog>

namespace Ui {
class importWeb;
}

class importWeb : public QDialog
{
    Q_OBJECT
    
public:
    explicit importWeb(QWidget *parent = 0);
    ~importWeb();
    
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_2_clicked();

private:
    Ui::importWeb *ui;

};

#endif // IMPORTWEB_H
