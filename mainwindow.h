#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openSerialPort();

private:
    void parseLine(const QByteArray &data);


    Ui::MainWindow *ui;

    QSerialPort *serial;

    QLineEdit *ambient;
    QLineEdit *red;
    QLineEdit *green;
    QLineEdit *blue;
    QLineEdit *yaw;
    QLineEdit *pitch;
    QLineEdit *roll;
    QLineEdit *temperature;
    QLineEdit *laserFL;
    QLineEdit *laserFR;
    QLineEdit *laserL;
    QLineEdit *laserR;
    QLineEdit *laserB;
private slots:
    void readData();


};

#endif
