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

void Gopher::ImportInfo()
{
    QJsonObject info = QJsonValue(list.value("Info")).toObject();

    QString takenVal = QJsonValue(info.value("Data Taken By")).toString();
    ui->DataTakenBy->setCurrentText(takenVal);

    QString projectVal = QJsonValue(info.value("Project ID")).toString();
    ui->ProjectID->setText(projectVal);

    QString SubVal = QJsonValue(info.value("Subset ID")).toString();
    ui->SubsetID->setText(SubVal);

    QString instrumentVal = QJsonValue(info.value("Instrument")).toString();
    ui->Instrument->setCurrentText(instrumentVal);

    QString imageVal = QJsonValue(info.value("Image Mode")).toString();
    ui->imageMode->setCurrentText(imageVal);

    QString desVal = QJsonValue(info.value("Descriptive Title")).toString();
    ui->DescriptiveTitleText->setText(desVal);

    QString specVal = QJsonValue(info.value("Specimen/Organism")).toString();
    ui->Specimen_Organism->setCurrentText(specVal);

    QString samVal = QJsonValue(info.value("Sample prep")).toString();
    ui->SamplePrepText->setText(samVal);

    QString notesVal = QJsonValue(info.value("Notes")).toString();
    ui->NotesText->setText(notesVal);
}

void Gopher::ImportTEM2D()
{
    QJsonObject tem2D = QJsonValue(list.value("TEM 2D")).toObject();

    QString csval = QJsonValue(tem2D.value("Cs Value")).toString();
    ui->CsValue_Text_TEM2D_2->setText(csval);

    QString voltageVal = QJsonValue(tem2D.value("Voltage")).toString();
    ui->Voltage_Text_TEM2D_2->setText(voltageVal);

    QString efssVal = QJsonValue(tem2D.value("Energy Filter Slit Size")).toString();
    ui->EnergyFilterSlitSize_Text_TEM2D_2->setText(efssVal);
}

void Gopher::ImportTEMTomo()
{
    QJsonObject temTomo = QJsonValue(list.value("TEM Tomo")).toObject();

    QString astVal = QJsonValue(temTomo.value("Actual Specimen Thickness")).toString();
    ui->MaxSpecimenThickness_Text_TEMTomo_2->setText(astVal);

    QString mfsVal = QJsonValue(temTomo.value("Max Fiducial Size")).toString();
    ui->MaxFiducialSize_Text_TEMTomo_2->setText(mfsVal);

    QString efssVal = QJsonValue(temTomo.value("Energy Filter Slit Size")).toString();
    ui->EnergyFilterSlitSize_Text_TEMTomo_2->setText(efssVal);

    QString voltageVal = QJsonValue(temTomo.value("Voltage")).toString();
    ui->Voltage_Text_TEMTomo_2->setText(voltageVal);

    QString csval = QJsonValue(temTomo.value("Cs Value")).toString();
    ui->CsValue_Text_TEMTomo_2->setText(csval);
}

void Gopher::ImportCryoTEM()
{
    QJsonObject cryoTEM2D = QJsonValue(list.value("Cryo-TEM 2D")).toObject();

    QString doseVal = QJsonValue(cryoTEM2D.value("Dose")).toString();
    ui->Dose_CryoTEM2D_2->setText(doseVal);

    QString efssVal = QJsonValue(cryoTEM2D.value("Energy Filter Slit Size")).toString();
    ui->EnergyFilterSlitSize_CryoTEM2D_3->setText(efssVal);

    QString voltageVal = QJsonValue(cryoTEM2D.value("Voltage")).toString();
    ui->Voltage_Text_CryoTEM2D_2->setText(voltageVal);

    QString csval = QJsonValue(cryoTEM2D.value("Cs Value")).toString();
    ui->CsValue_Text_CryoTEM2D_2->setText(csval);
}

void Gopher::ImportCryoTEMVitrobotSettings()
{
    QJsonObject vit = QJsonValue(list.value("Vitrobot Settings")).toObject();

    QString forceVal = QJsonValue(vit.value("Blot Force")).toString();
    ui->BlotForceText_VitrobotSettings_2->setText(forceVal);

    QString timeVal = QJsonValue(vit.value("Blot Time")).toString();
    ui->BlotText_VitrobotSettings_2->setText(timeVal);

    QString humVal = QJsonValue(vit.value("Humidity Set")).toString();
    ui->HumiditySetText_VitrobotSettings_2->setText(humVal);

    QString acthumVal = QJsonValue(vit.value("Actual Humidity")).toString();
    ui->ActualText_VitrobotSettings_2->setText(acthumVal);

    QString waitVal = QJsonValue(vit.value("Wait Time")).toString();
    ui->WaitText_VitrobotSettings_2->setText(waitVal);

    QString drainVal = QJsonValue(vit.value("Drain Time")).toString();
    ui->DrainText_VitrobotSettings_2->setText(drainVal);
}

void Gopher::ImportCryoTEMTomo()
{
    QJsonObject cryoTEMTomo = QJsonValue(list.value("Cryo-TEM Tomo")).toObject();

    QString mstVal = QJsonValue(cryoTEMTomo.value("Max Specimen Thickness")).toString();
    ui->MaxSpecimenThickness_Text_CryoTomo_2->setText(mstVal);

    QString mfsVal = QJsonValue(cryoTEMTomo.value("Max Fiducial Size")).toString();
    ui->MaxFidecialSize_Text_CryoTomo_2->setText(mfsVal);

    QString doseVal = QJsonValue(cryoTEMTomo.value("Dose")).toString();
    ui->Dose_Text_CryoTomo_2->setText(doseVal);

    QString efssVal = QJsonValue(cryoTEMTomo.value("Energy Filter Slit Size")).toString();
    ui->EnergyFilterSlitSize_Text_CryoTomo_2->setText(efssVal);

    QString voltageVal = QJsonValue(cryoTEMTomo.value("Voltage")).toString();
    ui->Voltage_Text_CryoTomo_2->setText(voltageVal);

    QString csval = QJsonValue(cryoTEMTomo.value("Cs Value")).toString();
    ui->CsValue_Text_CryoTomo_2->setText(csval);
}

void Gopher::ImportCryoTEMTomoVitrobotSettings()
{
    QJsonObject vit = QJsonValue(list.value("Vitrobot Settings")).toObject();

    QString forceVal = QJsonValue(vit.value("Blot Force")).toString();
    ui->BlotForceText_VitrobotSettings_3->setText(forceVal);

    QString timeVal = QJsonValue(vit.value("Blot Time")).toString();
    ui->BlotText_VitrobotSettings_3->setText(timeVal);

    QString humVal = QJsonValue(vit.value("Humidity Set")).toString();
    ui->HumiditySetText_VitrobotSettings_3->setText(humVal);

    QString acthumVal = QJsonValue(vit.value("Actual Humidity")).toString();
    ui->ActualText_VitrobotSettings_3->setText(acthumVal);

    QString waitVal = QJsonValue(vit.value("Wait Time")).toString();
    ui->WaitText_VitrobotSettings_3->setText(waitVal);

    QString drainVal = QJsonValue(vit.value("Drain Time")).toString();
    ui->DrainText_VitrobotSettings_3->setText(drainVal);
}

void Gopher::ImportStem2D()
{
    QJsonObject stem2D = QJsonValue(list.value("Stem 2D")).toObject();

    QString spotVal = QJsonValue(stem2D.value("Spot Size")).toString();
    ui->SpotSizeText_STEM2D_2->setText(spotVal);

    QString dwellVal = QJsonValue(stem2D.value("Dwell Time")).toString();
    ui->DwellTimeText_STEM2D_2->setText(dwellVal);

    QString currentVal = QJsonValue(stem2D.value("Current(I)")).toString();
    ui->I_Text_STEM2D_2->setText(currentVal);

    QString conVal = QJsonValue(stem2D.value("Convergence Angle")).toString();
    ui->ConvergenceAngle_Text_STEM2D_2->setText(conVal);

    bool probeMicroVal = QJsonValue(stem2D.value("Probe Mode Microprobe")).Bool;
    ui->Microprobe_STEM2D_2->setChecked(probeMicroVal);

    bool probeNanoVal = QJsonValue(stem2D.value("Probe Mode Nanoprobe")).Bool;
    ui->NanoProbe_STEM2D_2->setChecked(probeNanoVal);

    QString camLenVal = QJsonValue(stem2D.value("Camera Length")).toString();
    ui->CameraLengthText_STEM2D_2->setText(camLenVal);

    QString nomMagVal = QJsonValue(stem2D.value("Nominal Magnification")).toString();
    ui->NominalMagnification_Text_STEM2D_2->setText(nomMagVal);
}

void Gopher::ImportStemTomo()
{
    QJsonObject stemTomo = QJsonValue(list.value("Stem Tomo")).toObject();

    QString mstVal = QJsonValue(stemTomo.value("Max Section Thickness")).toString();
    ui->MaxSectionThickness_Text_STEMTomo_2->setText(mstVal);

    QString mfsVal = QJsonValue(stemTomo.value("Max Fiducial Size")).toString();
    ui->MaxFiducialSize_Text_STEMTomo_2->setText(mfsVal);

    QString spotVal = QJsonValue(stemTomo.value("Spot Size")).toString();
    ui->SpotSize_Text_STEMTomo_2->setText(spotVal);

    QString dwellVal = QJsonValue(stemTomo.value("Dwell Time")).toString();
    ui->DwellTime_Text_STEMTomo_2->setText(dwellVal);

    QString currentVal = QJsonValue(stemTomo.value("Current(I)")).toString();
    ui->I_Text_STEMTomo_2->setText(currentVal);

    QString conVal = QJsonValue(stemTomo.value("Convergence Angle")).toString();
    ui->ConvergenceAngle_Text_STEMTomo_2->setText(conVal);

    bool probeMicroVal = QJsonValue(stemTomo.value("Probe Mode Microprobe")).Bool;
    ui->Microprobe_STEMTomo_2->setChecked(probeMicroVal);

    bool probeNanoVal = QJsonValue(stemTomo.value("Probe Mode Nanoprobe")).Bool;
    ui->NanoProbe_STEMTomo_2->setChecked(probeNanoVal);

    QString decVal = QJsonValue(stemTomo.value("Detector")).toString();
    ui->Detector_DropBox_STEMTomo_2->setCurrentText(decVal);

    QString camLenVal = QJsonValue(stemTomo.value("Camera Length")).toString();
    ui->CameraLength_Text_STEMTomo_2->setText(camLenVal);
}

void Gopher::ImportSEM()
{
    QJsonObject sem2D = QJsonValue(list.value("SEM 2D")).toObject();

    QString coatVal = QJsonValue(sem2D.value("Coating")).toString();
    ui->Coating_DropBox_SEM_2->setCurrentText(coatVal);

    QString coatThickVal = QJsonValue(sem2D.value("Coating Thickness")).toString();
    ui->CoatingThickness_Text_SEM_2->setText(coatThickVal);

}

void Gopher::ImportCryoSEM()
{
    QJsonObject cryoSEM = QJsonValue(list.value("Cryo-SEM")).toObject();

    QString priCoatVal = QJsonValue(cryoSEM.value("Primary Coating")).toString();
    ui->PrimaryCoating_DropBox_CryoSEM_2->setCurrentText(priCoatVal);

    QString priCoatAngVal = QJsonValue(cryoSEM.value("Primary Coating Angle")).toString();
    ui->primaryCoatingAngle_Text->setText(priCoatAngVal);

    bool rotVal = QJsonValue(cryoSEM.value("Rotation")).Bool;
    ui->primaryCoatingAngle_Rotation->setChecked(rotVal);

    QString priCoatThickVal = QJsonValue(cryoSEM.value("Primary Coating Thickness")).toString();
    ui->PrimaryCoatingThickness_Text_CryoSEM_2->setText(priCoatThickVal);

    QString secCoatVal = QJsonValue(cryoSEM.value("Secondary Coating Angle")).toString();
    ui->SecondaryCoating_DropBox_CryoSEM_2->setCurrentText(secCoatVal);

    QString secCoatAngVal = QJsonValue(cryoSEM.value("Secondary Coating Angle")).toString();
    ui->secondaryCoatingAngle_Text->setText(secCoatAngVal);

    bool secRotVal = QJsonValue(cryoSEM.value("Rotation")).Bool;
    ui->secondaryCoatingAngle_Rotation->setChecked(secRotVal);

    QString secCoatThickVal = QJsonValue(cryoSEM.value("Secondary Coating Thickness")).toString();
    ui->SecondaryCoatingThickness_Text_CryoSEM_2->setText(secCoatThickVal);

    QString priSubTimeVal = QJsonValue(cryoSEM.value("Primary Sublimation Time")).toString();
    ui->PrimarySublimationTime_Text_CryoSEM_2->setText(priSubTimeVal);

    QString priSubTempVal = QJsonValue(cryoSEM.value("Primary Sublimation Temp")).toString();
    ui->PrimarySublimationTemp_Text_CryoSEM_2->setText(priSubTempVal);

    QString secSubTimeVal = QJsonValue(cryoSEM.value("Secondary Sublimation Time")).toString();
    ui->SecondarySublimationTime_Text_CryoSEM_2->setText(secSubTimeVal);

    QString secSubTempVal = QJsonValue(cryoSEM.value("Secondary Sublimation Temp")).toString();
    ui->SecondarySublimationTemp_Text_CryoSEM_2->setText(secSubTempVal);

    QString viewTempVal = QJsonValue(cryoSEM.value("Viewing Temp")).toString();
    ui->ViewingTemp_Text_CryoSEM_2->setText(viewTempVal);
}

void Gopher::ImportCryoSEMVitrobotSettings()
{
    QJsonObject vit = QJsonValue(list.value("Vitrobot Settings")).toObject();

    QString forceVal = QJsonValue(vit.value("Blot Force")).toString();
    ui->BlotForceText_VitrobotSettings_4->setText(forceVal);

    QString timeVal = QJsonValue(vit.value("Blot Time")).toString();
    ui->BlotText_VitrobotSettings_4->setText(timeVal);

    QString humVal = QJsonValue(vit.value("Humidity Set")).toString();
    ui->HumiditySetText_VitrobotSettings_4->setText(humVal);

    QString acthumVal = QJsonValue(vit.value("Actual Humidity")).toString();
    ui->ActualText_VitrobotSettings_4->setText(acthumVal);

    QString waitVal = QJsonValue(vit.value("Wait Time")).toString();
    ui->WaitText_VitrobotSettings_4->setText(waitVal);

    QString drainVal = QJsonValue(vit.value("Drain Time")).toString();
    ui->DrainText_VitrobotSettings_4->setText(drainVal);
}

void Gopher::ImportConfocal()
{
    QJsonObject confocal = QJsonValue(list.value("Confocal")).toObject();
}

