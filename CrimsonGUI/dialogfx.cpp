//--------------------------------------------------------------------------------------------------
//              DIALOGFX.CPP
//--------------------------------------------------------------------------------------------------

#include "dialogfx.h"
#include "ui_dialogfx.h"

#include <QString>

DialogFx::DialogFx(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFx)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    dial0->setNotchesVisible(true);
    dial1->setNotchesVisible(true);
    dial2->setNotchesVisible(true);
    dial3->setNotchesVisible(true);
    dial4->setNotchesVisible(true);
    dial5->setNotchesVisible(true);

    ui->setupUi(this);
}

DialogFx::~DialogFx()
{
    delete ui;
}

void DialogFx::dialogSettings(int fxNum, Effect fx)
{           
    // Aca hay que inicializar los botones de encendido y apagado de los
    // efectos y del preset en el que esten
    effect = fxNum;

    // Seteo el estado del boton on off
    updateFxState(fx.state);

    // Esta funcion debe crear dinamicamente
    // los widgets necesarios para cada efecto

    // pongo el nombre del efecto en el gui
    ui->lblFx->setText(fx.name);

    ui->vLayout->addLayout(row1); //rowOne a Star Wars Stwory
    ui->vLayout->addLayout(row2);
    ui->vLayout->addLayout(row3);
    ui->vLayout->addLayout(row4);

    if (fx.nParam >= 1)
    {
        lblDial0->setText(QString(fx.param[PARAM0].name));
        dial0->setValue(fx.param[PARAM0].value);
        row1->addWidget(dial0);
        row2->addWidget(lblDial0);
        connect(dial0,SIGNAL(valueChanged(int)),
                this,SLOT(slot_dial0_valueChanged(int)));
    }
    if (fx.nParam >= 2)
    {
        lblDial1->setText(QString(fx.param[PARAM1].name));
        dial1->setValue(fx.param[PARAM1].value);
        row1->addWidget(dial1);
        row2->addWidget(lblDial1);
        connect(dial1,SIGNAL(valueChanged(int)),
                this,SLOT(slot_dial1_valueChanged(int)));
    }
    if (fx.nParam >= 3)
    {

        lblDial2->setText(QString(fx.param[PARAM2].name));
        dial2->setValue(fx.param[PARAM2].value);
        row1->addWidget(dial2);
        row2->addWidget(lblDial2);
        connect(dial2,SIGNAL(valueChanged(int)),
                this,SLOT(slot_dial2_valueChanged(int)));
    }
    if (fx.nParam >= 4)
    {
        lblDial3->setText(QString(fx.param[PARAM3].name));
        dial3->setValue(fx.param[PARAM3].value);
        row3->addWidget(dial3);
        row4->addWidget(lblDial3);
        connect(dial3,SIGNAL(valueChanged(int)),
                this,SLOT(slot_dial3_valueChanged(int)));
    }
    if (fx.nParam >= 5)
    {
        lblDial4->setText(QString(fx.param[PARAM4].name));
        row3->addWidget(dial4);
        row4->addWidget(lblDial4);
        connect(dial4,SIGNAL(valueChanged(int)),
                this,SLOT(slot_dial4_valueChanged(int)));
    }
    if (fx.nParam >= 6)
    {
        lblDial5->setText(QString(fx.param[PARAM5].name));
        row3->addWidget(dial5);
        row4->addWidget(lblDial5);
        connect(dial5,SIGNAL(valueChanged(int)),
                this,SLOT(slot_dial5_valueChanged(int)));
    }

    this->show();
}

void DialogFx::updateFxState(bool state)
{
    // Actualizar la GUI con los estados de los efectos
    setPBtnStyle(ui->btnOnOff,state);
}

void DialogFx::setDialValues(Effect fx)
{
    if (fx.nParam >= 1)
    {
        dial0->setValue(fx.param[PARAM0].value);
    }
    if (fx.nParam >= 2)
    {
        dial1->setValue(fx.param[PARAM1].value);
    }
    if (fx.nParam >= 3)
    {
        dial2->setValue(fx.param[PARAM2].value);
    }
    if (fx.nParam >= 4)
    {
        dial3->setValue(fx.param[PARAM3].value);
    }
    if (fx.nParam >= 5)
    {
        dial4->setValue(fx.param[PARAM4].value);
    }
    if (fx.nParam >= 6)
    {
        dial5->setValue(fx.param[PARAM5].value);
    }
}

void DialogFx::slot_dial0_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM0,position);
}

void DialogFx::slot_dial1_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM1,position);
}

void DialogFx::slot_dial2_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM2,position);
}

void DialogFx::slot_dial3_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM3,position);
}

void DialogFx::slot_dial4_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM4,position);
}

void DialogFx::slot_dial5_valueChanged(int position)
{
    emit signal_fx_param_changed(effect,PARAM5,position);
}

void DialogFx::on_btnOnOff_released()
{
    emit signal_fx_state_changed(effect);
}

void DialogFx::on_btnClose_released()
{
    emit signal_destroyed();
    this->close();
}

void DialogFx::setPBtnStyle(QPushButton *button, bool checked)
{
    if(checked)
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #dc143c, stop: 1 #a60f2d)");
    else
        button->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 0.67, stop: 0 #4a4a4a, stop: 1 #3d3d3d)");
}
