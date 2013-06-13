#include "importweb.h"
#include "ui_importweb.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QVariant>
#include <QVariantMap>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QSettings>
#include <QObject>
#include <QQueue>
#include <QToolBox>
#include <QIcon>
#include <QResource>
#include <QDesktopServices>
#include <QUrl>

importWeb::importWeb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importWeb)
{
    ui->setupUi(this);
}

importWeb::~importWeb()
{
    delete ui;
}

void importWeb::on_buttonBox_accepted()
{
    close();
}

void importWeb::on_buttonBox_rejected()
{
    close();
}

void importWeb::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://myrtb.nih.gov"));
}
