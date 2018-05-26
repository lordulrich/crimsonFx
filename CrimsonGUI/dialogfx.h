#ifndef DIALOGFX_H
#define DIALOGFX_H

#include <QDialog>
#include <QHBoxLayout>
#include <QDial>
#include <QLabel>

#include "fxbank.h"

namespace Ui {
class DialogFx;
}

class DialogFx : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFx(QWidget *parent = 0);
    ~DialogFx();

    void dialogSettings(int fx);

private slots:
    void slot_dial0_valueChanged(int position);
    void slot_dial1_valueChanged(int position);
    void slot_dial2_valueChanged(int position);
    void slot_dial3_valueChanged(int position);
    void slot_dial4_valueChanged(int position);

    void on_btnPreset1_released();
    void on_btnPreset2_released();
    void on_btnPreset3_released();

    void on_btnClose_released();

    void presetSelector(int preset);

signals:
    void signal_state_changed(int fx, int param, bool state);
    void signal_param_changed(int fx, int param, int value);
    void signal_preset_changed(int fx, int preset);

    void signal_fx_param_changed(int fx, int param,int position);

    void signal_destroyed();

private:
    Ui::DialogFx *ui;

    int effect;

    QDial *dial0 = new QDial;
    QDial *dial1 = new QDial;
    QDial *dial2 = new QDial;
    QDial *dial3 = new QDial;
    QDial *dial4 = new QDial;

    QLabel *lblDial0 = new QLabel;
    QLabel *lblDial1 = new QLabel;
    QLabel *lblDial2 = new QLabel;
    QLabel *lblDial3 = new QLabel;
    QLabel *lblDial4 = new QLabel;


    QHBoxLayout *row1 = new QHBoxLayout;
    QHBoxLayout *row2 = new QHBoxLayout;
    QHBoxLayout *row3 = new QHBoxLayout;
    QHBoxLayout *row4 = new QHBoxLayout;


};

#endif // DIALOGFX_H