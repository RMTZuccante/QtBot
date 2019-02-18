#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        serial(new QSerialPort(this)) {

    ui->setupUi(this);

    setWindowTitle(QCoreApplication::applicationName());

    ambient = ui->ambient;
    red = ui->red;
    green = ui->green;
    blue = ui->blue;
    yaw = ui->yaw;
    pitch = ui->pitch;
    roll = ui->roll;
    temperature = ui->temperature;
    laserFL = ui->laserFL;
    laserFR = ui->laserFR;
    laserL = ui->laserL;
    laserR = ui->laserR;
    laserB = ui->laserB;

    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    openSerialPort();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openSerialPort() {
    serial->setPortName("COM11");
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setDataBits(QSerialPort::Data8);
    serial->setFlowControl(QSerialPort::NoFlowControl );
    serial->setBaudRate(QSerialPort::Baud9600);

    serial->open(QIODevice::ReadOnly);
}

void MainWindow::readData() {
    if (serial->canReadLine()) parseLine(serial->readLine());
}

void MainWindow::parseLine(const QByteArray &data) {
    QStringList list = QString(data).simplified().split(QRegExp("\\t?\\D+:\\s"));
    list.removeAt(0);

    ambient->setText(list[0]);
    red->setText(list[1]);
    green->setText(list[2]);
    blue->setText(list[3]);
    yaw->setText(list[4]);
    pitch->setText(list[5]);
    roll->setText(list[6]);
    temperature->setText(list[7]);
    laserB->setText(list[8]);
    laserFL->setText(list[9]);
    laserL->setText(list[10]);
    laserR->setText(list[11]);
    laserFR->setText(list[12]);

}


