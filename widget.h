#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_weight_pushButton_1_clicked();

    void on_weight_pushButton_2_clicked();   //质量

    void on_length_pushButton_1_clicked();

    void on_length_pushButton_2_clicked();   //长度

    void on_area_pushButton_1_clicked();

    void on_area_pushButton_2_clicked();     //面积

    void on_volume_pushButton_1_clicked();

    void on_volume_pushButton_2_clicked();   //体积

    void on_temperature_pushButton_1_clicked();

    void on_temperature_pushButton_2_clicked();//温度

    void on_money_pushButton_1_clicked();

    void on_money_pushButton_2_clicked();     //汇率

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
