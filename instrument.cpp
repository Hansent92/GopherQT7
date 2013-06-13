#include "gopher.h"
#include "ui_gopher.h"

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

void Gopher::FillInstrumentsImageMode()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, d, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, d, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, d, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, d, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, d, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, d, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, d, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, d, Qt::UserRole -1);
}


void Gopher::FillInstrumentsCameras()
{
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);

}

void Gopher::FillInstrumentsAquisitionSoftware()
{
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
}

void Gopher::FillH7500ImageModes()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(1);

//    ui->imageMode->insertItem(1,"TEM 2D");

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, e, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, d, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, d, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, d, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, d, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, d, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, d, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, d, Qt::UserRole -1);
}

void Gopher::FillH7500Camera()
{
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);

    ui->Camera->insertItem(1,"Hamamatsu Xr-100");
}

void Gopher::FillH7500AquisitionSoftware()
{
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);

    ui->AquisitionSoftware->insertItem(1,"AMT");
}

void Gopher::FillSU8000ImageMode()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(2);
//    ui->imageMode->removeItem(3);
//    ui->imageMode->removeItem(4);
//    ui->imageMode->removeItem(5);
//    ui->imageMode->removeItem(6);
//    ui->imageMode->removeItem(7);
//    ui->imageMode->removeItem(8);
//    ui->imageMode->removeItem(9);

//    ui->imageMode->insertItem(5,"Stem 2D");
//    ui->imageMode->insertItem(7,"SEM 2D");

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, d, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, d, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, d, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, d, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, e, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, e, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, d, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, d, Qt::UserRole -1);
}

void Gopher::FillSU8000Camera()
{
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
}

void Gopher::FillSU8000AquisitionSoftware()
{
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);

    ui->AquisitionSoftware->insertItem(1,"Hitachi SEM");
}

void Gopher::FillS5200ImageMode()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(2);
//    ui->imageMode->removeItem(3);
//    ui->imageMode->removeItem(4);
//    ui->imageMode->removeItem(5);
//    ui->imageMode->removeItem(6);
//    ui->imageMode->removeItem(7);
//    ui->imageMode->removeItem(8);
//    ui->imageMode->removeItem(9);

//    ui->imageMode->insertItem(7,"SEM 2D");
//    ui->imageMode->insertItem(8,"Cryo-SEM");

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, d, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, d, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, d, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, d, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, d, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, e, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, e, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, d, Qt::UserRole -1);
}

void Gopher::FillS5200Camera()
{
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
}

void Gopher::FillS5200AquisitionSoftware()
{
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);

    ui->AquisitionSoftware->insertItem(1, "Hitachi SEM");
}

void Gopher::FillTecnaiAMTImageMode()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(2);
//    ui->imageMode->removeItem(3);
//    ui->imageMode->removeItem(4);
//    ui->imageMode->removeItem(5);
//    ui->imageMode->removeItem(6);
//    ui->imageMode->removeItem(7);
//    ui->imageMode->removeItem(8);
//    ui->imageMode->removeItem(9);

//    ui->imageMode->insertItem(1,"TEM 2D");
//    ui->imageMode->insertItem(2,"TEM Tomo");
//    ui->imageMode->insertItem(3,"Cryo-TEM 2D");

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, e, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, e, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, e, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, d, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, d, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, d, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, d, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, d, Qt::UserRole -1);
}

void Gopher::FillTecnaiAMTCamera()
{
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);

    ui->Camera->insertItem(1,"Hamamatsu Xr-100");
    ui->Camera->insertItem(2,"UltraScan 1000 Gatan CCD");
}

void Gopher::FillTecnaiAMTAquisitionSoftware()
{
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);

    ui->AquisitionSoftware->insertItem(1,"AMT");
    ui->AquisitionSoftware->insertItem(2,"Digital Micrograph");
}

void Gopher::FillTecnaiTomoImageMode()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(2);
//    ui->imageMode->removeItem(3);
//    ui->imageMode->removeItem(4);
//    ui->imageMode->removeItem(5);
//    ui->imageMode->removeItem(6);
//    ui->imageMode->removeItem(7);
//    ui->imageMode->removeItem(8);
//    ui->imageMode->removeItem(9);

//    ui->imageMode->insertItem(2,"TEM Tomo");
//    ui->imageMode->insertItem(4,"Cryo-TEM Tomo");

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, d, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, e, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, d, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, e, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, d, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, d, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, d, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, d, Qt::UserRole -1);
}

void Gopher::FillTecnaiTomoCamera()
{
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);

    ui->Camera->insertItem(1,"UltraScan 1000 Gatan CCD");
}

void Gopher::FillTecnaiTomoAquisitionSoftware()
{
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);

    ui->AquisitionSoftware->insertItem(1,"Xplore3D");
}

void Gopher::FillKriosImageMode()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(2);
//    ui->imageMode->removeItem(3);
//    ui->imageMode->removeItem(4);
//    ui->imageMode->removeItem(5);
//    ui->imageMode->removeItem(6);
//    ui->imageMode->removeItem(7);
//    ui->imageMode->removeItem(8);
//    ui->imageMode->removeItem(9);

//    ui->imageMode->insertItem(1,"TEM 2D");
//    ui->imageMode->insertItem(2,"TEM Tomo");
//    ui->imageMode->insertItem(3,"Cryo-TEM 2D");
//    ui->imageMode->insertItem(4,"Cryo-TEM Tomo");
//    ui->imageMode->insertItem(5,"STEM 2D");
//    ui->imageMode->insertItem(6,"STEM Tomo");

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, d, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, d, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, d, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, d, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, d, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, e, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, e, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, e, Qt::UserRole -1);
}

void Gopher::FillKriosCamera()
{
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);
    ui->Camera->removeItem(1);

    ui->Camera->insertItem(1,"UltraScan 4000 Gatan CCD");
    ui->Camera->insertItem(2,"UltraScan GIF 2002");
}

void Gopher::FillKriosAquisitionSoftware()
{
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);
    ui->AquisitionSoftware->removeItem(1);

    ui->AquisitionSoftware->insertItem(1,"Digital Micrograph");
    ui->AquisitionSoftware->insertItem(2,"Xplore3D");
    ui->AquisitionSoftware->insertItem(3,"TIA");
    ui->AquisitionSoftware->insertItem(4,"EPU");
}

void Gopher::Fill510MetaImageMode()
{
//    ui->imageMode->removeItem(1);
//    ui->imageMode->removeItem(2);
//    ui->imageMode->removeItem(3);
//    ui->imageMode->removeItem(4);
//    ui->imageMode->removeItem(5);
//    ui->imageMode->removeItem(6);
//    ui->imageMode->removeItem(7);
//    ui->imageMode->removeItem(8);
//    ui->imageMode->removeItem(9);

//    ui->imageMode->insertItem(9,"Confocal");

    QVariant d(0); //disables
    QVariant e(1 | 32); //enables

    QModelIndex index1 = ui->imageMode->model()->index(1,0);//TEM 2D
    ui->imageMode->model()->setData(index1, d, Qt::UserRole -1);
    QModelIndex index2 = ui->imageMode->model()->index(2,0);//TEM Tomp
    ui->imageMode->model()->setData(index2, d, Qt::UserRole -1);
    QModelIndex index3 = ui->imageMode->model()->index(3,0);//Cryo-TEM 2D
    ui->imageMode->model()->setData(index3, d, Qt::UserRole -1);
    QModelIndex index4 = ui->imageMode->model()->index(4,0);//Cryo-TEM Tomo
    ui->imageMode->model()->setData(index4, d, Qt::UserRole -1);
    QModelIndex index5 = ui->imageMode->model()->index(5,0);//Stem 2D
    ui->imageMode->model()->setData(index5, d, Qt::UserRole -1);
    QModelIndex index6 = ui->imageMode->model()->index(6,0);//Stem Tomo
    ui->imageMode->model()->setData(index6, d, Qt::UserRole -1);
    QModelIndex index7 = ui->imageMode->model()->index(7,0);//SEM 2D
    ui->imageMode->model()->setData(index7, d, Qt::UserRole -1);
    QModelIndex index8 = ui->imageMode->model()->index(8,0);//Cryo-SEM
    ui->imageMode->model()->setData(index8, d, Qt::UserRole -1);
    QModelIndex index9 = ui->imageMode->model()->index(9,0);//Confocal
    ui->imageMode->model()->setData(index9, e, Qt::UserRole -1);
}

